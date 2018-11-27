#ifndef _ANGLEFIRING_H
#define _ANGLEFIRING_H
#include "stdint.h"
#include "stm32f1xx_hal.h"
TIM_HandleTypeDef htim4;
extern uint16_t DMA_Buffer1[8] ;

//#define DEBUG_LOG
#define TIM4_CCR1_ADDRS ((uint32_t)0x40000834)
#define MAX_MARGIN			10
#define MIN_POS_TIME		4 + COMPENSATE_DELAY
#define MIN_NEG_TIME		54 + COMPENSATE_DELAY
#define MAX_POS_TIME		43 + COMPENSATE_DELAY
#define MAX_NEG_TIME		93 + COMPENSATE_DELAY
#define DEFAULT_PWIDTH		2
#define COMPENSATE_DELAY 	1
#define NON_BUFFERED		0
#define BUFFERED			1

void convertFiringPercentageToTimes(float pulse,int *negativeHalf, int *positiveHalf);
void getFiringTimesAndCopyIntoBuffer(int *negativeHalf, int *positiveHalf);
int getPulseWidth(void);
void compensateFiringTimes(int *negativeHalf, int *positiveHalf);
#endif // _ANGLEFIRING_H
