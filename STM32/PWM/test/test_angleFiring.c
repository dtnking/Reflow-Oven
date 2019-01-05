#include "unity.h"
#include "angleFiring.h"


void setUp(void){
}

void tearDown(void){}

/*
 *	Given a percentage, convert it to firing times(negativeHalf and positiveHalf).
 */


void test_computeValueToPutIntoDmaBufferFromTicks_2(void)
{
	int i,y;
	int negativeHalf = 75;
	int positiveHalf = 30;
	int busyFlag = 0;
	computeValueToPutIntoDmaBufferFromTicks(&negativeHalf,&positiveHalf,&busyFlag);
	computeValueToPutIntoDmaBufferFromTicks(&negativeHalf,&positiveHalf,&busyFlag);
	computeValueToPutIntoDmaBufferFromTicks(&negativeHalf,&positiveHalf,&busyFlag);
	computeValueToPutIntoDmaBufferFromTicks(&negativeHalf,&positiveHalf,&busyFlag);
	negativeHalf = 80;
	positiveHalf = 20;
	computeValueToPutIntoDmaBufferFromTicks(&negativeHalf,&positiveHalf,&busyFlag);

	for(i=0;i<20;i++){
		TEST_ASSERT_EQUAL_INT(75, DMA_Buffer1[i]);
		TEST_ASSERT_EQUAL_INT(77, DMA_Buffer1[++i]);
		TEST_ASSERT_EQUAL_INT(30, DMA_Buffer1[++i]);
		TEST_ASSERT_EQUAL_INT(32, DMA_Buffer1[++i]);
	}
	computeValueToPutIntoDmaBufferFromTicks(&negativeHalf,&positiveHalf,&busyFlag);
	for(y=0;y<DMA_BUFFER_MAX_SIZE;y++){
		printf("DMA_Buffer1[%u] = %i\n",y,DMA_Buffer1[y]);
	}
	printf("\n\n",y,DMA_Buffer1[y]);
	for(y=0;y<3;y++){
		printf("DMA_Buffer1[%u] = %i\n",y,DMA_Buffer1[y]);
	}
	for(i=0;i<4;i++){
		TEST_ASSERT_EQUAL_INT(80, DMA_Buffer1[i]);
		TEST_ASSERT_EQUAL_INT(82, DMA_Buffer1[++i]);
		TEST_ASSERT_EQUAL_INT(20, DMA_Buffer1[++i]);
		TEST_ASSERT_EQUAL_INT(22, DMA_Buffer1[++i]);

	}
}



//
///*
// *	If the firing Angle is at the middle, the pulseWidth is default( user Defined as 2)
// *
// * 				    	Buffer
// *   ________________________________________
// *	| 75 | 77 | 30 | 32 | 75 | 77 | 30 | 32 |
// *	|___ |___ |____|____|____|____|____|____|
// */
//void test_dataCopyIntoBuffer_with_default_PulseWidth(void)
//{
//	int negativeHalf = 75;
//	int positiveHalf = 30;
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	TEST_ASSERT_EQUAL_INT(75, DMA_Buffer1[0]);
//	TEST_ASSERT_EQUAL_INT(77, DMA_Buffer1[1]);
//	TEST_ASSERT_EQUAL_INT(30, DMA_Buffer1[2]);
//	TEST_ASSERT_EQUAL_INT(32, DMA_Buffer1[3]);
//	TEST_ASSERT_EQUAL_INT(75, DMA_Buffer1[4]);
//	TEST_ASSERT_EQUAL_INT(77, DMA_Buffer1[5]);
//	TEST_ASSERT_EQUAL_INT(30, DMA_Buffer1[6]);
//	TEST_ASSERT_EQUAL_INT(32, DMA_Buffer1[7]);
//}
//
///*
// *	If the firing Angle is less than the minimum limit(negativeHalf = 55, positiveHalf = 5),
// *	the firing angle will change the value to (negativeHalf = 50-55, positiveHalf = 0-5)
// * 				    	Buffer
// *   ___________________________________
// *	| 50 | 55 | 0 | 5 | 50 | 55 | 0 | 5 |
// *	|___ |___ |___|___|____|___|___|____|
// */
//void test_dataCopyIntoBuffer_with_minLimit_FiringAngle(void)
//{
//	int negativeHalf = 52;
//	int positiveHalf = 2;
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	TEST_ASSERT_EQUAL_INT(50, DMA_Buffer1[0]);
//	TEST_ASSERT_EQUAL_INT(55, DMA_Buffer1[1]);
//	TEST_ASSERT_EQUAL_INT(0, DMA_Buffer1[2]);
//	TEST_ASSERT_EQUAL_INT(5, DMA_Buffer1[3]);
//	TEST_ASSERT_EQUAL_INT(50, DMA_Buffer1[4]);
//	TEST_ASSERT_EQUAL_INT(55, DMA_Buffer1[5]);
//	TEST_ASSERT_EQUAL_INT(0, DMA_Buffer1[6]);
//	TEST_ASSERT_EQUAL_INT(5, DMA_Buffer1[7]);
//}
//
///*
// *	If the firing Angle is more than the maximum limit(negativeHalf = 92, positiveHalf = 42),
// *	the firing angle will change the value to (negativeHalf = 92-97, positiveHalf = 42-47)
// * 				    	Buffer
// *   ________________________________________
// *	| 92 | 97 | 42 | 47 | 92 | 97 | 42 | 47 |
// *	|___ |___ |____|____|____|____|____|____|
// */
//void test_dataCopyIntoBuffer_with_maxLimit_FiringAngle(void)
//{
//	int negativeHalf = 93;
//	int positiveHalf = 43;
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	TEST_ASSERT_EQUAL_INT(92, DMA_Buffer1[0]);
//	TEST_ASSERT_EQUAL_INT(97, DMA_Buffer1[1]);
//	TEST_ASSERT_EQUAL_INT(42, DMA_Buffer1[2]);
//	TEST_ASSERT_EQUAL_INT(47, DMA_Buffer1[3]);
//	TEST_ASSERT_EQUAL_INT(92, DMA_Buffer1[4]);
//	TEST_ASSERT_EQUAL_INT(97, DMA_Buffer1[5]);
//	TEST_ASSERT_EQUAL_INT(42, DMA_Buffer1[6]);
//	TEST_ASSERT_EQUAL_INT(47, DMA_Buffer1[7]);
//}
//
///*
// *	When the pulse is smaller than the minimum value(positiveHalf = 5,negativeHalf = 55),
// *  the pulse width is 5.
// */
//void test_function_getPulseWidth_MinLimit_expected_equal_5(void){
//	int negativeHalf = 50;
//	int positiveHalf = 0;
//	int pulseWidth;
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
//}
//
//void test_function_getPulseWidth_MinLimit2_expected_equal_5(void){
//	int negativeHalf = 55;
//	int positiveHalf = 5;
//	int pulseWidth;
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
//}
//
///*
// *	When the pulse is greater than the maximum value(positiveHalf = 92,negativeHalf = 42),
// *  the pulse width is 5
// */
//void test_function_getPulseWidth_MaxLimit_expected_equal_5(void){
//	int negativeHalf = 92;
//	int positiveHalf = 42;
//	int pulseWidth;
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
//}
//
//void test_function_getPulseWidth_MaxLimit2_expected_equal_5(void){
//	int negativeHalf = 97;
//	int positiveHalf = 47;
//	int pulseWidth;
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(5,pulseWidth);
//}
//
///*
// *	When the pulse is greater than the maximum value, and smaller than the minimum value
// *	the pulse Width is at the default = 2.
// */
//void test_function_getPulseWidth_defaultPulseWidth_expected_equal_2(void){
//	int negativeHalf = 56;
//	int positiveHalf = 6;
//	int pulseWidth;
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(2,pulseWidth);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(2,pulseWidth);
//}
//
//void test_function_getPulseWidth_defaultPulseWidth2_expected_equal_2(void){
//	int negativeHalf = 91;
//	int positiveHalf = 41;
//	int pulseWidth;
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(2,pulseWidth);
//	pulseWidth = getPulseWidth();
//	TEST_ASSERT_EQUAL_INT(2,pulseWidth);
//}
//
///*
// *	Given an initial value, run the test by increment the value(0-100).
// * 	So every possible value is being tested (100 tests).
// *  If the pulse width is larger than 6, then it will fails.
// */
//void test_functionality_pulseWidth(void){
//	static int negativeHalf = 50;
//	static int positiveHalf = 0;
//	int pulseWidth;
//	static int y=6;
//	for(int x=1;x<51;x++){
//		getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//		getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
//		if(x<6){
//			negativeHalf += x;
//			positiveHalf += x;
//		}
//		else{
//			if(x==7)
//				y=1;
//
//			if(x>42){
//				negativeHalf = negativeHalf-42+x;
//				positiveHalf = positiveHalf-42+x;
//			}
//			else{
//				negativeHalf += y;
//				positiveHalf += y;
//			}
//		}
//		pulseWidth = getPulseWidth();
//		printf("The firing times is %i and the pulse width is %i\n",negativeHalf-1,pulseWidth);
//		TEST_ASSERT_LESS_THAN_INT(6, pulseWidth);
//		pulseWidth = getPulseWidth();
//		printf("The firing times is %i and the pulse width is %i\n\n",positiveHalf-1,pulseWidth);
//		TEST_ASSERT_LESS_THAN_INT(6, pulseWidth);
//	}
//}
