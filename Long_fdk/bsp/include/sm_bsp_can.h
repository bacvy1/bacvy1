/*
 * sp_bsp_can.h
 *
 *  Created on: Jul 5, 2023
 *      Author: Admin
 */

#ifndef BSP_INCLUDE_SM_BSP_CAN_H_
#define BSP_INCLUDE_SM_BSP_CAN_H_

#include <sm_fifo.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct sm_bsp_can sm_bsp_can_t;

typedef struct sm_bsp_can_mgs sm_bsp_can_mgs_t;

typedef void (*func_can_rx_callback)(sm_bsp_can_t *_this, sm_bsp_can_mgs_t *_mgs);

/**
 * @struct sm_bsp_can_mgs
 * @brief can message format
 *
 */
struct sm_bsp_can_mgs
{
    /* data */
    uint32_t id;
    uint8_t data[8];
    uint16_t length;
};

/**
 * @struct  sm_bsp_can_proc
 * @brief   function can pointer
 *
 */
typedef struct sm_bsp_can_proc
{
    /* data */
    int32_t (*write)(sm_bsp_can_t *_this, sm_bsp_can_mgs_t *_mgs);
    int32_t (*set_baudrate)(sm_bsp_can_t *_this, uint32_t _baudrate);
    int32_t (*open)(sm_bsp_can_t *_this);
    int32_t (*close)(sm_bsp_can_t *_this);
}sm_bsp_can_proc_t;

/**
 * @struct sm_bsp_can
 * @brief BSP CAN's driver
 *
 */
struct sm_bsp_can 
{
    /* data */
    const sm_bsp_can_proc_t *proc;
    void* handle;
};
/**
 * @fn sm_bsp_can_t sm_bsp_can_init*(sm_bsp_can_proc_t*, void*)
 * @brief init BSP CAN's driver
 *
 * @param m_proc CAN's function
 * @param handle MCU's CAN driver
 * @return CAN's driver pointer
 */
sm_bsp_can_t* sm_bsp_can_init(sm_bsp_can_proc_t *_proc, void *_handle);
/**
 * @fn void sm_bsp_can_deinit(sm_bsp_can_t*)
 * @brief clear BSP CAN's driver
 *
 * @param _this BSP CAN's driver
 */
void sm_bsp_can_deinit(sm_bsp_can_t *_this);
/**
 * @fn int32_t sm_bsp_can_write(sm_bsp_can_t*, sm_bsp_can_mgs_t*)
 * @brief Write CAN Message
 *
 * @param _this
 * @param mgs message
 * @return 0: success | -1 : false
 */
int32_t sm_bsp_can_write(sm_bsp_can_t *_this, sm_bsp_can_mgs_t *_mgs);
/**
 * @fn int32_t sm_bsp_can_read(sm_bsp_can_t*, sm_bsp_can_mgs_t*)
 * @brief Read CAN message
 *
 * @param _this
 * @param mgs
 * @return 0: success | -1 : false
 */
int32_t sm_bsp_can_read(sm_bsp_can_t *_this, sm_bsp_can_mgs_t *_mgs);
/**
 * @fn int32_t sm_bsp_can_set_baudrate(sm_bsp_can_t*, uint32_t)
 * @brief set CAN's baudrate
 *
 * @param _this
 * @param baudrate
 * @return 0: success | -1 : false
 */
int32_t sm_bsp_can_set_baudrate(sm_bsp_can_t *_this, uint32_t _baudrate);
/**
 * @fn int32_t sm_bsp_can_open(sm_bsp_can_t*)
 * @brief Open CAN's driver
 *
 * @param _this
 * @return 0: success | -1 : false
 */
int32_t sm_bsp_can_open(sm_bsp_can_t *_this);
/**
 * @fn int32_t sm_bsp_can_close(sm_bsp_can_t*)
 * @brief Close CAN's driver
 *
 * @param _this
 * @return 0: success | -1 : false
 */
int32_t sm_bsp_can_close(sm_bsp_can_t *_this);
/**
 * @fn void sm_bsp_can_rx_callback(sm_bsp_can_t*, sm_bsp_can_mgs_t*)
 * @brief CAN receive call back, calling on MCU can receiver callback
 *
 * @param _this
 * @param mgs
 */
void sm_bsp_can_rx_callback(sm_bsp_can_t *_this, sm_bsp_can_mgs_t *_mgs);
/**
 * @fn void sm_bsp_can_tx_callback(sm_bsp_can_t*)
 * @brief CAN transmit call back, calling on MCU can transmit callback
 *
 * @param _this
 */
void sm_bsp_can_tx_callback(sm_bsp_can_t *_this);
void sm_bsp_can_set_rx_callback(sm_bsp_can_t *_this, func_can_rx_callback callback);
#endif /* BSP_INCLUDE_SM_BSP_CAN_H_ */
