#include "unity.h"
#include "angleFiring.h"

void setUp(void){}

void tearDown(void){}

void test_functionality_getPulseTimes(void)
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

// void test_replicateData(void)
// {
// 	int negativeHalf = 90;
// 	int positiveHalf = 40;
// 	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
// 	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
// 	TEST_ASSERT_EQUAL_INT(93, DMA_Buffer1[0]);
// 	TEST_ASSERT_EQUAL_INT(95, DMA_Buffer1[1]);
// 	TEST_ASSERT_EQUAL_INT(43, DMA_Buffer1[2]);
// 	TEST_ASSERT_EQUAL_INT(45, DMA_Buffer1[3]);
// 	TEST_ASSERT_EQUAL_INT(93, DMA_Buffer1[4]);
// 	TEST_ASSERT_EQUAL_INT(95, DMA_Buffer1[5]);
// 	TEST_ASSERT_EQUAL_INT(43, DMA_Buffer1[6]);
// 	TEST_ASSERT_EQUAL_INT(45, DMA_Buffer1[7]);
// }

/*
 *	When the pulse is smaller than the minimum value(positiveHalf = 6,negativeHalf = 56),
 *  the pulse width is the default pulse width(2)
 *
 */
void test_function_getPulseWidth_expected_equal_6(void){
	int negativeHalf = 50;
	int positiveHalf = 0;
	int pulseWidth;
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	pulseWidth = getPulseWidth();
	TEST_ASSERT_EQUAL_INT(6,pulseWidth);
	pulseWidth = getPulseWidth();
	TEST_ASSERT_EQUAL_INT(6,pulseWidth);
}

void test_function_getPulseWidth_expected_equal_2(void){
	int negativeHalf = 56;
	int positiveHalf = 6;
	int pulseWidth;
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	pulseWidth = getPulseWidth();
	TEST_ASSERT_EQUAL_INT(6,pulseWidth);
	pulseWidth = getPulseWidth();
	TEST_ASSERT_EQUAL_INT(6,pulseWidth);
}

void test_functionality_pulseWidth(void){
	static int negativeHalf = 50;
	static int positiveHalf = 0;
	int pulseWidth;
	static int y=7;
	for(int x=1;x<51;x++){
		getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
		if(x<8){
			negativeHalf += x;
			positiveHalf += x;
		}
		else{
			if(x==8)
				y=1;
			if(x>45){
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
		TEST_ASSERT_LESS_THAN_INT(7, pulseWidth);
		pulseWidth = getPulseWidth();
		printf("The firing times is %i and the pulse width is %i\n\n",positiveHalf,pulseWidth);
		TEST_ASSERT_LESS_THAN_INT(7, pulseWidth);
	}
}
