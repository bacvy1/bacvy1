#include "sm_bsp_pwm.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    sm_bsp_pwm_t base;

    /* data */
}sm_bsp_pwm_impl_t;


sm_bsp_pwm_t *sm_bsp_pwm_init(sm_bsp_pwm_proc_t *_proc,void* _handle){
    sm_bsp_pwm_impl_t* parent = malloc(sizeof(sm_bsp_pwm_impl_t));

    parent->base.proc = _proc;
    parent->base.handle = _handle;

    return &parent->base;
}
void sm_bsp_pwm_deinit(sm_bsp_pwm_t *_this){
    sm_bsp_pwm_impl_t *parent = (sm_bsp_pwm_impl_t*)_this;
    if(_this->proc->close != NULL)
        _this->proc->close(_this);
    free(parent);
}
