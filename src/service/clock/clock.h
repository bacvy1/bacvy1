/*
 * clock.h
 *
 *  Created on: Feb 3, 2022
 *      Author: KhanhDQ
 */

#ifndef SERVICE_CLOCK_CLOCK_H_
#define SERVICE_CLOCK_CLOCK_H_

#include "stdint.h"
#include "stdbool.h"

typedef struct Clock_t Clock;
struct Clock_t{
    uint32_t    timeout_ms;
    bool        is_expired;
    bool        is_active;
};

void clock_active_timeout(Clock* p_clk, const uint32_t timeout);
void clock_reset_timeout(Clock* p_clk);
void clock_set_timeout(Clock* p_clk);

static inline void clock_process_timeout(Clock* p_clk){
    if(p_clk->is_active){

        p_clk->timeout_ms--;
        if(p_clk->timeout_ms == 0){

            p_clk->is_expired = true;
            p_clk->is_active = false;
        }
    }
}

static inline uint32_t clock_get_timestamp(Clock* p_clk){
    return p_clk->timeout_ms;
}

#endif /* SERVICE_CLOCK_CLOCK_H_ */
