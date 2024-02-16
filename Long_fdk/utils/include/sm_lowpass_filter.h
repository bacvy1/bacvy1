/*
 * sm_lowpass_filter.h
 *
 *  Created on: Sep 7, 2023
 *      Author: Admin
 */

#ifndef SM_LOWPASS_FILTER_H_
#define SM_LOWPASS_FILTER_H_

#include "stdint.h"


typedef struct sm_lowpass_f sm_lowpass_f_t;

struct sm_lowpass_f{
	float output;
	float epow;
};

void sm_lowpass_init(sm_lowpass_f_t *_this,float _cutOffFrequency, float _freq_sample_rate);

float sm_lowpass_update(sm_lowpass_f_t *_this,float _input);

static inline float sm_lowpass_get_update(sm_lowpass_f_t *_this){
	return _this->output;
}

#endif /* SM_LOWPASS_FILTER_H_ */
