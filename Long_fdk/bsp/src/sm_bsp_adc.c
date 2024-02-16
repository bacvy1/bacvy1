#include "sm_bsp_adc.h"
#include <stdlib.h>

typedef struct 
{
    /* data */
    sm_bsp_adc_t base;
    uint16_t *value;
    uint16_t *channel;
    void (*callback)(sm_bsp_adc_t *_this,uint16_t value);
}sm_bsp_adc_impl_t;


static void adc_callback(sm_bsp_adc_t *_this,uint16_t value);

sm_bsp_adc_t* sm_bsp_adc_init(sm_bsp_adc_proc_t *_proc, void *_handle, uint8_t _num_channel)
{

    sm_bsp_adc_impl_t* parent = malloc(sizeof(sm_bsp_adc_impl_t));

    parent->base.proc = _proc;
    parent->base.handle = _handle;
    parent->value = calloc (0, _num_channel);
    parent->channel = calloc (0, _num_channel);
    parent->callback = adc_callback;
    return &parent->base;
}

void sm_bsp_adc_deinit(sm_bsp_adc_t *_this){
    sm_bsp_adc_impl_t* parent = (sm_bsp_adc_impl_t*) _this;
    if(_this->proc->close != NULL)
        _this->proc->close(_this);
    free(parent);
}
static void adc_callback(sm_bsp_adc_t *_this,uint16_t _value){
    sm_bsp_adc_impl_t* parent = (sm_bsp_adc_impl_t*) _this;
    parent->value[0] = _value;
}

uint16_t sm_bsp_adc_read(sm_bsp_adc_t *_this, uint8_t _channel)
{
//    sm_bsp_adc_impl_t* parent = (sm_bsp_adc_impl_t*) _this;
    return _this->proc->read(_this,_channel);;
}
void sm_bsp_adc_callback(sm_bsp_adc_t *_this,uint16_t _value){
    sm_bsp_adc_impl_t* parent = (sm_bsp_adc_impl_t*) _this;
    parent->callback(_this,_value);
}
int32_t sm_bsp_adc_open(sm_bsp_adc_t *_this){
    return _this->proc->open(_this);
}
int32_t sm_bsp_adc_close(sm_bsp_adc_t *_this){
    return _this->proc->close(_this);
}
