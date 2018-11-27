/*
 * DbgMcu.h
 *
 *  Created on: Nov 26, 2018
 *      Author: user
 */

#ifndef DBGMCU_H_
#define DBGMCU_H_

#define DBGMCU_CR			(*(uint32_t *)0xE0042004)
#define DBG_TIM3_STOP		(1<<12)
#define DBG_TIM4_STOP		(1<<13)


#define haltTimerxWhenDebugging(x)			(DBGMCU_CR |= x)


#endif /* DBGMCU_H_ */
