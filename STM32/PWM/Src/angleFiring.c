#include "angleFiring.h"

uint16_t DMA_Buffer1[16] ;


void convertFiringPercentageToTimes(float pulse,int *negativeHalf, int *positiveHalf)
{
	int pulseWidth = (int)(100-((pulse / 100) * 50));
	*negativeHalf = (int)pulseWidth;
	*positiveHalf = (int)pulseWidth-50;
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

void getFiringTimesAndCopyIntoBuffer(int *negativeHalf, int *positiveHalf)
{
	static int x=0;
	int y=0,secNegPulse=0,secPosPulse=0;

	//Compute for the HI to LO pulse of the OC
	if(*negativeHalf + COMPENSATE_DELAY >= MAX_NEG_TIME){
		if(*negativeHalf + COMPENSATE_DELAY >= 100)
			*negativeHalf = 500;
		else{
			*negativeHalf=MAX_NEG_TIME;
			secNegPulse=97;
		}

	}
	else if(*negativeHalf + COMPENSATE_DELAY <= MIN_NEG_TIME){
		*negativeHalf = 50;
		secNegPulse=MIN_NEG_TIME;
	}
	else
		secNegPulse = *negativeHalf + COMPENSATE_DELAY + DEFAULT_PWIDTH;	//default pulse width


	if(*positiveHalf+ COMPENSATE_DELAY >= MAX_POS_TIME){
		if(*positiveHalf + COMPENSATE_DELAY >= 50)
			*positiveHalf = 500;			// The CNT will never reach this value, so it will never fire.
		else{
			*positiveHalf = MAX_POS_TIME;
			secPosPulse=47;
		}
	}
	else if(*positiveHalf + COMPENSATE_DELAY <= MIN_POS_TIME){
		*positiveHalf = 0;
		secPosPulse= MIN_POS_TIME;
	}
	else
		secPosPulse = *positiveHalf+ COMPENSATE_DELAY + DEFAULT_PWIDTH;
	//End of computation


	/*
	 * Write into the DMA buffer
	 */
	if(x==8)
		x=0;
	while(y!=4)
	{
		DMA_Buffer1[x]= *negativeHalf + COMPENSATE_DELAY;
		DMA_Buffer1[x+1]= secNegPulse;
		DMA_Buffer1[x+2]= *positiveHalf + COMPENSATE_DELAY;
		DMA_Buffer1[x+3]= secPosPulse;
		x+=4;
		y+=4;
	}
}
