#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t countMutex;

void *incThread(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&countMutex);
        count++;
        printf("Inc Thread: %d\n", count);
        pthread_mutex_unlock(&countMutex);
    }
}

void *decThread(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&countMutex);
        count--;
        printf("Dec Thread: %d\n", count);
        pthread_mutex_unlock(&countMutex);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t incId, decId;
    printf("Main: Creating thread\n");

    pthread_mutex_init(&countMutex, NULL);

    pthread_create(&incId, NULL, incThread, NULL);
    pthread_create(&decId, NULL, decThread, NULL);
    pthread_join(incId, NULL);
    pthread_join(decId, NULL);
    printf("Main: Sensor thread joined\n");

    return 0;
}
