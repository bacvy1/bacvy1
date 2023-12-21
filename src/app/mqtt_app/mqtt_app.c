/*
 * mqtt_app.c
 *
 *  Created on: Jul 7, 2023
 *      Author: Admin
 */

#include "mqtt_app.h"
#if USING_MQTT
#include "sm_ec200s.h"
#include "hal_data.h"
#include "sm_porting.h"
#include "FreeRTOS.h"
#include "air_sensor_app.h"
#include "app_thingspeak_config.h"
#define TEST_TOPIC  "dt/test"

char topic[100];
// Example MQTT Client using EC200N

//	Create EVENT data Queue

/*define mqtt client funtion*/
sm_mqtt_client_error_t mqtt_open(sm_mqtt_client_t *client, char *host,
		uint32_t port);
sm_mqtt_client_error_t mqtt_close(sm_mqtt_client_t *client);
sm_mqtt_client_error_t mqtt_connect(sm_mqtt_client_t *client, char *name,
		char *user, char *pass);
sm_mqtt_client_error_t mqtt_disconnect(sm_mqtt_client_t *client);
sm_mqtt_client_error_t mqtt_publics(sm_mqtt_client_t *client,
		const char *topic, const char *data, uint32_t len, uint8_t qos,
		uint8_t retain);
sm_mqtt_client_error_t mqtt_subscribes(sm_mqtt_client_t *client,
		const char *topic, uint8_t qos);
sm_mqtt_client_error_t mqtt_unsubscribes(sm_mqtt_client_t *client,
		const char *topic);
sm_mqtt_client_error_t mqtt_data_iscomming(sm_mqtt_client_t *client,
		char *topic, char *data);
sm_mqtt_client_error_t mqtt_reconnect(sm_mqtt_client_t *client);
/*end define mqtt client funtion*/
static void mqtt_event(sm_mqtt_client_t *client, sm_mqtt_client_event_t event);
/*define variable*/
//sm_mqtt_client_t *mqtt_client;

#define BUFF_LENGTH 			2048
#define MQTT_UPDATE_CYCLE		10000
#define MQTT_UPDATE_EVENT_CYCLE	20000

extern sm_bsp_io_t *lte_rs_pin;
extern sm_bsp_uart_t *lte_uart;
char topic_mqtt[128];
char data_mqtt[BUFF_LENGTH];

#define PORT_PB 2

//sm_mqtt_client_proc_t client_proc = { .open = mqtt_open,
//									  .close = mqtt_close,
//									  .connect = mqtt_connect,
//									  .disconnect = mqtt_disconnect,
//									  .publics = mqtt_publics,
//									  .subscribes = mqtt_subscribes,
//									  .unsubscribes = mqtt_unsubscribes,
//									  .data_iscomming = mqtt_data_iscomming,
//									  .reconnect = mqtt_reconnect
//};

sm_mqtt_client_proc_t client_proc;

void mqtt_client_init() {

	sm_ec200s_init (&air_sensor_app.ec200s, lte_rs_pin, lte_uart);
	sm_ec200s_set_apn (&air_sensor_app.ec200s, "m3-world", "mms", "mms");
	sm_ec200s_get_ip (&air_sensor_app.ec200s);
	CONFIG_MQTT:
	if(sm_ec200s_config_mqtt(&air_sensor_app.ec200s) != 0) goto CONFIG_MQTT;

	client_proc.open = mqtt_open;
	client_proc.close = mqtt_close;
	client_proc.connect = mqtt_connect;
	client_proc.disconnect = mqtt_disconnect;
	client_proc.publics = mqtt_publics;
	client_proc.subscribes = mqtt_subscribes;
	client_proc.unsubscribes = mqtt_unsubscribes;
	client_proc.data_iscomming = mqtt_data_iscomming;
//	client_proc.reconnect = mqtt_reconnect;
	sm_mqtt_client_register_handle(air_sensor_app.mqtt_client, mqtt_event);
    air_sensor_app.mqtt_client = sm_mqtt_client_init_static (&client_proc, (void*) &air_sensor_app.ec200s,
                                                             "mqtt3.thingspeak.com", 1883, USERNAME, PASSWORD);
	air_sensor_app.mqtt_client->topic = topic_mqtt;
	air_sensor_app.mqtt_client->data = data_mqtt;
	air_sensor_app.mqtt_client->client_id = CLIENT_ID;
	sprintf(topic, "%s", TEST_TOPIC);
}

void mqtt_client_process() {
//	count = xTaskGetTickCount();
	sm_mqtt_client_process(air_sensor_app.mqtt_client);
	if (sm_mqtt_client_get_state(air_sensor_app.mqtt_client) == MQTT_ST_CLOSED) {
		sm_ec200s_init (&air_sensor_app.ec200s, lte_rs_pin, lte_uart);
		sm_ec200s_set_apn(&air_sensor_app.ec200s, "m3-world", "mms", "mms");
		sm_ec200s_get_ip(&air_sensor_app.ec200s);
		sm_ec200s_config_mqtt(&air_sensor_app.ec200s);
		sm_mqtt_client_set_state(air_sensor_app.mqtt_client, MQTT_ST_OPEN);
	}

//    count = xTaskGetTickCount();
	/*USER CODE*/

}
sm_mqtt_client_error_t mqtt_open(sm_mqtt_client_t *client, char *host,
		uint32_t port) {
	sm_ec200s_t *p_ec = (sm_ec200s_t*) client->arg;
	return sm_ec200s_open_mqtt(p_ec, host, port);
}
sm_mqtt_client_error_t mqtt_close(sm_mqtt_client_t *client) {
	sm_ec200s_t *p_ec = (sm_ec200s_t*) client->arg;
	return sm_ec200s_close_mqtt(p_ec);
}
sm_mqtt_client_error_t mqtt_connect(sm_mqtt_client_t *client, char *name,
		char *user, char *pass) {
	sm_ec200s_t *p_ec = (sm_ec200s_t*) client->arg;
	return sm_ec200s_connect_mqtt(p_ec, name, user, pass);
}
sm_mqtt_client_error_t mqtt_disconnect(sm_mqtt_client_t *client) {
	sm_ec200s_t *p_ec = (sm_ec200s_t*) client->arg;
	return sm_ec200s_disconnect_mqtt(p_ec);
}
sm_mqtt_client_error_t mqtt_publics(sm_mqtt_client_t *client,
		const char *topic, const char *data, uint32_t len, uint8_t qos,
		uint8_t retain) {
	sm_ec200s_t *p_ec = (sm_ec200s_t*) client->arg;
	return sm_ec200s_public_mqtt(p_ec, (char*) topic, (char*) data, len, qos,
			retain);
}
sm_mqtt_client_error_t mqtt_subscribes(sm_mqtt_client_t *client,
		const char *topic, uint8_t qos) {
	sm_ec200s_t *p_ec = (sm_ec200s_t*) client->arg;
	return sm_ec200s_subscribes_mqtt(p_ec, (char*) topic, qos);
}
sm_mqtt_client_error_t mqtt_unsubscribes(sm_mqtt_client_t *client,
		const char *topic) {
	sm_ec200s_t *p_ec = (sm_ec200s_t*) client->arg;
	return sm_ec200s_unsubscribes_mqtt(p_ec, (char*) topic);
}
sm_mqtt_client_error_t mqtt_data_iscomming(sm_mqtt_client_t *client,
		char *topic, char *data) {
	sm_ec200s_t *p_ec = (sm_ec200s_t*) client->arg;
	return sm_ec200s_data_iscomming_mqtt(p_ec, topic, data);
}
sm_mqtt_client_error_t mqtt_reconnect(sm_mqtt_client_t *client)
{
    (void) client;
    sm_ec200s_init (&air_sensor_app.ec200s, lte_rs_pin, lte_uart);
    return sm_ec200s_set_apn (&air_sensor_app.ec200s, "m3-world", "mms", "mms");
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
//            printf("Topic: %s\r\n",client->topic);
//            printf("Data: %s\r\n",client->data);
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


#endif
