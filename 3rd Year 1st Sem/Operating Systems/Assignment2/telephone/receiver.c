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
		//Open fifo for reading
		fd=open(fifopath, O_RDONLY);

		//Read from fifo
		read(fd,str1,sizeof(str1));
		printf("Sender: %s\n",str1);
		close(fd);

		//Open fifo for writing
		fd=open(fifopath, O_WRONLY);
		fgets(str2,80,stdin);

		//Write to fifo
		write(fd,str2,strlen(str2)+1);
		close(fd);
	}
	return 0;
}