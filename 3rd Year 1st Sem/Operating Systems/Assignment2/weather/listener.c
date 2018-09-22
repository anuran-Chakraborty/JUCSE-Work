#include <stdio.h>
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
		//receive the message
			msgrcv(msgid,&message,sizeof(message),1,0);

			printf("Current weather report: %s",message.mess_text);
		}
		// Destroy message queue
		msgctl(msgid,IPC_RMID,NULL);
	// }


	return 0;
}