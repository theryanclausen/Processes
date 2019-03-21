// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("Fork spooned.");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("child pre exec\n");
        char* args[] = {"/bin/ls", NULL};
        execv(args[0], args);
        printf("post execv\n");
    }
    else
    {
        printf("Parent\n");
    }
       

    return 0;
}
