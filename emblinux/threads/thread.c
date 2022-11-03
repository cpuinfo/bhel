#include <stdio.h>
#include <pthread.h>

// void *(*start_routine) (void *)

void *sensor_thread(void *args)
{
    printf("Sensor Thread: %s\n", (char *)args);
}

int main(int argc, char const *argv[])
{
    pthread_t sid1, sid2;
    printf("Main: Creating thread\n");
    pthread_create(&sid1, NULL, sensor_thread, "s1\n");
    pthread_create(&sid2, NULL, sensor_thread, "s2\n");
    printf("Main: Thread Created\n");
    pthread_join(sid1, NULL);
    pthread_join(sid2, NULL);
    printf("Main: Sensor thread joined\n");

    return 0;
}
