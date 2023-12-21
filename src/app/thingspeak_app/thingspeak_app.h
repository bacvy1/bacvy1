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

typedef struct THING_SPEAK_APP_t THING_SPEAK_APP;
struct THING_SPEAK_APP_t{
    char update_topic[TOPIC_MAX_LENGTH];
};

void thingspeak_process();
void thingspeak_app_init();
#endif /* APP_THINGSPEAK_APP_THINGSPEAK_APP_H_ */
