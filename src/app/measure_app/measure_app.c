/*
 * measure_app.c
 *
 *  Created on: Dec 25, 2023
 *      Author: My PC
 */
#include "measure_app.h"
#include "air_sensor_app.h"
extern sm_bsp_io_t *dht_22_pin;

void measure_app_init(){
    DHT22* p_dht = &air_sensor_app.dht22;
    DUST_SENSOR* p_dust = &air_sensor_app.dust_sensor;
    sm_dht22_init(p_dht, dht_22_pin);
    dust_sensor_init(p_dust);
}

void measure_app_process(){
    DHT22* p_dht = &air_sensor_app.dht22;
    DUST_SENSOR* p_dust = &air_sensor_app.dust_sensor;
    sm_dht22_process(p_dht);
    dust_sensor_process(p_dust);
}
