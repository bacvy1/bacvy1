/*
 * can.c
 *
 *  Created on: Jul 10, 2023
 *      Author: Admin
 */


#include "sm_bsp_can.h"

static int32_t can_write(sm_bsp_can_t *_this,sm_bsp_can_mgs_t *mgs);
static int32_t can_set_baud(sm_bsp_can_t *_this,uint32_t baud);
static int32_t can_open(sm_bsp_can_t *_this);
static int32_t can_close(sm_bsp_can_t *_this);

sm_bsp_can_proc_t can_func = {.close = can_close,.open = can_open,.set_baudrate = can_set_baud,.write = can_write};

static int32_t can_write(sm_bsp_can_t *_this,sm_bsp_can_mgs_t *mgs){
    /*User code*/
    (void) _this;
    (void) mgs;
    return 0;
}
static int32_t can_set_baud(sm_bsp_can_t *_this,uint32_t baud){
    /*User code*/
    (void) _this;
    (void) baud;
    return 0;
}
static int32_t can_open(sm_bsp_can_t *_this){
    /*User code*/
    (void) _this;
    return 0;
}
static int32_t can_close(sm_bsp_can_t *_this){
    /*User code*/
    (void) _this;
    return 0;
}
