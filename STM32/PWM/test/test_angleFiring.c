#include "unity.h"
#include "angleFiring.h"

void setUp(void){}

void tearDown(void){}

void test_angleFiring(void)
{
	int negativeHalf,positiveHalf;
  calculationForPulseWidth(1,&negativeHalf,&positiveHalf);
 	TEST_ASSERT_EQUAL_INT(99,negativeHalf);
 	TEST_ASSERT_EQUAL_INT(49,positiveHalf);
	calculationForPulseWidth(1,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(99,negativeHalf);
	TEST_ASSERT_EQUAL_INT(49,positiveHalf);
	calculationForPulseWidth(1,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(99,negativeHalf);
	TEST_ASSERT_EQUAL_INT(49,positiveHalf);
	calculationForPulseWidth(1,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(99,negativeHalf);
	TEST_ASSERT_EQUAL_INT(49,positiveHalf);
	calculationForPulseWidth(1,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(99,negativeHalf);
	TEST_ASSERT_EQUAL_INT(49,positiveHalf);
	calculationForPulseWidth(5,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(97,negativeHalf);
	TEST_ASSERT_EQUAL_INT(47,positiveHalf);
	calculationForPulseWidth(5,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(97,negativeHalf);
	TEST_ASSERT_EQUAL_INT(47,positiveHalf);
	calculationForPulseWidth(5,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(97,negativeHalf);
	TEST_ASSERT_EQUAL_INT(47,positiveHalf);
	calculationForPulseWidth(5,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(97,negativeHalf);
	TEST_ASSERT_EQUAL_INT(47,positiveHalf);
	calculationForPulseWidth(5,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(97,negativeHalf);
	TEST_ASSERT_EQUAL_INT(47,positiveHalf);
	calculationForPulseWidth(5,&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(97,negativeHalf);
	TEST_ASSERT_EQUAL_INT(47,positiveHalf);
}

void test_replicateData(void)
{
	int negativeHalf = 90;
	int positiveHalf = 40;
	replicateData(&negativeHalf,&positiveHalf);
	replicateData(&negativeHalf,&positiveHalf);
	TEST_ASSERT_EQUAL_INT(90, DMA_Buffer1[0]);
	TEST_ASSERT_EQUAL_INT(92, DMA_Buffer1[1]);
	TEST_ASSERT_EQUAL_INT(40, DMA_Buffer1[2]);
	TEST_ASSERT_EQUAL_INT(42, DMA_Buffer1[3]);
	TEST_ASSERT_EQUAL_INT(90, DMA_Buffer1[4]);
	TEST_ASSERT_EQUAL_INT(92, DMA_Buffer1[5]);
	TEST_ASSERT_EQUAL_INT(40, DMA_Buffer1[6]);
	TEST_ASSERT_EQUAL_INT(42, DMA_Buffer1[7]);
}
