// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    char buf[MSGSIZE];
    int pipe1[2];
    pipe(pipe1);

    pid_t frk = fork();
    if (frk < 0)
    {
        perror("Fork spooned.");
        exit(1);
    }
    if (frk == 0)
    {
        printf("hello child\n");
        write(pipe1[1], msg1, MSGSIZE);
        write(pipe1[1], msg2, MSGSIZE);
        write(pipe1[1], msg3, MSGSIZE);
    }
    else
    {
        printf("Wait for pipe\n");
        wait(NULL);
        printf("pipes are calling\n");
        close(pipe1[1]);
        while (read(pipe1[0], buf, MSGSIZE) > 0)
        {
            printf("%s \n", buf);
        }
        
    }

    return 0;
}
