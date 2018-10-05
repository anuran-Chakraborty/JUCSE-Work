#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

int main()
{
	int fd[5];

	sem_t* sem;
	sem=sem_open("sem",O_CREAT | O_EXCL, 0777,1);

    // FIFO file path
	char * myfifo[5];
	int i;
	for(i=0;i<5;i++)
	{
		char s[] = "myfifo";
		char num[2];
		num[0]='0'+i;num[1]='\0';
		strcat(s,num);
		myfifo[i]=s;
        // Creating the named file(FIFO)
        // mkfifo(<pathname>,<permission>)
		mkfifo(myfifo[i], 0666);
	}

	pid_t PID_PARENT=getpid();

    for(i=0;i<5;i++) // loop will run n times (n=5)
    {
    	pid_t pid;
    	if(getpid()==PID_PARENT)
    	{
    		pid=fork();
    		if(pid>0)
    		{
    			printf("%d\n", getpid());
    		}
    		printf("forked\n"	 );
    		if(pid <0)
    		{
    			printf("fork error\n");
    		}
    		else if(pid == 0)
    		{
    			while (1)
    			{
    				sem_wait(sem);
    				char str1[80], str2[80];
			        // First open in read only and read
    				fd[i] = open(myfifo[i],O_RDONLY);
    				read(fd[i], str1, 80);

			        // Print the read string and close

    				printf("User%d: %s\n",getpid(), str1);

    				close(fd[i]);

    				sem_post(sem);

			        // Now open in write mode and write
			        // string taken from user.
			        // fd1 = open(myfifo,O_WRONLY);
			        // fgets(str2, 80, stdin);
			        // write(fd1, str2, strlen(str2)+1);
			        // close(fd1);
    			}
    		}
    	}
    }
		for(i=0;i<5;i++) // loop will run n times (n=5)
			wait(NULL);
		return 0;
	}
