/*
 * thingspeak_app.h
 *
 *  Created on: Dec 21, 2023
 *      Author: My PC
 */

#ifndef APP_THINGSPEAK_APP_THINGSPEAK_APP_H_
#define APP_THINGSPEAK_APP_THINGSPEAK_APP_H_
#define TOPIC_MAX_LENGTH 100

#define UPDATE_TOPIC    "channels/%s/publish"
#define SUBCRIBE_TOPIC  "channels/%s/subscribe"

typedef struct THING_SPEAK_APP_t THING_SPEAK_APP;
struct THING_SPEAK_APP_t{
    char update_topic[TOPIC_MAX_LENGTH];
    char subcribe_topic[TOPIC_MAX_LENGTH];
    char receive_data[1024];
    float max_temp;
    float max_co;
    float max_dust;
    float max_humi;
    int   period;
};

void thingspeak_process();
void thingspeak_app_init();
#endif /* APP_THINGSPEAK_APP_THINGSPEAK_APP_H_ */
