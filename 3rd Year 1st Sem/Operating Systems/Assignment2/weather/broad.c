#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Program implements weather broadcast using fifo

int main()
{
    int fd[5],i;

    //Define fifo paths
    char* fifopath[5] = {"fifo1","fifo2","fifo3","fifo4","fifo5"};
    
    for(i=0;i<5;i++)
        mkfifo(fifopath[i],0777);

    char str1[80],str2[80];

    while(1)
    {
        printf("Enter weather report\n");
        fgets(str2,80,stdin);

        for(i=0;i<5;i++)
        {
            //Open fifo for writing
            fd[i]=open(fifopath[i], O_WRONLY);
            printf("Writing to fifo %d\n",i);
            //Write to fifo
            write(fd[i],str2,strlen(str2)+1);
            close(fd[i]);
        }

    }
    return 0;
}