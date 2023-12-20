/*
 * adc.c
 *
 *  Created on: Jul 10, 2023
 *      Author: Admin
 */


#include "sm_bsp_adc.h"

static int32_t adc_start(sm_bsp_adc_t *_this);
static int32_t adc_stop(sm_bsp_adc_t *_this);
static int32_t adc_open(sm_bsp_adc_t *_this);
static int32_t adc_close(sm_bsp_adc_t *_this);

sm_bsp_adc_proc_t adc_func = {.start = adc_start,.stop = adc_stop,.open = adc_open,.close = adc_close};


static int32_t adc_start(sm_bsp_adc_t *_this){
    /*User code*/
    (void) _this;
    return 0;
}
static int32_t adc_stop(sm_bsp_adc_t *_this){
    /*User code*/
    (void) _this;
    return 0;
}
static int32_t adc_open(sm_bsp_adc_t *_this){
    /*User code*/
    (void) _this;
    return 0;
}
static int32_t adc_close(sm_bsp_adc_t *_this){
    /*User code*/
    (void) _this;
    return 0;
}
