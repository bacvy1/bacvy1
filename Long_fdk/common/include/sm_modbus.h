/*
 * modbusRTU.h
 *
 *  Created on: Jul 8, 2023
 *      Author: Admin
 */

#ifndef COMMON_MODBUS_SM_MODBUS_H_
#define COMMON_MODBUS_SM_MODBUS_H_

#include "sm_bsp_uart.h"
#include "sm_bsp_io.h"
#include "sm_bsp_timer.h"
#include "sm_config.h"

#if USING_MODBUS
typedef enum{
    SM_MODBUS_RTU,
    SM_MODBUS_ASCII,
    SM_MODBUS_TCP
}sm_modbus_protocol_t;

typedef struct sm_modbus sm_modbus_t;

struct sm_modbus{
    sm_bsp_uart_t *uart;
    sm_bsp_io_t *io;
    sm_bsp_timer_t *timer;
    sm_modbus_protocol_t protocol;
    uint8_t addr;

    uint8_t *ucSDiscInBuf;
    uint8_t *ucSCoilBuf;
    uint16_t *usSRegInBuf;
    uint16_t *usSRegHoldBuf;

    uint16_t nregInput;
    uint16_t nregHolding;
    uint16_t nregDisc;
    uint16_t nregCoil;

};

/**
 * @brief
 * @param _this
 * @param addr
 * @param protocol
 */
void sm_modbus_init(sm_modbus_t *_this,uint8_t addr,sm_modbus_protocol_t protocol);

/**
 * @brief
 * @param _this
 */
void sm_modbus_process(sm_modbus_t *_this);
#endif
#endif /* COMMON_MODBUS_SM_MODBUS_H_ */
