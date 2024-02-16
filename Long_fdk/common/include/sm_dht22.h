/*
 * sm_dht22.h
 *
 *  Created on: Dec 25, 2023
 *      Author: My PC
 */

#ifndef INCLUDE_SM_DHT22_H_
#define INCLUDE_SM_DHT22_H_
#include "sm_bsp_io.h"

typedef struct DHT22_t DHT22;
struct DHT22_t{
    sm_bsp_io_t* dht_pin;
    float temperature;
    float humidity;
};
void sm_dht22_init(DHT22* p_dht, sm_bsp_io_t* dht_pin);
void sm_dht22_process(DHT22* p_dht);
#endif /* INCLUDE_SM_DHT22_H_ */
