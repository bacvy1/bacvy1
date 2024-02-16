/*
 * ringbuff.h
 *
 *  Created on: Jun 10, 2023
 *      Author: Admin
 */

#ifndef UTIL_FIFO_RINGBUFF_H_
#define UTIL_FIFO_RINGBUFF_H_


#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "string.h"

typedef struct RingBuffer_t RingBuffer;

struct RingBuffer_t{
    uint8_t *buff;
    size_t length;
    volatile int head;
    volatile int tail;
    volatile unsigned int count;
};


void ringbuff_init(RingBuffer *p_fifo,uint8_t* buff,size_t length);
bool ringbuff_push(RingBuffer *p_fifo,uint8_t item);
bool ringbuff_pop(RingBuffer *p_fifo,uint8_t *item);
void ringbuff_deinit(RingBuffer *p_fifo);
unsigned int ringbuff_get_num_item(RingBuffer *p_fifo);

#endif /* UTIL_FIFO_RINGBUFF_H_ */
