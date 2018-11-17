#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <dirent.h>
#include <semaphore.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>

static int* readcount;
static int* writecount;
pthread_t tid;

sem_t *noReaders,*noWriters,*writerSwitch,*resource,*readerSwitch;


void initialize()
{
	sem_unlink("sem1");
	sem_unlink("sem2");
	sem_unlink("sem3");
	sem_unlink("sem4");
	sem_unlink("sem5");

	// shm_unlink("shm1");

	// int shared_mem=shm_open ("shm1", O_CREAT|O_RDWR, 0);
	readcount = mmap(NULL, sizeof *readcount, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	*readcount=0;

	writecount = mmap(NULL, sizeof *writecount, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	*writecount=0;

  if ((noReaders = sem_open("sem1", O_CREAT, 0644, 1)) == SEM_FAILED) //(initial value = 3)
  {
    perror("semaphore noReaders initilization");
    exit(1);
  }
  if ((noWriters = sem_open("sem2", O_CREAT, 0644, 1)) == SEM_FAILED) //(initial value = 1)
  {
    perror("semaphore noWriters initilization");
    exit(1);
  }
  if ((writerSwitch = sem_open("sem3", O_CREAT, 0644, 1)) == SEM_FAILED) //(initial value = 1)
  {
    perror("semaphore writerSwitch initilization");
    exit(1);
  }
  if ((resource = sem_open("sem4", O_CREAT, 0644, 1)) == SEM_FAILED) //(initial value = 1)
  {
    perror("semaphore resource initilization");
    exit(1);
  }
  if ((readerSwitch = sem_open("sem5", O_CREAT, 0644, 1)) == SEM_FAILED) //(initial value = 1)
  {
    perror("semaphore readerSwitch initilization");
    exit(1);
  }

}

//READER
void reader() 
{
//ENTRY Section
	printf("r1\n");
	sem_wait(noReaders);
	printf("r2\n");
	sem_wait(readerSwitch);
	(*readcount)++;
	printf("Readcount: %d \n",(*readcount));
	if((*readcount)==1)
		sem_wait(noWriters);
	sem_post(readerSwitch);
	sem_post(noReaders);

//CRITICAL Section
  printf("\n********* READING **************\n");
  printf("reading started by %d\n",getpid());
  //reading is performed
  printf("Reading.....\n");
  sleep(1);
  printf("reading completed by %d\n",getpid());
  printf("********* READING ENDS *********\n");

//EXIT Section
	sem_wait(readerSwitch);
	(*readcount)--;
	if((*readcount)==0)
	{
		sem_post(noWriters);
	}
	sem_post(readerSwitch);

}

//WRITER
void writer() 
{
//ENTRY Section
	printf("w1\n");
	sem_wait(writerSwitch);
	printf("w2\n");
	(*writecount)++;
	if((*writecount)==1)
		sem_wait(noReaders);
	sem_post(writerSwitch);
	sem_wait(noWriters);


  //CRITICAL Section
  printf("\n********* WRITING **************\n");                
  printf("writing started by %d\n",getpid());
  //writing is performed
  printf("Writing.....\n");
  sleep(2);
  printf("writing completed by %d\n",getpid());
  printf("********* WRITING ENDS *********\n"); 

//EXIT Section
	sem_post(noWriters);
	sem_wait(writerSwitch);
	(*writecount)--;
	if((*writecount)==0)
		sem_post(noReaders);
	sem_post(writerSwitch);
}

void read_write(int r,int w)
{
	initialize();
	pid_t wpid;

	int i,status=0;

	if(getpid()>0)
	{
		for(i=0;i<r+w;i++)
		{
			pid_t newp=fork();
			if(newp<0)
			{
				printf("fork error\n");
				exit(1);
			}
			if(newp==0 && i<r)
			{
				printf("%dreader%d\n",i,getpid());
				reader();
				exit(0);
			}
			else if(newp==0 && i>=r)
			{
				printf("%dwriter%d\n",i,getpid());
				writer();
				exit(0);
			}
		}
	}
	while ((wpid = wait(&status)) > 0);
}

int main()
{
	int r,w,i;    
	printf("\nEnter the no of readers: ");
	scanf("%d",&r);
	printf("\nEnter the no of writers: ");
	scanf("%d",&w);
	read_write(r,w);
	munmap(readcount, sizeof *readcount);
	return 0;
}