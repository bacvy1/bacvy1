#include "process_lte.h"
#include "mqtt_app.h"
#include "hal_data.h"
#include "board.h"
/* LTE entry function */
/* pvParameters contains TaskHandle_t */
void process_lte_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    /* TODO: add your own code here */
    board_init();
    mqtt_client_init();
    while (1)
    {
        mqtt_client_process();
        vTaskDelay (1);
    }
}
