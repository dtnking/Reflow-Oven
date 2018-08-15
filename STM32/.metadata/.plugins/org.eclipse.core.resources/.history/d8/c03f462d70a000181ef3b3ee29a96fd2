#ifndef _ANGLEFIRING_H
#define _ANGLEFIRING_H
#include "stdint.h"
extern uint16_t DMA_Buffer1[16] ;

#define MIN_POS_TIME		6
#define MIN_NEG_TIME		56
#define MAX_POS_TIME		44
#define MAX_NEG_TIME		94
#define DEFAULT_PWIDTH		2
#define COMPENSATE_DELAY 	4
void convertFiringPercentageToTimes(float pulse,int *negativeHalf, int *positiveHalf);
void getFiringTimesAndCopyIntoBuffer(int *negativeHalf, int *positiveHalf);
#endif // _ANGLEFIRING_H
