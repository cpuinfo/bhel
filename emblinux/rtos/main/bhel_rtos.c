#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t sensor_task_handle;

void sensor_task(void *pvParameters)
{
    while (1)
    {
        printf("Sensor task: entry\n");
        vTaskSuspend(NULL);
        // ---------
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void app_main(void)
{
    int count = 0;
    printf("Hello BHEL on ESP32\n");

    xTaskCreate(sensor_task, "sensor_task", 1024, NULL, 10, &sensor_task_handle);

    while (1)
    {
        count++;
        if (count == 10)
        {
            vTaskResume(sensor_task_handle);
        }
        printf("Main thread\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
