#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "testmodule/test.h"

void app_main(void)
{
    int i = 0;
    while (1) {
        printf("[%d] Hello world!\n", i);
        test();
        i++;
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
