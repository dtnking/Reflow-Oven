#ifndef _ANGLEFIRING_H
#define _ANGLEFIRING_H
#include "stdint.h"
#include "stm32f1xx_hal.h"
extern uint16_t DMA_Buffer1[16] ;

#define MIN_POS_TIME		5
#define MIN_NEG_TIME		55
#define MAX_POS_TIME		42
#define MAX_NEG_TIME		92
#define DEFAULT_PWIDTH		2
#define COMPENSATE_DELAY 	0
#define NON_BUFFERED		0
#define BUFFERED			1

void convertFiringPercentageToTimes(float pulse,int *negativeHalf, int *positiveHalf);
void getFiringTimesAndCopyIntoBuffer(int *negativeHalf, int *positiveHalf);
int getPulseWidth(void);
#endif // _ANGLEFIRING_H
