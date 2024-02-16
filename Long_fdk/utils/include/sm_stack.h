/*
 * sm_stack.h
 *
 *  Created on: Jul 17, 2023
 *      Author: Admin
 */

#ifndef UTILS_SM_STACK_H_
#define UTILS_SM_STACK_H_

#include <stdint.h>
#include <stdio.h>

typedef struct sm_stack sm_stack_t;

struct sm_stack{
    void *item;
    size_t item_size;
    uint32_t length;
    int32_t count;
};

void sm_stack_init(sm_stack_t *p_stack,uint32_t length,size_t item_size);
int32_t sm_stack_push(sm_stack_t *p_stack,void* item);
int32_t sm_stack_pop(sm_stack_t *p_stack,void* item);
int32_t sm_stack_deinit(sm_stack_t *p_stack);
#endif /* UTILS_SM_STACK_H_ */
