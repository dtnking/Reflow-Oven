#ifndef _ANGLEFIRING_H
#define _ANGLEFIRING_H
#include "stdint.h"


//#define DEBUG_LOG
#define MEMORY_BARRIER			0
//#define MEMORY_BARRIER						asm volatile("dmb" ::: "memory");														// Memory Barrier to ensure busy=1 is performed first.
#define TIM4_CCR1_ADDRS 					((uint32_t)0x40000834)
#define MAX_MARGIN							5
#define MIN_POS_TIME						4 + COMPENSATE_DELAY
#define MIN_NEG_TIME						54 + COMPENSATE_DELAY
#define MAX_POS_TIME						43 + COMPENSATE_DELAY
#define MAX_NEG_TIME						93 + COMPENSATE_DELAY
#define DEFAULT_PWIDTH						2
#define COMPENSATE_DELAY 					0

#define NUMBER_OF_DATA						2
#define NUMBER_OF_DUPLICATION				2
#define DMA_BUFFER_SIZE						(4 * 2 * NUMBER_OF_DATA * NUMBER_OF_DUPLICATION)
#define DMA_BUFFER_MAX_SIZE					48

#define NORMAL_OPERATION					0
#define FIRST_FIRING						1
#define TURN_OFF							-1

#define MAX_TICK_PER_CYCLE					100
#define	MAX_TICK_PER_HALF_CYCLE				50
#define NON_BUFFERED						0
#define BUFFERED							1

extern uint16_t DMA_Buffer1[DMA_BUFFER_SIZE];
void computeValueToPutIntoDmaBufferFromTicks(int *negativeHalf, int *positiveHalf,int *busyFlag);
void computeFiringPercentageToTicks(int percentage,int *negativeHalf, int *positiveHalf,int *busyFlag);
void computeFiringTimesValue(int *currNegativeHalf, int *currPositiveHalf, int *secNegPulse, int *secPosPulse,int *state);
void dmaStateOperationDeterminant(int *duplicateNumber,int *state,int **negativeHalf,int **positiveHalf);
int replicateValueIntoDmaBuffer(uint16_t *buffer,int duplicateNumber,int currNegativeHalf, int secNegPulse, int currPositiveHalf, int secPosPulse,int *state);
int getPulseWidth(void);
void compensateFiringTimes(int *negativeHalf, int *positiveHalf);
#endif // _ANGLEFIRING_H
