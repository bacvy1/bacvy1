/*
 * sm_bsp_iwdg.h
 *
 *  Created on: Jul 12, 2023
 *      Author: Admin
 */

#ifndef BSP_INCLUDE_SM_BSP_IWDG_H_
#define BSP_INCLUDE_SM_BSP_IWDG_H_

#include <stdint.h>
#include <stdio.h>


typedef struct sm_bsp_iwdg sm_bsp_iwdg_t;

typedef struct sm_bsp_iwdg_proc{
    int32_t (*open)(sm_bsp_iwdg_t *);
    int32_t (*close)(sm_bsp_iwdg_t *);
    int32_t (*reset)(sm_bsp_iwdg_t *);
}sm_bsp_iwdg_proc_t;

struct sm_bsp_iwdg{
    const sm_bsp_iwdg_proc_t *proc;
    void *handle;
};

sm_bsp_iwdg_t* sm_bsp_iwdg_init(sm_bsp_iwdg_proc_t *sm_proc, void* _handle);

static inline int32_t sm_bsp_iwdg_open(sm_bsp_iwdg_t *_this){
    return _this->proc->open(_this);
}
static inline int32_t sm_bsp_iwdg_close(sm_bsp_iwdg_t *_this){
    return _this->proc->close(_this);
}
static inline int32_t sm_bsp_iwdg_reset(sm_bsp_iwdg_t *_this){
    return _this->proc->reset(_this);
}

#endif /* BSP_INCLUDE_SM_BSP_IWDG_H_ */
