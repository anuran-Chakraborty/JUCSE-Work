#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Program implements telephone conversation using fifo

int main()
{
	int fd;
	char* fifopath = "./fifo1";
	mkfifo(fifopath,0777);

	char str1[80],str2[80];

	while(1)
	{
		//Open fifo for writing
		fd=open(fifopath, O_WRONLY);
		printf("Enter weather report: ");
		fgets(str2,80,stdin);

		//Write to fifo
		write(fd,str2,strlen(str2)+1);
		close(fd);
	}
	return 0;
}