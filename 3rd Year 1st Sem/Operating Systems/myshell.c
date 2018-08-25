#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<pwd.h>
#include<time.h>
#include<fcntl.h>

#define TOK_BUFFSIZE 64
#define TOK_DELIM " \t\r\n"
#define clear() printf("\033[H\033[J")
#define EXIT_CODE -9999
#define PATH_MAX 1000

void sh_loop(); //Function which starts the shell loop
char* sh_read_line(); //Function to read line
char** sh_parse(char*); //Function to parse the line
int sh_launch(char**); //Function to start a program
int sh_execute(); //Function to execute a command

/** Functions which define the basic shell functions **/

int newdir(char** args); //Function to create a new directory
int editfile(char** args); //Function to edit a file
int content(char** args); //Function to print contents of a file
int info(char** args); //Function to display info about a file
int exitjubcse(); //Function to exit the shell

/** ================================================= **/

//List of builtin functions
char* builtin_comm[] = {"newdir","editfile","content","info","exit"};

// Store pointer to respective functions
int (*builtin_func[]) (char**) = {&newdir,&editfile,&content,&info,&exitjubcse};


int main(int argc, char const *argv[])
{
	clear();
	//Display welcome message
	printf("================ Welcome to JUBCSEIII ===============\n");
	printf("Hi! Good ");

	time_t currTime=time(NULL);
	struct tm *cuTime=localtime(&currTime);
	int hour=cuTime->tm_hour;

	if(hour>=4 && hour<12)
		printf("Morning\n");
	else
	if(hour>=12 && hour<=17)
		printf("Afternoon\n");
	else
	if(hour>17 && hour<=23)
		printf("Evening\n");
	else
		printf("Night\n");
	printf("======================================================\n");
	// Call the shell loop
	sh_loop();

	return 0;
}

//Start the shell loop
void sh_loop()
{
	char* line;
	char** args;
	int status;
	 //Get username
	char* username=getenv("USER");

	 //Get current working directory
	char currdir[1024];
	getcwd(currdir, sizeof(currdir));

	 //Infinite shell loop
	do
	{
	 	//Print prompt
		printf("%s:%s $ ",username,currdir);

	 	//Now read the line
		line = sh_read_line();
	 	//Parse the line
		args = sh_parse(line);

		status=sh_execute(args);
		free(line);
		free(args);
	}
	while(status!=EXIT_CODE);
}

//Function to read the line
char* sh_read_line()
{
	char* line=NULL;
	ssize_t buffer=0;
	//Use getline
	getline(&line,&buffer,stdin);
	return line;
}

//Parse the line
char** sh_parse(char* line)
{
	int bufsize=TOK_BUFFSIZE;
	int position=0;

	char** tokens=malloc(bufsize* sizeof(char*)); //Array to store all the tokens
	char* token; //Each token

	//Check for memory allocation error
	if(!tokens)
	{
		printf("jubcseIII: allocation error");
		exit(1);
	}

	//Tokenize the line
	token=strtok(line, TOK_DELIM);

	while(token)
	{
		tokens[position++]=token; // Assign each token to an element in the array of tokens

		//Handle buffer overflow case
		if(position>=bufsize)
		{
			bufsize+=TOK_BUFFSIZE;
			tokens=realloc(tokens,bufsize*sizeof(char*)); //Reallocate memory with extended buffer

			//Check for memory allocation error
			if(!tokens)
			{
				printf("jubcseIII: allocation error");
				exit(1);
			}
		}

		token = strtok(NULL,TOK_DELIM);
	}
	tokens[position]=NULL;
	return tokens;
}

//Function to start a builtin process
int sh_launch(char** args)
{
	//Create a child process and call functions
	pid_t pid=fork();
	int background=0;
	if(args[2]!=NULL && strcmp(args[2],"&")==0)
	{
		background=1;
		args[2]=NULL;
	}
	
	
	if(background!=1 && args[1]!=NULL && strcmp(args[1],"&")==0)
	{
		background=1;
		args[1]=NULL; 
	}

	if(pid==-1)
	{
		//In case of failure to fork a chaild
		printf("forking child failed\n");
		return 0;
	}
	else
	if(pid==0 && background==1)
	{
		//If it is the child process and is background
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
	    int x = open("/dev/null", O_RDWR);   // Redirect input, output and stderr to /dev/null
	    dup(x);
		
		if(execvp(args[0],args)==-1)//For invalid command
		{
			printf("jubcseIII: no such file or command\n");
			return 0;
		}
		kill(getpid(),SIGINT);
	}
	else
	if(pid==0 && background!=1)
	{
		//If it is the child process
		//execute command
		if(execvp(args[0],args)==-1)//For invalid command
		{
			printf("jubcseIII: no such file or command\n");
			return 0;
		}
	}
	else
	if(background!=1)
	{
		//For parent process wait for child to terminate
		wait(NULL);
		return 0;
	}
	return 1;
}

//Function to start a custom process will take the fucntion pointer
int sh_launch_custom(char** args,int (*func)(char**))
{
	//Create a child process and call functions
	pid_t pid=fork();
	int background=(args[2]!=NULL && strcmp(args[2],"&")==0)?1:0; //Sets the background flag
	background=(background!=1 && args[1]!=NULL && strcmp(args[1],"&")==0)?1:0;

	if(pid==-1)
	{
		//In case of failure to fork a chaild
		printf("forking child failed\n");
		return 0;
	}
	else
	if(pid==0 && background==1)
	{
		//execute command
		if((*func)(args)==0)//For invalid command
		{
			printf("jubcseIII: error executing command\n");
			return 0;
		}
	}
	else
	if(pid==0 && background!=1)
	{
		//If it is the child process
		//execute command
		if(func(args)==0)//For invalid command
		{
			printf("jubcseIII: error executing command\n");
			return 0;
		}
	}
	else
	if(background!=1)
	{
		//For parent process wait for child to terminate
		wait(NULL);
		return 0;
	}
	return 1;
}




//Function to execute
int sh_execute(char** args)
{
	int i;
	if(args[0]==NULL) // no command entered
		return 1;
	else
	{
		//Comapare if the command is equal to any of the nuiltin commands
		for(int i=0;i<5;i++)
		{
			if(strcmp(args[0],builtin_comm[i])==0)
			{
				if(i==1)
					return editfile(args);
				if(i==4)
				{
					kill(0,SIGTERM);
					exit(0);
				}
				return sh_launch_custom(args,builtin_func[i]);
			}
		}
	}
	return sh_launch(args);
}

//Function to make a new directory
int newdir(char** args)
{
	if(args[1]==NULL) //If no arguments are given
	{
		printf("jubcseIII: newdir requires exactly one argument\n");
		return 0;
	}
	else
	{
		if(mkdir(args[1],0700)!=0)
		{
			printf("%s directory already exists\n",args[1]);
			return 0;
		}
	}
	printf("directory %s was created\n",args[1]);
	return 1;
}

//Function to edit a file
int editfile(char** args)
{
	args[0]="vim";
	//As a new process will run we have to fork it so call launch
	return sh_launch(args);
}

//Function to print contents of a file
int content(char** args)
{
	if(args[1]==NULL) //If no arguments are given
	{
		printf("jubcseIII: content requires exactly one argument\n");
		return 0;
	}
	else
	{
		//Read file and display it

		FILE *fptr;
		char* filename,c;
		filename=args[1];
    	// Open file
		fptr = fopen(filename, "r");
		if (fptr == NULL)
		{
			printf("jubcseII: no such file \n");
			return 0;
		}

    	// Read contents from file
		c = fgetc(fptr);
		while (c != EOF)
		{
			printf ("%c", c);
			c = fgetc(fptr);
		}

		fclose(fptr);
		printf("\n");
	}
	return 1;
}

//Function to print info about a file
int info(char** args)
{
	if(args[1]==NULL) //If no arguments are given
	{
		printf("jubcseIII: info requires exactly one argument\n");
		return 0;
	}
	else
	{

		//If file does not exist
		FILE *file;
	    if (!(file = fopen(args[1], "r")))
	    {
	    	printf("info:file does not exist\n");
	        return 0;
	    }
	    fclose(file);

		//Get the required info about the file
		//Get path of file
		char actualpath [PATH_MAX+1];
		char *ptr;
		ptr = realpath(args[1], actualpath);

		//Get size of file
		struct stat st;
		stat(args[1], &st);
		int size = st.st_size;

		//Get last modified of a file
		char date[10];
	    strftime(date, 20, "%d-%m-%y", localtime(&(st.st_mtime)));

		//Get owner of file
		uid_t owner=st.st_uid;
		struct passwd *pwd;
		pwd = getpwuid(owner);

		printf("Absolute path: %s\n",ptr);
		printf("Size of file: %d bytes\n",size);
		printf("Last Modified: %s\n",date);
		printf("Owner: %s\n", pwd->pw_name);

		date[0]=0;

	}
	return 1;
}

//Function to exit shell
int exitjubcse()
{
	return EXIT_CODE;
}