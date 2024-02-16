/*
 * delay.c
 *
 *  Created on: Jul 10, 2023
 *      Author: Admin
 */


/*Include mcu platform*/

/*End include mcu platform*/

#include "sm_bsp_delay.h"
#include "hal_data.h"
#include "FreeRTOS.h"
#include "task.h"
void sm_bsp_delay_ms(uint32_t timems){
    /*User code*/
    vTaskDelay(pdMS_TO_TICKS(timems));
}
void sm_bsp_delay_us(uint32_t timeus){
    /*User code*/
    R_BSP_SoftwareDelay(timeus, BSP_DELAY_UNITS_MICROSECONDS);
}
uint32_t get_tick_count(){
    /*User code*/
    return 0;
}
