#include "unity.h"
#include "angleFiring.h"

void setUp(void){}

void tearDown(void){}

void test_getPulseTimes(void)
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

void test_replicateData(void)
{
	int negativeHalf = 90;
	int positiveHalf = 40;
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	getFiringTimesAndCopyIntoBuffer(&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(93, DMA_Buffer1[0]);
	TEST_ASSERT_EQUAL_INT(95, DMA_Buffer1[1]);
	TEST_ASSERT_EQUAL_INT(43, DMA_Buffer1[2]);
	TEST_ASSERT_EQUAL_INT(45, DMA_Buffer1[3]);
	TEST_ASSERT_EQUAL_INT(93, DMA_Buffer1[4]);
	TEST_ASSERT_EQUAL_INT(95, DMA_Buffer1[5]);
	TEST_ASSERT_EQUAL_INT(43, DMA_Buffer1[6]);
	TEST_ASSERT_EQUAL_INT(45, DMA_Buffer1[7]);
}
