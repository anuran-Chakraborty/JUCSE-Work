#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <dirent.h>
#include <semaphore.h>
#include <sys/sem.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int readcount=0;
pthread_t tid;

sem_t *rlock,*wlock,*rwlock,*resource,*rclock;

int w_flag=0;

void initialize(int r)
{
	sem_unlink("sem1");
	sem_unlink("sem2");
	sem_unlink("sem3");
	sem_unlink("sem4");
	sem_unlink("sem5");

  if ((rlock = sem_open("sem1", O_CREAT, 0644, r)) == SEM_FAILED) //(initial value = 3)
  {
  	perror("semaphore rlock initilization");
  	exit(1);
  }
  if ((wlock = sem_open("sem2", O_CREAT, 0644, 1)) == SEM_FAILED) //(initial value = 1)
  {
  	perror("semaphore wlock initilization");
  	exit(1);
  }
  if ((rwlock = sem_open("sem3", O_CREAT, 0644, 1)) == SEM_FAILED) //(initial value = 1)
  {
  	perror("semaphore rwlock initilization");
  	exit(1);
  }
  if ((resource = sem_open("sem4", O_CREAT, 0644, 1)) == SEM_FAILED) //(initial value = 1)
  {
  	perror("semaphore resource initilization");
  	exit(1);
  }
  if ((rclock = sem_open("sem5", O_CREAT, 0644, 1)) == SEM_FAILED) //(initial value = 1)
  {
  	perror("semaphore rclock initilization");
  	exit(1);
  }

}

//READER
void reader()
{
	// printf("r\n");
	//ENTRY Section
	if(w_flag==0)
	{
		// printf("Reader wflag: %d\n",w_flag);
		sem_wait(rlock);
		sem_wait(rclock);
		readcount++;
		// printf("Readcount: %d\n",readcount);
		// if(readcount==1)
		sem_wait(wlock);
		sem_post(rclock);

		//CRITICAL Section
		printf("\n********* READING **************\n");
		printf("reading started by %d\n",getpid());
		//reading is performed
		printf("Reading.....\n");
		sleep(1);
		printf("reading completed by %d\n",getpid());
		printf("********* READING ENDS *********\n");

		//EXIT Section
		sem_wait(rclock);
		readcount--;
		sem_post(rclock);
		// if(w_flag)
		// {
		sem_post(wlock);
			// sem_wait(rwlock);
		// }
		sem_post(rlock);
	}

}

//WRITER
void writer() 
{
	sleep(1);
	// printf("w\n");
	//ENTRY Section
	sem_wait(rwlock);
	w_flag++;
	printf("Writer %d wflag: %d\n",getpid(),w_flag);
	sem_post(rwlock);
	// sleep(5);
	sem_wait(wlock);

	//CRITICAL Section
	sem_wait(resource);
	printf("\n********* WRITING **************\n");                //reserve the resource for yourself - prevents other writers from simultaneously editing the shared resource
	printf("writing started by %d\n",getpid());
	//writing is performed
	printf("Writing.....\n");
	sleep(2);
	printf("writing completed by %d\n",getpid());
	printf("********* WRITING ENDS *********\n"); 
	sem_post(resource);                //release file

	//EXIT Section
	sem_wait(rwlock);
	w_flag--;
	sem_post(rwlock);
	// if(!w_flag)
	// {
	// 	sem_post(rwlock);
	// }
	sem_post(wlock);

}

void read_write(int r,int w)
{
	initialize(1);
	pid_t wpid;

	int i,status=0;

	if(getpid()>0)
	{
		for(i=0;i<r+w;i++)
		{
			pid_t readerp=fork();
			if(readerp<0)
			{
				printf("fork error\n");
				exit(1);
			}
			if(readerp==0 && i<r)
			{
				// printf("%dreader%d\n",i,getpid());
				reader();
				exit(0);
			}
			else if(readerp==0 && i>=r)
			{
				// printf("%dwriter%d\n",i,getpid());
				writer();
				exit(0);
			}
			if(i>=r)
				sleep(3);
		}
	}
	while ((wpid = wait(&status)) > 0);

	// for(i=0;i<r+w;i++) // loop will run n times (n=5) 
 //    { 
 //        if(fork() == 0) 
 //        {
 //            pid_t readerp=fork();
	// 		if(readerp<0)
	// 		{
	// 			printf("fork error\n");
	// 			exit(1);
	// 		}
	// 		if(readerp==0 && i<r)
	// 		{
	// 			printf("%dreader%d\n",i,getpid());
	// 			reader();
	// 		}
	// 		else if(readerp==0 && i>=r)
	// 		{
	// 			printf("%dwriter%d\n",i%5,getpid());
	// 			writer();
	// 		}
 //        } 
 //    }

 //    for(i=0;i<r+w;i++) // loop will run n times (n=5) 
 //        wait(NULL);
}

int main()
{
	int r,w,i;    
	printf("\nEnter the no of readers: ");
	scanf("%d",&r);
	printf("\nEnter the no of writers: ");
	scanf("%d",&w);
	read_write(r,w);

	return 0;
}