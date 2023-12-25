#include "process_measure.h"
#include "air_sensor_app.h"
#include "measure_app.h"
#include "hal_data.h"
#include "board.h"
/* MEA entry function */
/* pvParameters contains TaskHandle_t */
void process_measure_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    board_init();
    measure_app_init();
    /* TODO: add your own code here */
    while (1)
    {
        measure_app_process();
        vTaskDelay (1);
    }
}
