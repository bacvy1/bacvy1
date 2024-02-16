/*
 * sm_dft.h
 *
 *  Created on: Sep 7, 2023
 *      Author: Admin
 *
 *      Discrete Fourier Transform Algorithm
 *
 *
 */

#ifndef SM_DFT_H_
#define SM_DFT_H_

#include<stdio.h>
#include<math.h>
#define PI 3.14159265

typedef struct sm_dft_val sm_dft_val_t;

struct sm_dft_val{
    double *real;
    double *img;
    double *magnitude;
};

void sm_calculateDFT(sm_dft_val_t *dft,double *func/*Signal Value*/,size_t len /*Number Sample*/);
double sm_calculateFreq(sm_dft_val_t *dft,unsigned int len/*Number Sample*/,double Fs /*Frequency Sample Rate */);


/*
 *
 * Example
 *
 * */

/*#include "sm_dft.h"

#define MAX_SAMPLE 500

double sensor_val[MAX_SAMPLE];
double real[MAX_SAMPLE] = { 0 };
double img[MAX_SAMPLE] = { 0 };
double magnitude[MAX_SAMPLE] = { 0 };
int main(int argc, char **argv) {

	sm_dft_val_t dft;

	dft.img = img;
	dft.real = real;
	dft.magnitude = magnitude;
	sm_calculateDFT(&dft, sensor_val, MAX_SAMPLE);
	double freq = sm_calculateFreq(&dft, MAX_SAMPLE, 10000);
	printf("Freq : %f\n", freq);
	return 0;
}*/


#endif /* SM_DFT_H_ */
