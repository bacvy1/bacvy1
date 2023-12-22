/*
 * l76lb_hw.h
 *
 *  Created on: Jan 2, 2022
 *      Author: Ha
 */

#ifndef BOARD_L76LB_HW_L76LB_HW_H_
#define BOARD_L76LB_HW_L76LB_HW_H_

#include "bsp_api.h"
#include "common_data.h"
#include "hal_data.h"

#include "stdint.h"

#define GPS_RESET_PIN           BSP_IO_PORT_02_PIN_00
#define GPS_RESET_SET_HIGH      R_IOPORT_PinWrite(&g_ioport_ctrl, GPS_RESET_PIN, IOPORT_CFG_PORT_OUTPUT_HIGH)
#define GPS_RESET_SET_LOW       R_IOPORT_PinWrite(&g_ioport_ctrl, GPS_RESET_PIN, IOPORT_CFG_PORT_OUTPUT_LOW)

typedef struct GPS_hw_t GPS_hw;
struct GPS_hw_t{
    uint32_t        baudrate;
    uint8_t         rx_data;
    uint8_t         tx_data;
    void        (*receive_handle)(GPS_hw*);
};

extern GPS_hw   gps_hw;

void gps_hw_init(void);
void gps_sends(const char* tx_buff);

#endif /* BOARD_L76LB_HW_L76LB_HW_H_ */
