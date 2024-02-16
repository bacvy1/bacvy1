/*
 * clock.c
 *
 *  Created on: Feb 3, 2022
 *      Author: KhanhDQ
 */

#include "clock.h"

void clock_active_timeout(Clock* p_clk, const uint32_t timeout){
    p_clk->timeout_ms = timeout;
    p_clk->is_active = true;
    p_clk->is_expired = false;
}

void clock_reset_timeout(Clock* p_clk){
    p_clk->timeout_ms = 0;
    p_clk->is_active = false;
    p_clk->is_expired = false;
}

void clock_set_timeout(Clock* p_clk){
    p_clk->is_expired = true;
    p_clk->is_active = false;
}
