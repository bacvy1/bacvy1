/*
 * air_sensor_app.h
 *
 *  Created on: Dec 20, 2023
 *      Author: My PC
 */

#ifndef APP_AIR_SENSOR_APP_H_
#define APP_AIR_SENSOR_APP_H_
#include "mqtt_app.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "board.h"
#include "thingspeak_app.h"
#include "display_app.h"
#include "gps_app.h"
#include "time.h"
#include <sm_ec200s.h>


typedef struct AIR_SENSOR_APP_t AIR_SENSOR_APP;
struct AIR_SENSOR_APP_t{
    sm_ec200s_t       ec200s;
    sm_mqtt_client_t* mqtt_client;
    THING_SPEAK_APP   thingspeak;
    LCD               lcd;
    L76_LB            gps;
    struct tm         time;
};

extern AIR_SENSOR_APP air_sensor_app;
#endif /* APP_AIR_SENSOR_APP_H_ */
