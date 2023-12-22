/*
 * at_modem.h
 *
 *  Created on: Oct 7, 2020
 *      Author: quangnd
 */

#ifndef COMPONENT_AT_MODEM_AT_MODEM_H_
#define COMPONENT_AT_MODEM_AT_MODEM_H_

#include "stdint.h"
#include "string.h"
#include "stdbool.h"
#include "clock.h"

#define AT_CMD_TX_BUFFER_SIZE                           128
#define AT_DATA_TX_BUFFER_SIZE                          512

#define AT_CMD_BUILD_HEADER(buff)   *(buff)++='A';*(buff)++='T';*(buff)++='+'
#define AT_CMD_BUILD_TAIL(buff)     *(buff)++='\r';*(buff)++='\n';*(buff)++='\0'

typedef enum AT_MODEM_CMD_STATE_t{
	AT_CMD_ST_IDLE = 1,
	AT_CMD_ST_WAIT_FOR_RESPONSE,
	AT_CMD_ST_RESPONSE_FINISH,
	AT_CMD_ST_TIMEOUT,
	AT_CMD_ST_ERROR
}AT_MODEM_CMD_STATE;

typedef enum AT_MODEM_STATE_t{
    AT_MODEM_ST_INACTIVE = 0,
    AT_MODEM_ST_ACTIVE
}AT_MODEM_STATE;

typedef struct AT_Modem_t AT_Modem;
struct AT_Modem_t{
	AT_MODEM_CMD_STATE  cmd_state;
	AT_MODEM_STATE      state;
	Clock               timer;
	bool                is_echo;
	char*               rx_res_buffer;
    uint16_t            rx_res_index;
    uint16_t            rx_res_buffer_size;
	char*               rx_cmd_buffer;
    uint16_t            rx_cmd_index;
    uint16_t            rx_cmd_buffer_size;
	char*               rx_data_buff;
	uint16_t			rx_data_index;
	uint16_t 			rx_data_buff_size;
	char                tx_cmd[AT_CMD_TX_BUFFER_SIZE];
	char*               tx_data_buff;
	char* 				mqtt_data_buff;
	void                (*send)(const char* cmd);
};


void at_modem_init(AT_Modem* p_modem);
int8_t at_modem_send_cmd(AT_Modem* p_modem,const char* res,const uint32_t timeout);
int8_t at_modem_send_data(AT_Modem* p_modem,const char* res,const uint32_t timeout);
int32_t at_modem_search_response_string(const AT_Modem* p_modem,const char* str);
uint8_t at_modem_is_response_finish(const AT_Modem* const p_mdm);

static inline AT_MODEM_STATE at_modem_get_state(const AT_Modem* const p_mdm){
	return (p_mdm->state);
}

static inline void at_modem_set_state(AT_Modem* p_mdm,AT_MODEM_STATE state){
	p_mdm->state=state;
}

static inline void at_modem_set_cmd(AT_Modem* p_modem,const char* cmd){

	char* cmd_buff=(char*)p_modem->tx_cmd+3;
	while(*cmd){
		*cmd_buff=*cmd;
		cmd++;
		cmd_buff++;
	}

	AT_CMD_BUILD_TAIL(cmd_buff);
}

static inline void at_modem_flush_rx_res_buffer(AT_Modem* p_modem){
    memset(p_modem->rx_res_buffer, 0, p_modem->rx_res_buffer_size);
	p_modem->rx_res_index = 0;
}

static inline void at_modem_flush_rx_cmd_buffer(AT_Modem* p_modem){
    memset(p_modem->rx_cmd_buffer, 0, p_modem->rx_cmd_buffer_size);
    p_modem->rx_cmd_index = 0;
    p_modem->rx_data_buff = NULL;
}

#endif /* COMPONENT_AT_MODEM_AT_MODEM_H_ */
