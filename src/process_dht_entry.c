#include "process_dht.h"
#include "air_sensor_app.h"
#include "hal_data.h"
#include "board.h"
/* MEA entry function */
/* pvParameters contains TaskHandle_t */
void process_dht_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    dht_app_init();
    /* TODO: add your own code here */
    while (1)
    {
        dht_app_process();
        vTaskDelay(1);
    }
}
