#include "process_lte.h"
/* LTE entry function */
/* pvParameters contains TaskHandle_t */
void process_lte_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */
    while (1)
    {
        vTaskDelay (1);
    }
}
