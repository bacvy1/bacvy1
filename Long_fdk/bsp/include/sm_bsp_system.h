/*
 * sm_sbp_system.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Admin
 */

#ifndef BSP_INCLUDE_SM_BSP_SYSTEM_H_
#define BSP_INCLUDE_SM_BSP_SYSTEM_H_

#include <stdint.h>


#define WEAK        __attribute__((weak))


void sm_bsp_reset() WEAK;
void sm_bsp_jump_addr(uint32_t addr) WEAK;

#endif /* BSP_INCLUDE_SM_BSP_SYSTEM_H_ */
