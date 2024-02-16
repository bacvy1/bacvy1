/*
 * sm_bsp_flash.h
 *
 *  Created on: Jul 5, 2023
 *      Author: Admin
 */

#ifndef BSP_INCLUDE_SM_BSP_FLASH_H_
#define BSP_INCLUDE_SM_BSP_FLASH_H_

#include <stdint.h>
#include <stdio.h>
typedef struct sm_bsp_flash sm_bsp_flash_t;
/**
 * @struct sm_bsp_flash_proc
 * @brief
 *
 */
typedef struct sm_bsp_flash_proc
{
    /* data */
    int32_t (*write)(sm_bsp_flash_t *_this, uint32_t _addr, void *_data, size_t _size);
    int32_t (*read)(sm_bsp_flash_t *_this, uint32_t _addr, void *_data, size_t _size);
    int32_t (*erase)(sm_bsp_flash_t *_this, uint32_t _addr, size_t _size);
    int32_t (*open)(sm_bsp_flash_t *_this);
    int32_t (*close)(sm_bsp_flash_t *_this);
} sm_bsp_flash_proc_t;

/**
 * @struct sm_bsp_flash
 * @brief
 *
 */
struct sm_bsp_flash
{
    /* data */
    sm_bsp_flash_proc_t *proc;
    void *handle;
};
/**
 * @fn sm_bsp_flash_t sm_bsp_flash_init*(sm_bsp_flash_proc_t*, void*)
 * @brief
 *
 * @param m_proc
 * @param handle
 * @return
 */
sm_bsp_flash_t* sm_bsp_flash_init(sm_bsp_flash_proc_t *_proc, void *_handle);
/**
 * @fn void sm_bsp_flash_deinit(sm_bsp_flash_t*)
 * @brief
 *
 * @param _this
 */
void sm_bsp_flash_deinit(sm_bsp_flash_t *_this);
/**
 * @fn int32_t sm_bsp_flash_write(sm_bsp_flash_t*, uint32_t, void*, size_t)
 * @brief
 *
 * @param _this
 * @param addr
 * @param data
 * @param size
 * @return
 */
static inline int32_t sm_bsp_flash_write(sm_bsp_flash_t *_this, uint32_t _addr, void *_data, size_t _size)
{
    return _this->proc->write (_this, _addr, _data, _size);
}
/**
 * @fn int32_t sm_bsp_flash_read(sm_bsp_flash_t*, uint32_t, void*, size_t)
 * @brief
 *
 * @param _this
 * @param addr
 * @param data
 * @param size
 * @return
 */
static inline int32_t sm_bsp_flash_read(sm_bsp_flash_t *_this, uint32_t _addr, void *_data, size_t _size)
{
    return _this->proc->read (_this, _addr, _data, _size);
}
/**
 * @fn int32_t sm_bsp_flash_erase(sm_bsp_flash_t*, uint32_t, size_t)
 * @brief
 *
 * @param _this
 * @param addr
 * @param size
 * @return
 */
static inline int32_t sm_bsp_flash_erase(sm_bsp_flash_t *_this, uint32_t _addr, size_t _size)
{
    return _this->proc->erase (_this, _addr, _size);
}
/**
 * @fn int32_t sm_bsp_flash_open(sm_bsp_flash_t*)
 * @brief
 *
 * @param _this
 * @return
 */
static inline int32_t sm_bsp_flash_open(sm_bsp_flash_t *_this)
{
    return _this->proc->open (_this);
}
/**
 * @fn int32_t sm_bsp_flash_close(sm_bsp_flash_t*)
 * @brief
 *
 * @param _this
 * @return
 */
static inline int32_t sm_bsp_flash_close(sm_bsp_flash_t *_this)
{
    return _this->proc->close (_this);
}

#endif /* BSP_INCLUDE_SM_BSP_FLASH_H_ */
