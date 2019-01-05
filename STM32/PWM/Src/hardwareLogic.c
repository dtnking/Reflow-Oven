/*
 * hardwareLogic.c
 *
 *  Created on: Dec 19, 2018
 *      Author: user
 */
#include "hardwareLogic.h"

void disableDmaAndOcFiring(void){
	int flag=0;
	hdma_tim4_ch1.Instance->CCR &= (~1);
	flag = checkTransferCompletedFlag();
//	while(flag == (1)){							//check TC flag
		HAL_TIM_OC_Stop(&htim4, TIM_CHANNEL_1);
//		flag =0;
//	}
}

int checkTransferCompletedFlag(void){
	int flag=0;
	flag = hdma_tim4_ch1.DmaBaseAddress->ISR & (1<<1);
	return flag>>1;
}

