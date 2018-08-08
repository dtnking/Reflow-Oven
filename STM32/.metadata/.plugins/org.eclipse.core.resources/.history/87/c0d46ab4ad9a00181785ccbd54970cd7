#include "angleFiring.h"

uint16_t DMA_Buffer1[16] ;
void calculationForPulseWidth(float pulse,int *negativeHalf, int *positiveHalf)
{
//	if(pulse==0)
//		pulse=1;
	int pulseWidth = (int)(100-((pulse / 100) * 50));
	*negativeHalf = (int)pulseWidth;
	*positiveHalf = (int)pulseWidth-50;
}

void replicateData(int *negativeHalf, int *positiveHalf)
{
	static int x=0;
	int y=0,secNegPulse,secPosPulse;

	//Compute for the HI to LO pulse of the OC
	if(*negativeHalf >=98){
		if(*negativeHalf == 100)
			*negativeHalf = 500;
		else
			secNegPulse=100;
	}
	else
		secNegPulse=*negativeHalf+2;

	if(*positiveHalf >=48){
		if(*positiveHalf == 50)
			*positiveHalf = 500;
		else
			secPosPulse=50;
	}
	else
		secPosPulse = *positiveHalf+2;
	//End of computation

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
