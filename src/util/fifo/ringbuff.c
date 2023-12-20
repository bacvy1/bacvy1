/*
 * ringbuff.c
 *
 *  Created on: Jun 10, 2023
 *      Author: Admin
 */


#include "ringbuff.h"


void ringbuff_init(RingBuffer *p_fifo,uint8_t* buff,size_t length){
    if(p_fifo == NULL){
        return;
    }

    p_fifo->length = length+1;
    p_fifo->count = 0;
    p_fifo->head = -1;
    p_fifo->tail = -1;
    p_fifo->buff = buff;

}
bool ringbuff_push(RingBuffer *p_fifo,uint8_t item){
    unsigned int next = (unsigned int) (p_fifo->head + 1) % p_fifo->length;
    if (next != p_fifo->tail) {
        p_fifo->buff[p_fifo->head] = item;
        p_fifo->head = next;
        p_fifo->count += 1;
        return true;
    }
    return false;
}
bool ringbuff_pop(RingBuffer *p_fifo,uint8_t *item){
	if (p_fifo->head != p_fifo->tail) {
		item[0] = p_fifo->buff[p_fifo->tail];
		p_fifo->tail = (unsigned int) (p_fifo->tail + 1) % p_fifo->length;
		p_fifo->count -= 1;
		return true;
	}
	return false;
}
void ringbuff_deinit(RingBuffer *p_fifo){
	p_fifo->count = 0;
	p_fifo->head = 0;
	p_fifo->tail = 0;
	p_fifo->length = 0;
	free(p_fifo->buff);
	if(p_fifo->buff != NULL){
		//printf("deinit false\r\n");
	}
}
unsigned int ringbuff_get_num_item(RingBuffer *p_fifo){
	return p_fifo->count;
}
