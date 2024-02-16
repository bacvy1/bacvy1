/*
 *
 *
 *  Created on: Jul 22, 2022
 *      Author: Minh Nhan
 */

#ifndef FIFO_H_
#define FIFO_H_


#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

#if NO_RTOS
#else
#include "FreeRTOS.h"
#include "queue.h"
#endif

typedef struct sm_fifo_handle sm_fifo_handle_t;

struct sm_fifo_handle{
#if NO_RTOS
    void *buff;
    size_t length;
    size_t size;
    volatile int head;
    volatile int tail;
    volatile unsigned int count;
    volatile bool lock;
#else
    StaticQueue_t static_queue;
    QueueHandle_t queue;
    size_t length;
    size_t size;

#endif


};


void sm_fifo_init(sm_fifo_handle_t *p_fifo,size_t length,size_t size);
sm_fifo_handle_t *sm_fifo_new_(size_t length,size_t size);
bool sm_fifo_push(sm_fifo_handle_t *p_fifo,void *item);
bool sm_fifo_pop(sm_fifo_handle_t *p_fifo,void *item);
bool sm_fifo_push_irq(sm_fifo_handle_t *p_fifo, void *item);
bool sm_fifo_pop_irq(sm_fifo_handle_t *p_fifo, void *item);
bool sm_fifo_peek(sm_fifo_handle_t* p_fifo, void* item);
void sm_fifo_deinit(sm_fifo_handle_t *p_fifo);
unsigned int sm_fifo_get_num_item(sm_fifo_handle_t *p_fifo);

#endif
