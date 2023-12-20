/*
 * iic.c
 *
 *  Created on: Jul 10, 2023
 *      Author: Admin
 */


/*include mcu platform*/

/*end*/

#include "sm_bsp_iic.h"

static    int32_t iic_open(sm_bsp_iic_t *_this);
static    int32_t iic_close(sm_bsp_iic_t *_this);
static    int32_t iic_write(sm_bsp_iic_t *_this,uint8_t *data,uint32_t len);
static    int32_t iic_read(sm_bsp_iic_t *_this,uint8_t *data,uint32_t len);
static    int32_t iic_abort(sm_bsp_iic_t *_this);
static    int32_t iic_set_addr(sm_bsp_iic_t *_this,uint8_t addr);

sm_bsp_iic_proc_t iic_func = {.abort = iic_abort,.open = iic_open,.close = iic_close,.read = iic_read,.set_addr = iic_set_addr ,.write = iic_write};

static int32_t iic_open(sm_bsp_iic_t *_this)
{
    /*User code*/
    return 0;
}
static int32_t iic_close(sm_bsp_iic_t *_this)
{
    /*User code*/
    return 0;
}
static int32_t iic_write(sm_bsp_iic_t *_this, uint8_t *data, uint32_t len)
{
    /*User code*/
    return 0;
}
static int32_t iic_read(sm_bsp_iic_t *_this, uint8_t *data, uint32_t len)
{
    /*User code*/
    return 0;
}
static int32_t iic_abort(sm_bsp_iic_t *_this)
{
    /*User code*/
    return 0;
}
static int32_t iic_set_addr(sm_bsp_iic_t *_this, uint8_t addr)
{
    /*User code*/
    return 0;
}
