/*
 * thingspeak_app.c
 *
 *  Created on: Dec 21, 2023
 *      Author: My PC
 */
#include "thingspeak_app.h"
#include "air_sensor_app.h"
#include "mqtt_app.h"
#include "app_thingspeak_config.h"
sm_mqtt_client_error_t thingspeak_update(AIR_SENSOR_APP *p_app, void* stream);
#define dataFormat      "field1=%d&field2=%d"
char update_data[100];
uint16_t counter = 0;
void thingspeak_app_init(){
    sprintf(air_sensor_app.thingspeak.update_topic,UPDATE_TOPIC, DEVICE_ID);
}

void thingspeak_process(){
    AIR_SENSOR_APP* p_app = &air_sensor_app;
    counter++;
    if(sm_mqtt_client_get_state(p_app->mqtt_client) == MQTT_ST_CONNECTED){
        if(counter > 1000){
            counter = 0;
            uint8_t temp = 17;
            uint8_t humidity = 50;
            sprintf(update_data, dataFormat, temp, humidity);
            sm_mqtt_client_error_t update_result = thingspeak_update(&air_sensor_app, update_data);
            if(update_result == MQTT_ERROR_FAIL){
                update_result = MQTT_ERROR_NO;
                sm_mqtt_client_set_state(air_sensor_app.mqtt_client, MQTT_ST_DISCONNECT);
            }
        }
    }

}

sm_mqtt_client_error_t thingspeak_update(AIR_SENSOR_APP *p_app, void* stream)
{
    return sm_mqtt_publics (p_app->mqtt_client, p_app->thingspeak.update_topic, (char*) stream, strlen ((char*) stream), 1, 0);
}
