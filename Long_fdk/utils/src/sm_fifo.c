/*
 * cfifo.c
 *
 *  Created on: Jul 22, 2022
 *      Author: Minh Nhan
 */



#include <sm_fifo.h>
#include <assert.h>
#include <sm_bsp_delay.h>

#if NO_RTOS

bool sm_fifo_push_irq(sm_fifo_handle_t *p_fifo, void *item){

    //    while (p_fifo->lock)
    //    {
    ////        sm_bsp_delay_ms (1);
    //    }

        p_fifo->lock = true;
        unsigned int next = (unsigned int) (p_fifo->head + 1) % p_fifo->length;
        if (next != p_fifo->tail) {
    //        p_fifo->buff[p_fifo->head] = c;
            memcpy((p_fifo->buff+p_fifo->head*p_fifo->size),item,p_fifo->size);
            p_fifo->head = next;
            p_fifo->count += 1;
            p_fifo->lock = false;
            return true;
        }
        p_fifo->lock = false;
        //printf("fifo push false\r\n");
        return false;
}
bool sm_fifo_pop_irq(sm_fifo_handle_t *p_fifo, void *item){
    //    while (p_fifo->lock)
    //    {
    ////        sm_bsp_delay_ms (1);
    //    }

        p_fifo->lock = true;

        if (p_fifo->head != p_fifo->tail) {
            // data[0] = p_fifo->buff[p_fifo->tail];
            memcpy(item,(p_fifo->buff+p_fifo->tail*p_fifo->size),p_fifo->size);
            p_fifo->tail = (unsigned int) (p_fifo->tail + 1) % p_fifo->length;
            p_fifo->count -= 1;
            p_fifo->lock = false;
            return true;
        }
        p_fifo->lock = false;
        //printf("fifo pop false\r\n");
        return false;
}

void sm_fifo_init(sm_fifo_handle_t *p_fifo,size_t length,size_t size){

    if(p_fifo == NULL){
        p_fifo = (fifo_handle_t*)malloc(sizeof(fifo_handle_t));
    }
    assert(p_fifo != NULL);
    p_fifo->length = length+1;
    p_fifo->size = size;
    p_fifo->count = 0;
    p_fifo->head = -1;
    p_fifo->tail = -1;
    p_fifo->buff = calloc(p_fifo->length,p_fifo->size);
    p_fifo->lock = false;
    if(p_fifo->buff == NULL){
    	printf("fifo init false\r\n");
    	return;
    }
}
void sm_fifo_deinit(sm_fifo_handle_t *p_fifo){
	p_fifo->count = 0;
	p_fifo->head = 0;
	p_fifo->tail = 0;
	p_fifo->length = 0;
	free(p_fifo->buff);
	if(p_fifo->buff != NULL){
		//printf("deinit false\r\n");
	}
}
bool sm_fifo_push(sm_fifo_handle_t *p_fifo,void *item){

//    while (p_fifo->lock)
//    {
////        sm_bsp_delay_ms (1);
//    }

    p_fifo->lock = true;
    unsigned int next = (unsigned int) (p_fifo->head + 1) % p_fifo->length;
    if (next != p_fifo->tail) {
//        p_fifo->buff[p_fifo->head] = c;
        memcpy((p_fifo->buff+p_fifo->head*p_fifo->size),item,p_fifo->size);
        p_fifo->head = next;
        p_fifo->count += 1;
        p_fifo->lock = false;
        return true;
    }
    p_fifo->lock = false;
    //printf("fifo push false\r\n");
    return false;
}
bool sm_fifo_pop(sm_fifo_handle_t *p_fifo,void *item){

//    while (p_fifo->lock)
//    {
////        sm_bsp_delay_ms (1);
//    }

    p_fifo->lock = true;

	if (p_fifo->head != p_fifo->tail) {
		// data[0] = p_fifo->buff[p_fifo->tail];
        memcpy(item,(p_fifo->buff+p_fifo->tail*p_fifo->size),p_fifo->size);
		p_fifo->tail = (unsigned int) (p_fifo->tail + 1) % p_fifo->length;
		p_fifo->count -= 1;
        p_fifo->lock = false;
		return true;
	}
    p_fifo->lock = false;
	//printf("fifo pop false\r\n");
	return false;
}
unsigned int sm_fifo_get_num_item(sm_fifo_handle_t *p_fifo){
	return p_fifo->count;
}
#else
#include "FreeRTOS.h"
#include "queue.h"

sm_fifo_handle_t *sm_fifo_new_(size_t length,size_t size){
	sm_fifo_handle_t *_this = NULL;

	sm_fifo_init(_this,length,size);

	return _this;

}

void sm_fifo_init(sm_fifo_handle_t *p_fifo, size_t length, size_t size)
{
    assert(p_fifo != NULL);

    uint8_t *area = malloc (length * size);

    p_fifo->queue = xQueueCreateStatic(length, size, area, &p_fifo->static_queue);
}
void sm_fifo_deinit(sm_fifo_handle_t *p_fifo)
{
    (void) p_fifo;
}
bool sm_fifo_push(sm_fifo_handle_t *p_fifo, void *item)
{
    xQueueSend(p_fifo->queue, item, 10);
    return true;
}
bool sm_fifo_pop(sm_fifo_handle_t *p_fifo, void *item)
{
    if (xQueueReceive (p_fifo->queue, item, 1) == pdPASS)
    {
        return true;
    }
    return false;
}
unsigned int sm_fifo_get_num_item(sm_fifo_handle_t *p_fifo)
{
    return 1;
}
bool sm_fifo_push_irq(sm_fifo_handle_t *p_fifo, void *item)
{
    BaseType_t mask;
    xQueueSendFromISR(p_fifo->queue, item, &mask);
    return true;
}
bool sm_fifo_pop_irq(sm_fifo_handle_t *p_fifo, void *item)
{
    BaseType_t mask;
    xQueueReceiveFromISR (p_fifo->queue, item, &mask);
    return true;
}
bool sm_fifo_peek(sm_fifo_handle_t* p_fifo, void* item){
	if(xQueuePeek(p_fifo->queue, item, 1) == pdPASS)
	{
		return true;
	}
	return false;
}
#endif
