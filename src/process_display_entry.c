#include "process_display.h"
#include "display_app.h"
#include "hal_data.h"
#include "board.h"
/* LCD entry function */
/* pvParameters contains TaskHandle_t */
void process_display_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    /* TODO: add your own code here */
    board_init();
    display_app_init();
    while (1)
    {
        display_process();
        vTaskDelay (1);
    }
}
