/**
 * @file process_lte_entry.c
 * @author LongDH
 * @date 2024
 * @brief LTE main process of Air-sensor project
 *
 * */

/**@defgroup Main process_lte_entry.c
 * Main file of process LTE in project Air-sensor
 * @{
 * */
#include "process_lte.h"
#include "mqtt_app.h"
#include "hal_data.h"
#include "air_sensor_app.h"
#include "thingspeak_app.h"
#include "board.h"
#include "time.h"
#include "FreeRTOS.h"

#define TIME_UPDATE_SNTP 60000

static void update_time() {
    static uint32_t time_update = TIME_UPDATE_SNTP;
    struct tm* p_time = &air_sensor_app.time;
    if (time_update % TIME_UPDATE_SNTP == 0) {
        if (sm_ec200s_get_time_network(&air_sensor_app.ec200s, p_time) == 0) {
            set_time(p_time);
        }
    }
    time_update++;
}
/* LTE entry function */
/* pvParameters contains TaskHandle_t */
void process_lte_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);
    /* TODO: add your own code here */

    mqtt_client_init();
    thingspeak_app_init();
    while (1)
    {
        mqtt_client_process();
        thingspeak_process();
        update_time();
        vTaskDelay((1));
    }
}
