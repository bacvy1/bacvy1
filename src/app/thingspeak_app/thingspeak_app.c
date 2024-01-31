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
#include "cJSON.h"

sm_mqtt_client_error_t thingspeak_update(AIR_SENSOR_APP *p_app, void* stream);
sm_mqtt_client_error_t thingspeak_subcribe(AIR_SENSOR_APP *p_app);
#define dataFormat      "field1=%2.1f&field2=%2.1f&field3=%2.1f&field4=%2.1f&field5=%f&field6=%f"
char update_data[100];
uint16_t counter = 0;
static void mqtt_event(sm_mqtt_client_t *client, sm_mqtt_client_event_t event);
static void command_data_handle(THING_SPEAK_APP* p_thinkspeak);

void thingspeak_app_init(){
    sprintf(air_sensor_app.thingspeak.update_topic,UPDATE_TOPIC, DEVICE_ID);
    sprintf(air_sensor_app.thingspeak.subcribe_topic,SUBCRIBE_TOPIC, DEVICE_ID);
    sm_mqtt_client_register_handle(air_sensor_app.mqtt_client, mqtt_event);
}


void thingspeak_process(){
    AIR_SENSOR_APP* p_app = &air_sensor_app;
    counter++;
    if(sm_mqtt_client_get_state(p_app->mqtt_client) == MQTT_ST_CONNECTED){
        if(counter > 1000){
            sm_mqtt_client_error_t sub_error = thingspeak_subcribe(&air_sensor_app);
            counter = 0;
            sprintf (update_data, dataFormat, p_app->dht22.temperature, p_app->dht22.humidity,
                     p_app->adc_sensor.co_value, p_app->adc_sensor.dust_value, p_app->gps.lat, p_app->gps.lon);
            sm_mqtt_client_error_t update_result = thingspeak_update(&air_sensor_app, update_data);
            if(update_result == MQTT_ERROR_FAIL){
                update_result = MQTT_ERROR_NO;
                sm_mqtt_client_set_state(air_sensor_app.mqtt_client, MQTT_ST_DISCONNECT);
            }
            if(sub_error == MQTT_ERROR_FAIL){
                sub_error = MQTT_ERROR_NO;
                sm_mqtt_client_set_state(air_sensor_app.mqtt_client, MQTT_ST_DISCONNECT);
            }
        }
    }

}

sm_mqtt_client_error_t thingspeak_update(AIR_SENSOR_APP *p_app, void* stream)
{
    return sm_mqtt_publics (p_app->mqtt_client, p_app->thingspeak.update_topic, (char*) stream, strlen ((char*) stream), 1, 0);
}

sm_mqtt_client_error_t thingspeak_subcribe(AIR_SENSOR_APP *p_app)
{
    return sm_mqtt_subscribes(p_app->mqtt_client, p_app->thingspeak.subcribe_topic, 0);
}

static void command_data_handle(THING_SPEAK_APP* p_thinkspeak){
    cJSON* root = cJSON_Parse(p_thinkspeak->receive_data);
    if(root == NULL){
        return;
    }
    cJSON* max_co = cJSON_GetObjectItem(root, "max_co");
    if(max_co == NULL){
        return;
    }
    cJSON* max_dust = cJSON_GetObjectItem(root, "max_dust");
    if(max_dust == NULL){
        return;
    }
    cJSON* max_temp = cJSON_GetObjectItem(root, "max_temp");
    if(max_temp == NULL){
        return;
    }

    p_thinkspeak->max_co = (float)cJSON_GetNumberValue(max_co);
    p_thinkspeak->max_dust = (float)cJSON_GetNumberValue(max_dust);
    p_thinkspeak->max_temp = (float)cJSON_GetNumberValue(max_temp);

    cJSON_Delete(root);
}

static void mqtt_event(sm_mqtt_client_t *client, sm_mqtt_client_event_t event) {
    switch (event) {
    case MQTT_EVENT_NONE:
        /* User code */
        break;
    case MQTT_EVENT_CLOSE:
        /* User code */

        break;
    case MQTT_EVENT_CONNECTED:
        /* User code */

        break;
    case MQTT_EVENT_DATA:
        /* User code */
        strcpy(air_sensor_app.thingspeak.receive_data, client->data);
        command_data_handle(&air_sensor_app.thingspeak);
        break;
    case MQTT_EVENT_DISCONNECTED:
        /* User code */
        break;
    case MQTT_EVENT_ERROR:
        /* User code */
        break;
    case MQTT_EVENT_OPEN:
        /* User code */
        break;
    default:
        break;
    }
}

