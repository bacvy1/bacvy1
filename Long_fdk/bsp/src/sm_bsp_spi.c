#include "sm_bsp_spi.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    /* data */
    sm_bsp_spi_t base;
}sm_bsp_spi_impl_t;


sm_bsp_spi_t* sm_bsp_spi_init(sm_bsp_spi_proc_t *_proc,void *_handle){
    sm_bsp_spi_impl_t* parent = (sm_bsp_spi_impl_t*) malloc(sizeof(sm_bsp_spi_impl_t));
    parent->base.proc = _proc;
    parent->base.handle = _handle;
    return &parent->base;
}

void sm_bsp_spi_deinit(sm_bsp_spi_t* _this){
    sm_bsp_spi_impl_t* parent = ( sm_bsp_spi_impl_t*)_this;
    if(_this->proc->close != NULL)
        _this->proc->close(_this);
    free(parent);
}
