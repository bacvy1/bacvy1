/*
 * sm_math.c
 *
 *  Created on: Sep 7, 2023
 *      Author: Admin
 */


#include "sm_math.h"


int sm_rand(int max, int min){
	return (rand() % (max - min + 1) + min);
}
