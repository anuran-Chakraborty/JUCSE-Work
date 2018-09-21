#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void processCreate();
void iterate(int);

int main()
{
	processCreate();
	return 0;
}

void iterate(int time)
{
	int i;
	pid_t procid=getpid();
	for(i=1;i<=10;i++)
	{
		//Print process id and iteration number
		printf("ProcessId: %d Iteration: %d\n",procid,i);
		sleep(time);
	}
}

void processCreate()
{
	pid_t pid=fork();

	if(pid==-1)
		printf("Fork failure\n");
	else
	if(pid==0)
	{
		//Child process X
		printf("Child X created\n");
		iterate(1);
	}
	else
	{
		pid_t pid2=fork();

		if(pid2==-1)
		printf("Fork failure\n");
		else
		if(pid2==0)
		{
			//Child process Y
			printf("Child Y created\n");
			iterate(2);
		}
		else
		{
			wait(NULL);
		}
		wait(NULL);
		return;
	}
}