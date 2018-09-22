#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void writer (const char* message, int count, FILE* stream)
{
    while(count--) {
        /* Write the message to the stream, and send it off immediately.*/
        fprintf (stream, "%s %d\n", message, count);
        fflush (stream);
        /* Snooze a while. */
        sleep (1);
    }
}
/* Read random strings from the stream as long as possible.
*/

void reader (FILE* stream)
{
    char buffer[1024];
    /* Read until we hit the end of the stream. fgets reads until
    either a newline or the end-of-file. */
    while (!feof (stream)
            && !ferror (stream)
            && fgets (buffer, sizeof (buffer), stream) != NULL)
    fputs (buffer, stdout);
}

int main(){
    int fds[2];
    pipe(fds);

    pid_t pid = fork();

    /* We shall write from parent process and read in the child process*/
    if(pid != 0) {
        /* PARENT PROCESS */

        /* Close the read end */
        close(fds[0]);

        /* Convert the write file descriptor to a FILE object, and write to it. */
        FILE* stream = fdopen (fds[1], "w");
        writer ("Hello, world.", 5, stream);

        close(fds[1]);
    } else {
        /* CHILD PROCESS */
        // Close the write end
        close(fds[1]);

        /* Convert the read file descriptor to a FILE object, and read from it. */
        FILE* stream = fdopen (fds[0], "r");
        reader (stream);

        close(fds[0]);
    }
}