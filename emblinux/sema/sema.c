#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int count = 0;
sem_t countSem;

void *incThread(void *args)
{
    while (1)
    {
        sem_wait(&countSem);
        count++;
        printf("Inc Thread: %d\n", count);
        sem_post(&countSem);
    }
}

void *decThread(void *args)
{
    while (1)
    {

        sem_wait(&countSem);
        count--;
        printf("Dec Thread: %d\n", count);
        sem_post(&countSem);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t incId, decId;
    printf("Main: Creating thread\n");

    sem_init(&countSem, 0, 1);
    pthread_create(&incId, NULL, incThread, NULL);
    pthread_create(&decId, NULL, decThread, NULL);
    pthread_join(incId, NULL);
    pthread_join(decId, NULL);
    printf("Main: Sensor thread joined\n");

    return 0;
}
