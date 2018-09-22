#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h> 
#include <sys/msg.h>


//Define structure of message queue
struct mess
{
	long mess_type;
	char mess_text[500];
} message;


//Broadcaster 
int main()
{
	key_t key;
	int msgid;

	// while(1)
	// {
		//Generate unique key
	key = ftok("./progfile",65);

		//msgget() creates message queue and return id
	if(msgid=msgget(key,0777 | IPC_CREAT)==-1)
	{
		perror("IPC error");
	}
	else
	{
		message.mess_type=1;

		printf("Enter weather report: \n");
		fgets(message.mess_text,500,stdin);

		//Send the message
		if(msgsnd(msgid,&message,sizeof(message)+1,0)<0)
			perror("Sending failed");
		else
			printf("Data sent is : %s \n", message.mess_text);
	}
	// }

	return 0;
} 