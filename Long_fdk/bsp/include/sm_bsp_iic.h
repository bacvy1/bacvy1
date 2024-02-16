/*
 * sm_bsp_iic.h
 *
 *  Created on: Jul 5, 2023
 *      Author: Admin
 */

#ifndef BSP_INCLUDE_SM_BSP_IIC_H_
#define BSP_INCLUDE_SM_BSP_IIC_H_

#include <stdint.h>
#include <stdio.h>

typedef struct sm_bsp_iic sm_bsp_iic_t;
/**
 * @struct sm_bsp_iic_proc
 * @brief
 *
 */
typedef struct sm_bsp_iic_proc
{
    /* data */
    int32_t (*open)(sm_bsp_iic_t *_this);
    int32_t (*close)(sm_bsp_iic_t *_this);
    int32_t (*write)(sm_bsp_iic_t *_this, uint8_t *_data, uint32_t _len);
    int32_t (*read)(sm_bsp_iic_t *_this, uint8_t *_data, uint32_t _len);
    int32_t (*abort)(sm_bsp_iic_t *_this);
    int32_t (*set_addr)(sm_bsp_iic_t *_this, uint8_t _addr);
} sm_bsp_iic_proc_t;

/**
 * @struct sm_bsp_iic
 * @brief
 *
 */
struct sm_bsp_iic
{
    /* data */
    void *handle;
    const sm_bsp_iic_proc_t *proc;
    uint8_t addr;
};
/**
 * @fn sm_bsp_iic_t sm_bsp_iic_init*(sm_bsp_iic_proc_t*, void*)
 * @brief
 *
 * @param m_proc
 * @param handle
 * @return
 */
sm_bsp_iic_t* sm_bsp_iic_init(sm_bsp_iic_proc_t *_proc, void *_handle);
/**
 * @fn void sm_bsp_iic_deinit(sm_bsp_iic_t*)
 * @brief
 *
 * @param _this
 */
void sm_bsp_iic_deinit(sm_bsp_iic_t *_this);
/**
 * @fn int32_t sm_bsp_iic_open(sm_bsp_iic_t*)
 * @brief
 *
 * @param _this
 * @return
 */
static inline int32_t sm_bsp_iic_open(sm_bsp_iic_t *_this)
{
    return _this->proc->open (_this);
}
/**
 * @fn int32_t sm_bsp_iic_close(sm_bsp_iic_t*)
 * @brief
 *
 * @param _this
 * @return
 */
static inline int32_t sm_bsp_iic_close(sm_bsp_iic_t *_this)
{
    return _this->proc->close (_this);
}
/**
 * @fn int32_t sm_bsp_iic_write(sm_bsp_iic_t*, uint8_t*, uint32_t)
 * @brief
 *
 * @param _this
 * @param data
 * @param len
 * @return
 */
int32_t sm_bsp_iic_write(sm_bsp_iic_t *_this, uint8_t *_data, uint32_t _len);
/**
 * @fn int32_t sm_bsp_iic_read(sm_bsp_iic_t*, uint8_t*, uint32_t)
 * @brief
 *
 * @param _this
 * @param data
 * @param len
 * @return
 */
int32_t sm_bsp_iic_read(sm_bsp_iic_t *_this, uint8_t *_data, uint32_t _len);
/**
 * @fn int32_t sm_bsp_iic_abort(sm_bsp_iic_t*)
 * @brief
 *
 * @param _this
 * @return
 */
static inline int32_t sm_bsp_iic_abort(sm_bsp_iic_t *_this)
{
    return _this->proc->abort (_this);
}
/**
 * @fn int32_t sm_bsp_iic_set_addr(sm_bsp_iic_t*, uint8_t)
 * @brief
 *
 * @param _this
 * @param addr
 * @return
 */
static inline int32_t sm_bsp_iic_set_addr(sm_bsp_iic_t *_this, uint8_t _addr)
{
    _this->addr = _addr;
    return _this->proc->set_addr (_this, _addr);
}
int32_t sm_bsp_iic_callback(sm_bsp_iic_t *_this, uint8_t event);

#endif /* BSP_INCLUDE_SM_BSP_IIC_H_ */
