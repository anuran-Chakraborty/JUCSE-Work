//Using semaphore
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<pthread.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/types.h>
#define mx "X"
#define my "Y"

void processCreate();
void iterate(int,int);

sem_t *mutexX;
sem_t *mutexY;

int main()
{	
	//Initialize the semaphore
	sem_unlink(mx);
	sem_unlink(my);

	mutexX = sem_open(mx, O_CREAT | O_EXCL ,0777, 1);

	if (mutexX == SEM_FAILED) {
     perror("Failed to open semphore for empty");
     exit(-1);
	}

	mutexY = sem_open(my, O_CREAT | O_EXCL ,0777, 0);

	if (mutexY == SEM_FAILED) {
     perror("Failed to open semphore for empty");
     exit(-1);
	}

	processCreate();
	return 0;
}

void iterate(int time,int flag)
{
	int i;
	pid_t procid=getpid();



	for(i=1;i<=10;i++)
	{
		
		if(flag==0) //If process is X
		{
			sem_wait(mutexX);
		}
		else //If process is Y
		{
			sem_wait(mutexY);
		}

		//Print process id and iteration number
		printf("Process Name: %c ProcessId: %d Iteration: %d\n",(char)(flag+'X'),procid,i);
		sleep(time);
		
		if(flag==0) //If process is X
		{
			sem_post(mutexY);
		}
		else //If process is Y
		{
			sem_post(mutexX);
		}

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
		iterate(1,0);
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
			iterate(2,1);
		}
		else
		{
			wait(NULL);
		}
		wait(NULL);
		return;
	}
}