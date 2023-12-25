/*
 * dht_app.c
 *
 *  Created on: 26 Dec 2023
 *      Author: Admin
 */
#include "dht_app.h"
#include "air_sensor_app.h"

extern sm_bsp_io_t *dht_22_pin;

void dht_app_init(){
    DHT22* p_dht = &air_sensor_app.dht22;
    sm_dht22_init(p_dht, dht_22_pin);
}

void dht_app_process(){
    DHT22* p_dht = &air_sensor_app.dht22;
    sm_dht22_process(p_dht);
}
