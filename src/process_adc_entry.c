#include "process_adc.h"
#include "air_sensor_app.h"
#include "hal_data.h"
#include "board.h"
/* ADC entry function */
/* pvParameters contains TaskHandle_t */
void process_adc_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    board_init();
    adc_app_init();
    /* TODO: add your own code here */
    while (1)
    {
        adc_app_process();
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
