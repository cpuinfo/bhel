#include <stdio.h>
#include <pthread.h>

void *sensor_task(void *args)
{
    printf("Sensor task\n");
    pthread_exit(NULL);
}

void app_main(void)
{
    pthread_t sid;
    printf("Hello BHEL on ESP32\n");
    pthread_create(&sid, NULL, sensor_task, NULL);
    pthread_join(sid, NULL);
}
