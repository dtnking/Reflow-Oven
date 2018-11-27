#include "angleFiring.h"

uint16_t DMA_Buffer1[8];
DMA_HandleTypeDef hdma_tim4_ch1;


void convertFiringPercentageToTimes(float pulse,int *negativeHalf, int *positiveHalf)
{
	int pulseWidth = (int)(100-(pulse/2)); // To divide into positive and negative half cycle : divide by half
	*negativeHalf = (int)pulseWidth;
	*positiveHalf = (int)pulseWidth-50;
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

void getFiringTimesAndCopyIntoBuffer(int *negativeHalf, int *positiveHalf)
{
	static int x=0;
	int y=0,secNegPulse=0,secPosPulse=0;

	//Compute for the HI to LO pulse of the OC
	if(*negativeHalf >= 100 - MAX_MARGIN){
		if(*negativeHalf >= 100) {
//			HAL_DMA_Abort_IT(&hdma_tim4_ch1);

			HAL_TIM_OC_Stop(&htim4, TIM_CHANNEL_1);

// 			*negativeHalf = 500;
		}
		else{
			*negativeHalf = 100 - MAX_MARGIN;
			secNegPulse = *negativeHalf + DEFAULT_PWIDTH;
		}
	}
	else if(*negativeHalf <= 50 + MAX_MARGIN + COMPENSATE_DELAY){
		*negativeHalf = 50 + COMPENSATE_DELAY;
		secNegPulse = 50 + COMPENSATE_DELAY + MAX_MARGIN;
	}
	else
		secNegPulse = *negativeHalf + DEFAULT_PWIDTH;	//default pulse width

	if(*positiveHalf >= 50 - MAX_MARGIN){
		if(*positiveHalf >= 50){
			HAL_TIM_OC_Stop(&htim4, TIM_CHANNEL_1);
//			*positiveHalf = 500;			// The CNT will never reach this value, so it will never fire.
		}
		else{
			*positiveHalf = 50 - MAX_MARGIN;
			secPosPulse = *positiveHalf + DEFAULT_PWIDTH;
		}
	}
	else if(*positiveHalf  <= 0 + MAX_MARGIN + COMPENSATE_DELAY){
		*positiveHalf = 0 + COMPENSATE_DELAY;
		secPosPulse = 0 + COMPENSATE_DELAY + MAX_MARGIN;
	}
	else
		secPosPulse = *positiveHalf + DEFAULT_PWIDTH;
	//End of computation


	/*
	 * Write into the DMA buffer
	 */
	if(x==8)
		x=0;
	while(y!=4)
	{
		DMA_Buffer1[x]= *negativeHalf;
		DMA_Buffer1[x+1]= secNegPulse;
		DMA_Buffer1[x+2]= *positiveHalf;
		DMA_Buffer1[x+3]= secPosPulse;
		x+=4;
		y+=4;
	}
}
