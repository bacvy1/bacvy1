#include "process_display.h"
#include "display_app.h"
#include "air_sensor_app.h"

#include "time.h"
#define SCAN_INTERVAL_mS    10
/* LCD entry function */
/* pvParameters contains TaskHandle_t */
void process_display_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */

    display_app_init();
    int32_t update_time = 1000;
    struct tm* time_network;
    while (1)
    {
        if(update_time > 1000){
            time_network = get_time();
            air_sensor_app.time.tm_hour = time_network->tm_hour;
            air_sensor_app.time.tm_min = time_network->tm_min;
            update_time = 0;
        }
        update_time += SCAN_INTERVAL_mS;
        display_process();
        vTaskDelay (1);
    }
}
