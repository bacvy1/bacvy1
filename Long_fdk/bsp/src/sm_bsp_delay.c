#include "sm_bsp_delay.h"


#if RTOS
/**
 * @fn void sm_bsp_delay_ms(uint32_t)
 * @brief
 *
 * @param timems
 */
void sm_bsp_delay_ms(uint32_t timems){
    vTaskDelay(timems);
}
/**
 * @fn void sm_bsp_delay_us(uint32_t)
 * @brief
 *
 * @param timeus
 */
void sm_bsp_delay_us(uint32_t timeus){
    vTaskDelay(timeus);
}
/**
 * @fn uint32_t get_tick_count()
 * @brief
 *
 * @return
 */
uint32_t get_tick_count(){
    return 0;
}
#endif
