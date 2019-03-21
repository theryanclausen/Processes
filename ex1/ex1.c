// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 99;
    printf("\nIn the beginning... \n\n");
    int frk = fork();
    printf("\na fork... \n\n");
    if (frk == 0)
    {
        printf("child %d \n", x);
        x = 7;
        printf("child changed %d \n", x);
    }
    else
    {
        printf("parent %d \n", x);
        x = 16;
        printf("parent changed %d \n", x);
    }

    // Your code here
    //printf("\nIn the end... \n\n");
    return 0;
}
