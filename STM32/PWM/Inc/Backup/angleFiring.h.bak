#ifndef _ANGLEFIRING_H
#define _ANGLEFIRING_H
#include "stdint.h"
#include "hardwareLogic.h"

//#define DEBUG_LOG
#define TIM4_CCR1_ADDRS 					((uint32_t)0x40000834)
#define MAX_MARGIN							5
#define MIN_POS_TIME						4 + COMPENSATE_DELAY
#define MIN_NEG_TIME						54 + COMPENSATE_DELAY
#define MAX_POS_TIME						43 + COMPENSATE_DELAY
#define MAX_NEG_TIME						93 + COMPENSATE_DELAY
#define DEFAULT_PWIDTH						2
#define COMPENSATE_DELAY 					0

#define NUMBER_OF_DATA						2
#define NUMBER_OF_DUPLICATION				3
#define DMA_BUFFER_SIZE						(4 * NUMBER_OF_DATA * NUMBER_OF_DUPLICATION)
#define DMA_BUFFER_MAX_SIZE					48

#define NORMAL_OPERATION					0
#define FIRST_FIRING						1
#define TURN_OFF							-1

#define MAX_TICK_PER_CYCLE					100
#define	MAX_TICK_PER_HALF_CYCLE				50
#define NON_BUFFERED						0
#define BUFFERED							1

extern uint16_t DMA_Buffer1[DMA_BUFFER_SIZE] ;
void computeFiringPercentageToTicks(int percentage,int *negativeHalf, int *positiveHalf,int *busyFlag);
int computeValueToPutIntoDmaBufferFromTicks(int *negativeHalf, int *positiveHalf,int *busyFlag);
int getPulseWidth(void);
void compensateFiringTimes(int *negativeHalf, int *positiveHalf);
#endif // _ANGLEFIRING_H
