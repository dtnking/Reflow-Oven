#include "unity.h"
#include "angleFiring.h"

void setUp(void){}

void tearDown(void){}

/*
 *	Given a percentage, convert it to firing times(negativeHalf and positiveHalf).
 */
void test_functionality_convertFiringPercentageToTimes(void)
{
	int negativeHalf,positiveHalf;
  convertFiringPercentageToTimes(1,&negativeHalf,&positiveHalf);
 	TEST_ASSERT_EQUAL_INT(99,negativeHalf);
 	TEST_ASSERT_EQUAL_INT(49,positiveHalf);
  convertFiringPercentageToTimes(2,&negativeHalf,&positiveHalf);
 	TEST_ASSERT_EQUAL_INT(99,negativeHalf);
 	TEST_ASSERT_EQUAL_INT(49,positiveHalf);
  convertFiringPercentageToTimes(3,&negativeHalf,&positiveHalf);
 	TEST_ASSERT_EQUAL_INT(98,negativeHalf);
 	TEST_ASSERT_EQUAL_INT(48,positiveHalf);
  convertFiringPercentageToTimes(4,&negativeHalf,&positiveHalf);
 	TEST_ASSERT_EQUAL_INT(98,negativeHalf);
 	TEST_ASSERT_EQUAL_INT(48,positiveHalf);
	convertFiringPercentageToTimes(5,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(97,negativeHalf);
	TEST_ASSERT_EQUAL_INT(47,positiveHalf);
	convertFiringPercentageToTimes(99,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(50,negativeHalf);
	TEST_ASSERT_EQUAL_INT(50,negativeHalf);
}

/*
 *	If the firing Angle is at the middle, the pulseWidth is default( user Defined as 2)
 *
 * 				    	Buffer
 *   ________________________________________
 *	| 75 | 77 | 30 | 32 | 75 | 77 | 30 | 32 |
 *	|___ |___ |____|____|____|____|____|____|
 */
void test_dataCopyIntoBuffer_with_default_PulseWidth(void)
{
	int negativeHalf = 75;
	int positiveHalf = 30;
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(75, DMA_Buffer1[0]);
	TEST_ASSERT_EQUAL_INT(77, DMA_Buffer1[1]);
	TEST_ASSERT_EQUAL_INT(30, DMA_Buffer1[2]);
	TEST_ASSERT_EQUAL_INT(32, DMA_Buffer1[3]);
	TEST_ASSERT_EQUAL_INT(75, DMA_Buffer1[4]);
	TEST_ASSERT_EQUAL_INT(77, DMA_Buffer1[5]);
	TEST_ASSERT_EQUAL_INT(30, DMA_Buffer1[6]);
	TEST_ASSERT_EQUAL_INT(32, DMA_Buffer1[7]);
}

/*
 *	If the firing Angle is less than the minimum limit(negativeHalf = 55, positiveHalf = 5),
 *	the firing angle will change the value to (negativeHalf = 50-55, positiveHalf = 0-5)
 * 				    	Buffer
 *   ___________________________________
 *	| 50 | 55 | 0 | 5 | 50 | 55 | 0 | 5 |
 *	|___ |___ |___|___|____|___|___|____|
 */
void test_dataCopyIntoBuffer_with_minLimit_FiringAngle(void)
{
	int negativeHalf = 52;
	int positiveHalf = 2;
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(50, DMA_Buffer1[0]);
	TEST_ASSERT_EQUAL_INT(55, DMA_Buffer1[1]);
	TEST_ASSERT_EQUAL_INT(0, DMA_Buffer1[2]);
	TEST_ASSERT_EQUAL_INT(5, DMA_Buffer1[3]);
	TEST_ASSERT_EQUAL_INT(50, DMA_Buffer1[4]);
	TEST_ASSERT_EQUAL_INT(55, DMA_Buffer1[5]);
	TEST_ASSERT_EQUAL_INT(0, DMA_Buffer1[6]);
	TEST_ASSERT_EQUAL_INT(5, DMA_Buffer1[7]);
}

/*
 *	If the firing Angle is more than the maximum limit(negativeHalf = 92, positiveHalf = 42),
 *	the firing angle will change the value to (negativeHalf = 92-97, positiveHalf = 42-47)
 * 				    	Buffer
 *   ________________________________________
 *	| 92 | 97 | 42 | 47 | 92 | 97 | 42 | 47 |
 *	|___ |___ |____|____|____|____|____|____|
 */
void test_dataCopyIntoBuffer_with_maxLimit_FiringAngle(void)
{
	int negativeHalf = 93;
	int positiveHalf = 43;
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(92, DMA_Buffer1[0]);
	TEST_ASSERT_EQUAL_INT(97, DMA_Buffer1[1]);
	TEST_ASSERT_EQUAL_INT(42, DMA_Buffer1[2]);
	TEST_ASSERT_EQUAL_INT(47, DMA_Buffer1[3]);
	TEST_ASSERT_EQUAL_INT(92, DMA_Buffer1[4]);
	TEST_ASSERT_EQUAL_INT(97, DMA_Buffer1[5]);
	TEST_ASSERT_EQUAL_INT(42, DMA_Buffer1[6]);
	TEST_ASSERT_EQUAL_INT(47, DMA_Buffer1[7]);
}

/*
 *	When the pulse is smaller than the minimum value(positiveHalf = 6,negativeHalf = 56),
 *  the pulse width is 5.
 */
void test_function_getPulseWidth_MinLimit_expected_equal_5(void){
	int negativeHalf = 50;
	int positiveHalf = 0;
	int pulseWidth;
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	pulseWidth = getPulseWidth();
	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
	pulseWidth = getPulseWidth();
	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
}

/*
 *	When the pulse is greater than the maximum value(positiveHalf = 92,negativeHalf = 42),
 *  the pulse width is 5
 */
void test_function_getPulseWidth_MaxLimit_expected_equal_5(void){
	int negativeHalf = 94;
	int positiveHalf = 44;
	int pulseWidth;
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	pulseWidth = getPulseWidth();
	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
	pulseWidth = getPulseWidth();
	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
}

/*
 *	When the pulse is greater than the maximum value, and smaller than the minimum value
 *	the pulse Width is at the default = 2.
 */
void test_function_getPulseWidth_defaultPulseWidth_expected_equal_2(void){
	int negativeHalf = 56;
	int positiveHalf = 6;
	int pulseWidth;
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	pulseWidth = getPulseWidth();
	TEST_ASSERT_EQUAL_INT(2,pulseWidth);
	pulseWidth = getPulseWidth();
	TEST_ASSERT_EQUAL_INT(2,pulseWidth);
}

/*
 *	Given an initial value, run the test by increment the value(0-100).
 * 	So every possible value is being tested (100 tests).
 */
void test_functionality_pulseWidth(void){
	static int negativeHalf = 50;
	static int positiveHalf = 0;
	int pulseWidth;
	static int y=6;
	for(int x=1;x<51;x++){
		getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
		getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
		if(x<6){
			negativeHalf += x;
			positiveHalf += x;
		}
		else{
			if(x==7)
				y=1;

			if(x>42){
				negativeHalf = negativeHalf-44+x;
				positiveHalf = positiveHalf-44+x;
			}
			else{
				negativeHalf += y;
				positiveHalf += y;
			}
		}
		pulseWidth = getPulseWidth();
		printf("The firing times is %i and the pulse width is %i\n",negativeHalf,pulseWidth);
		TEST_ASSERT_LESS_THAN_INT(6, pulseWidth);
		pulseWidth = getPulseWidth();
		printf("The firing times is %i and the pulse width is %i\n\n",positiveHalf,pulseWidth);
		TEST_ASSERT_LESS_THAN_INT(6, pulseWidth);
	}
}
