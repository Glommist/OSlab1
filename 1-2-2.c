#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t signal;
static int n = 0;

void* add(void* arg) 
{
    for (int i = 0; i < 100000; i++)
    {
        sem_wait(&signal);
        n++;
        sem_post(&signal);
    }
    return NULL;
}

void* sub(void* arg) 
{
    for (int i = 0; i < 100000; i++) 
    {
        sem_wait(&signal);
        n--;
        sem_post(&signal);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    sem_init(&signal, 0, 1);

    pthread_create(&thread1, NULL, add, NULL);
    pthread_create(&thread2, NULL, sub, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("n = %d\n", n);

    sem_destroy(&signal);
    
    return 0;
}
