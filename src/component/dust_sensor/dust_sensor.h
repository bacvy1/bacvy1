/*
 * dust_sensor.h
 *
 *  Created on: Dec 25, 2023
 *      Author: My PC
 */

#ifndef COMPONENT_DUST_SENSOR_DUST_SENSOR_H_
#define COMPONENT_DUST_SENSOR_DUST_SENSOR_H_
#include "dust_sensor_hw.h"
typedef struct DUST_SENSOR_t DUST_SENSOR;
struct DUST_SENSOR_t{
    DUST_hw* hw;
    float result;
};

void dust_sensor_init(DUST_SENSOR* p_dust);
void dust_sensor_process(DUST_SENSOR* p_dust);
#endif /* COMPONENT_DUST_SENSOR_DUST_SENSOR_H_ */
