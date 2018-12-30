#include "angleFiring.h"
uint16_t DMA_Buffer1[DMA_BUFFER_SIZE]={0};



void computeFiringPercentageToTicks(int percentage,int *negativeHalf, int *positiveHalf,int *busyFlag)
{
	*busyFlag = 1;
	asm volatile("dmb" ::: "memory");														// Memory Barrier to ensure busy=1 is performed first.
	int ticks = (int)(MAX_TICK_PER_CYCLE-((MAX_TICK_PER_CYCLE/100)*(percentage/2))); 		// To divide into positive and negative half cycle : divide by half
	*negativeHalf = ticks;
	*positiveHalf = ticks-MAX_TICK_PER_HALF_CYCLE;
	compensateFiringTimes(negativeHalf,positiveHalf);
	asm volatile("dmb" ::: "memory");														// Memory Barrier
	*busyFlag = 0;

}

void compensateFiringTimes(int *negativeHalf, int *positiveHalf)
{
	*negativeHalf = *negativeHalf + COMPENSATE_DELAY;
	*positiveHalf = *positiveHalf + COMPENSATE_DELAY;
}

int getPulseWidth(void)
{
	int pulseWidth;
	static int x=0;
	if(x==2)
		x=0;
	pulseWidth = DMA_Buffer1[x+1]-DMA_Buffer1[x];
	x+=2;
	return pulseWidth;
}


int computeValueToPutIntoDmaBufferFromTicks(int *negativeHalf, int *positiveHalf,int *busyFlag)
{
	static int index=0,currNegativeHalf,currPositiveHalf,state=1;
	static int duplicateNumber = NUMBER_OF_DUPLICATION;
	int y=0,secNegPulse=0,secPosPulse=0;

	if(busyFlag==0){
		currNegativeHalf = *negativeHalf;
		currPositiveHalf = *positiveHalf;
	}
	//Compute for the HI to LO pulse of the OC
	if(currNegativeHalf >= MAX_TICK_PER_CYCLE - MAX_MARGIN && currPositiveHalf >= MAX_TICK_PER_HALF_CYCLE - MAX_MARGIN){
		if(currNegativeHalf >= MAX_TICK_PER_CYCLE && currPositiveHalf >= MAX_TICK_PER_HALF_CYCLE) {
			state=TURN_OFF;
		}
		else{
			currNegativeHalf = MAX_TICK_PER_CYCLE - MAX_MARGIN;
			secNegPulse = currNegativeHalf + DEFAULT_PWIDTH;
			currPositiveHalf = MAX_TICK_PER_HALF_CYCLE - MAX_MARGIN;
			secPosPulse = currPositiveHalf + DEFAULT_PWIDTH;
		}
	}
	else if(currNegativeHalf <= MAX_TICK_PER_HALF_CYCLE + MAX_MARGIN + COMPENSATE_DELAY && currPositiveHalf  <= 0 + MAX_MARGIN + COMPENSATE_DELAY){
		currNegativeHalf = MAX_TICK_PER_HALF_CYCLE + COMPENSATE_DELAY;
		secNegPulse = MAX_TICK_PER_HALF_CYCLE + COMPENSATE_DELAY + MAX_MARGIN;
		currPositiveHalf = 0 + COMPENSATE_DELAY;
		secPosPulse = 0 + COMPENSATE_DELAY + MAX_MARGIN;
	}
	else{
		secNegPulse = currNegativeHalf + DEFAULT_PWIDTH;	//default pulse width
		secPosPulse = currPositiveHalf + DEFAULT_PWIDTH;
	}

	//End of computation


	/*
	 * Write into the DMA buffer
	 */
	if(index == DMA_BUFFER_MAX_SIZE)
		index = 0;

	if(state==TURN_OFF){
		state=NORMAL_OPERATION;
		*negativeHalf=-1;
		*positiveHalf=-1;
		return 0;
	}

	else if(state==FIRST_FIRING){
		duplicateNumber = NUMBER_OF_DUPLICATION;
	}
	else
		duplicateNumber = NUMBER_OF_DUPLICATION -1;

	while(y != duplicateNumber)
	{
		DMA_Buffer1[index]= currNegativeHalf;
		DMA_Buffer1[++index]= secNegPulse;
		DMA_Buffer1[++index]= currPositiveHalf;
		DMA_Buffer1[++index]= secPosPulse;
		index++;
		y+=1;
	}
	state=NORMAL_OPERATION;
	return index;
}
