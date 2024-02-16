#include "sm_bsp_flash.h"
#include <stdio.h>
#include <stdlib.h>

sm_bsp_flash_t *sm_bsp_flash_init(sm_bsp_flash_proc_t *_proc,void* _handle){

    sm_bsp_flash_t* _this = malloc(sizeof(sm_bsp_flash_t));

    _this->handle = _handle;
    _this->proc = _proc;
    return _this;

}
void sm_bsp_flash_deinit(sm_bsp_flash_t *_this){
    if(_this->proc->close != NULL)
        _this->proc->close(_this);
    free(_this);
}
