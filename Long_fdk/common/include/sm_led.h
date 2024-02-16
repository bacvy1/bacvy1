/*
 * sm_led.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Admin
 */

#ifndef COMMON_INCLUDE_SM_LED_H_
#define COMMON_INCLUDE_SM_LED_H_

#include "stdint.h"
#include "sm_bsp_io.h"

typedef struct sm_led sm_led_t;

struct sm_led
{
    sm_bsp_io_t *_io;
    enum led_state
    {
        LED_ST_OFF = 0, LED_ST_ON
    } _state;
};

/**
 * @brief
 * @param _this
 * @param _io
 */
void sm_led_init(sm_led_t *_this, sm_bsp_io_t *_io);

/**
 * @brief
 * @param _this
 * @param _state
 * @return
 */
int32_t sm_led_set_state(sm_led_t *_this, enum led_state _state);

#endif /* COMMON_INCLUDE_SM_LED_H_ */
