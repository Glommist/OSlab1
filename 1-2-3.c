#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* system_call(void* arg) 
{
    pid_t pid=getpid();
    pthread_t tid = pthread_self(); 
    char * str = (char*)arg;
    printf(str);
    printf(" tid = %d ,pid = %d\n",tid,pid);
    system("./system_call.o");
    printf(str);
    printf(" systemcall return\n");    
}

int main() {
    pthread_t thread1, thread2;
    char t1[]="thread1";
    char t2[]="thread2";
    if(pthread_create(&thread1, NULL, system_call,&t1)==0)
    {
        printf("thread1 create success!\n");
    }
    if(pthread_create(&thread2, NULL, system_call,&t2)==0)
    {
        printf("thread2 create success!\n");
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}