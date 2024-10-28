#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    pid_t pid, pid1;
    pid = fork();
    if(pid<0)
    {
        fprintf(stderr,"Frok Failed");
        return 1;
    }
    else if(pid == 0)
    {
        pid = getpid();
        printf("child process PID :%d  ",pid);
        system("./system_call.o");
    }
    else
    {
        pid1 = getpid();
        printf("parent process PID :%d  ",pid1);
        printf("child process1 PID :%d  ",pid);
        wait(NULL);
    }
    return 0;
}