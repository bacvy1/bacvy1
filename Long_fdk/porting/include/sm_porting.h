/*
 * sm_porting.h
 *
 *  Created on: Jul 10, 2023
 *      Author: Admin
 */

#ifndef PORTING_INCLUDE_SM_PORTING_H_
#define PORTING_INCLUDE_SM_PORTING_H_

#include "sm_bsp_adc.h"
#include "sm_bsp_can.h"
#include "sm_bsp_delay.h"
#include "sm_bsp_flash.h"
#include "sm_bsp_iic.h"
#include "sm_bsp_io.h"
#include "sm_bsp_pwm.h"
#include "sm_bsp_spi.h"
#include "sm_bsp_timer.h"
#include "sm_bsp_uart.h"

extern sm_bsp_adc_proc_t adc_func;
extern sm_bsp_can_proc_t can_func;
extern sm_bsp_flash_proc_t flash_func;
extern sm_bsp_io_proc_t io_func;
extern sm_bsp_iic_proc_t iic_func;
extern sm_bsp_pwm_proc_t pwm_func;
extern sm_bsp_spi_proc_t spi_func;
extern sm_bsp_timer_proc_t timer_func;
extern sm_bsp_uart_proc_t uart_func;
extern sm_bsp_iwdg_proc_t iwdg_fun;

#endif /* PORTING_INCLUDE_SM_PORTING_H_ */
