#include "process_gps.h"
/* GPS entry function */
/* pvParameters contains TaskHandle_t */
void process_gps_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */
    while (1)
    {
        vTaskDelay (1);
    }
}
