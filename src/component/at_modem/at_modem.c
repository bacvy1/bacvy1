/*
 * at_modem.c
 *
 *  Created on: Oct 7, 2020
 *      Author: quangnd
 */
#include "at_modem.h"
#include "string.h"
#include "string_util.h"
#include "FreeRTOS.h"
#include "task.h"
void at_modem_init(AT_Modem* p_modem){
    p_modem->is_echo = false;
	char* buff = &p_modem->tx_cmd[0];
	AT_CMD_BUILD_HEADER(buff);
	at_modem_set_state(p_modem, AT_MODEM_ST_INACTIVE);
}

uint8_t at_modem_is_response_finish(const AT_Modem* const p_mdm){
	if(p_mdm->rx_res_index<4) return (0);
	if(p_mdm->rx_res_buffer[p_mdm->rx_res_index-1]!='\n') return (0);
	if(p_mdm->rx_res_buffer[p_mdm->rx_res_index-2]!='\r') return (0);
	return (1);
}

int32_t at_modem_search_response_string(const AT_Modem* p_modem,const char* str){
    volatile uint16_t rx_index = p_modem->rx_res_index;
	uint16_t len = (uint16_t)strlen(str);
	if(rx_index == 0) return -1;
	if(rx_index < len) return (-1);
	for(int i=0;i<p_modem->rx_res_index;i++){
		if(str_contain((char*)(p_modem->rx_res_buffer+i),str)) return (i);
	}
	return (-1);
}

/* send command and wait for specific response */
int8_t at_modem_send_cmd(AT_Modem* p_modem,const char* res,const uint32_t timeout){

    clock_active_timeout(&p_modem->timer, timeout);
    int8_t rc=-1;

	at_modem_flush_rx_res_buffer(p_modem);
	p_modem->send((char*)p_modem->tx_cmd);

//	while ((at_modem_search_response_string(p_modem, res) < 0) && (!p_modem->timer.is_expired)){
//	    //at_modem_read_all(p_modem);
//	}
	while(1){
		if(strstr(p_modem->rx_res_buffer,res) != NULL) break;
		if(p_modem->timer.is_expired){
		    break;
		}
		vTaskDelay(1);
	}
	if(p_modem->timer.is_expired){
	    rc = -1;
	} else{
		rc = 0;
	}
    clock_reset_timeout(&p_modem->timer);
    //at_modem_flush_rx_res_buffer(p_modem);

	return (rc);
}

int8_t at_modem_send_data(AT_Modem* p_modem,const char* res,const uint32_t timeout){

    clock_active_timeout(&p_modem->timer, timeout);
    int8_t rc=-1;

    at_modem_flush_rx_res_buffer(p_modem);
    p_modem->send((char*)p_modem->tx_data_buff);

    while ((at_modem_search_response_string(p_modem, res) < 0) && (!p_modem->timer.is_expired)){
        //at_modem_read_all(p_modem);
    }
    if(p_modem->timer.is_expired){
        rc = -1;
    } else{
        rc = 0;
    }
    clock_reset_timeout(&p_modem->timer);

    at_modem_flush_rx_res_buffer(p_modem);


    return (rc);
}


