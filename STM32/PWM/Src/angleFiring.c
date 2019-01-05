#include "angleFiring.h"

uint16_t DMA_Buffer1[DMA_BUFFER_SIZE]={0};

void compensateFiringTimes(int *negativeHalf, int *positiveHalf){
	*negativeHalf = *negativeHalf + COMPENSATE_DELAY;
	*positiveHalf = *positiveHalf + COMPENSATE_DELAY;
}

int getPulseWidth(void){
	int pulseWidth;
	static int x=0;
	if(x==2)
		x=0;
	pulseWidth = DMA_Buffer1[x+1]-DMA_Buffer1[x];
	x+=2;
	return pulseWidth;
}

void computeFiringPercentageToTicks(int percentage,int *negativeHalf, int *positiveHalf,int *busyFlag){
	*busyFlag = 1;
	MEMORY_BARRIER;
	int ticks = (int)(MAX_TICK_PER_CYCLE-((MAX_TICK_PER_CYCLE/100)*(percentage/2))); 		// To divide into positive and negative half cycle : divide by half
	*negativeHalf = ticks;
	*positiveHalf = ticks-MAX_TICK_PER_HALF_CYCLE;
	compensateFiringTimes(negativeHalf,positiveHalf);
	MEMORY_BARRIER;													// Memory Barrier
	*busyFlag = 0;
}

void computeValueToPutIntoDmaBufferFromTicks(int *negativeHalf, int *positiveHalf,int *busyFlag){
	static int currNegativeHalf,currPositiveHalf,state=1;
	static int duplicateNumber = NUMBER_OF_DUPLICATION;
	int secNegPulse=0,secPosPulse=0;

	if(busyFlag==0){
		currNegativeHalf = *negativeHalf;
		currPositiveHalf = *positiveHalf;
	}
	computeFiringTimesValue(&currNegativeHalf,&currPositiveHalf,&secNegPulse,&secPosPulse,&state);
	dmaStateOperationDeterminant(&duplicateNumber,&state,&negativeHalf,&positiveHalf);
	replicateValueIntoDmaBuffer(&DMA_Buffer1,duplicateNumber,currNegativeHalf,secNegPulse,currPositiveHalf,secPosPulse,&state);
}

void dmaStateOperationDeterminant(int *duplicateNumber,int *state,int **negativeHalf,int **positiveHalf){
	if(*state==TURN_OFF){
		**negativeHalf=-1;
		**positiveHalf=-1;
	}

	else if(*state==FIRST_FIRING){
		*duplicateNumber = NUMBER_OF_DUPLICATION;
	}
	else
		*duplicateNumber = NUMBER_OF_DUPLICATION -1;
}

int replicateValueIntoDmaBuffer(uint16_t *buffer,int duplicateNumber,int currNegativeHalf, int secNegPulse, int currPositiveHalf, int secPosPulse,int *state){
	static int index = 0;
	int y = 0;
	if(*state == TURN_OFF){
		*state = NORMAL_OPERATION;	// switch the state back to normal operation, so that it won't stuck at this loop.
		return 0;					// to prevent replicating non-necessary value into buffer
	}
	while(y != duplicateNumber){
		buffer[index]= currNegativeHalf;
		buffer[++index]= secNegPulse;
		buffer[++index]= currPositiveHalf;
		buffer[++index]= secPosPulse;
		index++;
		y+=1;
		if(index == DMA_BUFFER_SIZE)
			index = 0;
	}
	*state = NORMAL_OPERATION;
	return 1;
}

void computeFiringTimesValue(int *currNegativeHalf, int *currPositiveHalf, int *secNegPulse, int *secPosPulse,int *state){
	//Compute for the HI to LO pulse of the OC
	if(*currNegativeHalf >= MAX_TICK_PER_CYCLE - MAX_MARGIN && *currPositiveHalf >= MAX_TICK_PER_HALF_CYCLE - MAX_MARGIN){
		if(*currNegativeHalf >= MAX_TICK_PER_CYCLE && *currPositiveHalf >= MAX_TICK_PER_HALF_CYCLE) {
			*state=TURN_OFF;
		}
		else{
			*currNegativeHalf = MAX_TICK_PER_CYCLE - MAX_MARGIN;
			*secNegPulse = *currNegativeHalf + DEFAULT_PWIDTH;
			*currPositiveHalf = MAX_TICK_PER_HALF_CYCLE - MAX_MARGIN;
			*secPosPulse = *currPositiveHalf + DEFAULT_PWIDTH;
		}
	}
	else if(*currNegativeHalf <= MAX_TICK_PER_HALF_CYCLE + MAX_MARGIN + COMPENSATE_DELAY && *currPositiveHalf  <= 0 + MAX_MARGIN + COMPENSATE_DELAY){
		*currNegativeHalf = MAX_TICK_PER_HALF_CYCLE + COMPENSATE_DELAY;
		*secNegPulse = MAX_TICK_PER_HALF_CYCLE + COMPENSATE_DELAY + MAX_MARGIN;
		*currPositiveHalf = 0 + COMPENSATE_DELAY;
		*secPosPulse = 0 + COMPENSATE_DELAY + MAX_MARGIN;
	}
	else{
		*secNegPulse = *currNegativeHalf + DEFAULT_PWIDTH;	//default pulse width
		*secPosPulse = *currPositiveHalf + DEFAULT_PWIDTH;
	}
}
