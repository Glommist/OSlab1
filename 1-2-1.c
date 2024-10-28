#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* add(void* arg) 
{
    int* n=(int*)arg;
    for (int i = 0; i < 100000; i++) {
        (*n)++;
    }
    return NULL;
}

void* sub(void* arg) 
{
    int* n=(int*)arg;
    for (int i = 0; i < 100000; i++) {
        (*n)--;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    static int n = 0;

    pthread_create(&thread1, NULL, add, &n);
    pthread_create(&thread2, NULL, sub, &n);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("n = %d\n", n);
    return 0;
}