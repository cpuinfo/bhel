#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

TaskHandle_t task_handle1, task_handle2;
QueueHandle_t locq_handle;

void location_task(void *pvParameters)
{
    int loc = 0;
    while (1)
    {
        loc++;
        printf("Location task: entry\n");
        xQueueSend(locq_handle, &loc, (TickType_t)10);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void location_processor(void *pvParameters)
{
    int buff;
    while (1)
    {
        printf("Location Processor task: entry\n");
        xQueueReceive(locq_handle, &buff, (TickType_t)10);
        printf("Loc: %d\n", buff);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
void app_main(void)
{
    int count = 0;
    printf("Hello BHEL on ESP32\n");

    locq_handle = xQueueCreate(5, sizeof(int));
    xTaskCreate(location_task, "sensor_task", 2048, NULL, 10, &task_handle2);
    xTaskCreate(location_processor, "sensor_task", 2048, NULL, 12, &task_handle1);

    while (1)
    {
        count++;
        printf("Main thread\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
