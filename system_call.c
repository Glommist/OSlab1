#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("system_call:pid = %d  ",getpid());
    return 0;
}