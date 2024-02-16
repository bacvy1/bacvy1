/*
 * sm_bsp_delay.h
 *
 *  Created on: Jul 5, 2023
 *      Author: Admin
 */

#ifndef BSP_INCLUDE_SM_BSP_DELAY_H_
#define BSP_INCLUDE_SM_BSP_DELAY_H_

#include <stdint.h>
#include <sm_bsp_system.h>
#include <sm_config.h>

#if !RTOS

/**
 * @fn void sm_bsp_delay_ms(uint32_t)
 * @brief
 *
 * @param timems
 */
void sm_bsp_delay_ms(uint32_t _timems);
/**
 * @fn void sm_bsp_delay_us(uint32_t)
 * @brief
 *
 * @param timeus
 */
void sm_bsp_delay_us(uint32_t _timeus);
/**
 * @fn uint32_t get_tick_count()
 * @brief
 *
 * @return
 */
uint32_t get_tick_count() WEAK;

void sm_bsp_system_clock_config() WEAK;

#else
/**
 * @fn void sm_bsp_delay_ms(uint32_t)
 * @brief
 *
 * @param timems
 */
void sm_bsp_delay_ms(uint32_t timems);
/**
 * @fn void sm_bsp_delay_us(uint32_t)
 * @brief
 *
 * @param timeus
 */
void sm_bsp_delay_us(uint32_t timeus);
/**
 * @fn uint32_t get_tick_count()
 * @brief
 *
 * @return
 */
uint32_t get_tick_count();
#endif


#endif /* BSP_INCLUDE_SM_BSP_DELAY_H_ */
