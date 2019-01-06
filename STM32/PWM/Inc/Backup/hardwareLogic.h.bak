/*
 * hardwareLogic.h
 *
 *  Created on: Dec 19, 2018
 *      Author: user
 */

#ifndef HARDWARELOGIC_H_
#define HARDWARELOGIC_H_

#define MAX_TICK_PER_CYCLE					100
#define	MAX_TICK_PER_HALF_CYCLE				50

#include "stm32f1xx_hal.h"

DMA_HandleTypeDef hdma_tim4_ch1;
TIM_HandleTypeDef htim4;


void disableDmaAndOcFiring(void);
int checkTransferCompletedFlag(void);

#endif /* HARDWARELOGIC_H_ */
