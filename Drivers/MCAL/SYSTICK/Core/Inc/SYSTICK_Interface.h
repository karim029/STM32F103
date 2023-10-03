/*
 * SYSTICK_Interface.h
 *
 *  Created on: Oct 3, 2023
 *      Author: karim
 */

#ifndef INC_SYSTICK_INTERFACE_H_
#define INC_SYSTICK_INTERFACE_H_

#include "SYSTICK_Config.h"

#define SYSTICK_INT_ENABLE  1
#define SYSTICK_INT_DISABLE 0

#define SYSCLK_AHB			1
#define SYSCLK_AHB_DIV_8	0
#define NULL 			((void*)0)

#define SINGLE_INTERVAL 	0
#define PERIODIC_INTERVAL	1

#if SYSCLK_SOURCE == SYSCLK_AHB

#define AHB_CLK 	8000000

#elif SYSCLK_SOURCE == SYSCLK_AHB_DIV_8

#define AHB_CLK		1000000

#endif


typedef void(*callback)(void);



/* functions declaration */

/* Function initialize the systick by the user configuration in the Config.h file
 * sets the clock AHB or AHB/8 and disable or enable interrupt
 *
 *  param[in] none
 *  param[out] none
 */
void SYSTICK_init();

/* function reset the registers and the load value of the systick timer
 *
 * param[in]none
 * param[in]none
 */
void SYSTICK_reset();


/* function gets the current value in the systick value register
 *
 * param[in] none
 * param[out] uint32_t value of the val register
 */
uint32_t SYSTICK_getCurrentVal();


/* function is used for delay in microseconds using the busy wait method (no interrupts)
 *
 * param[in] uint32_t value in microseconds
 * please note that the value should be in range of 0x00000001-0x00FFFFFF (24 bits)
 * param[out] none
 */
void SYSTICK_busyWait_MicroS(uint32_t microSeconds);

/* function is used for delay in milliseconds using the busy wait method (no interrupts)
 *
 * param[in] uint32_t value in milliseconds
 * please note that the value should be in range of 0x00000001-0x00FFFFFF (24 bits)
 * param[out] none
 */
void SYSTICK_busyWait_MilliS(uint32_t milliSeconds);

/* function is used for delay in microseconds using the interval wait delay method using interrupts
 * with the callback function excutiing when the systick_handler is excuting
 * for a single interval only, works 1 time only
 *
 * param[in] uint32_t value in microseconds
 * param[in] callback pointer to function fptr (the function should be void void)
 */
void SYSTICK_singleInterval(uint32_t microSeconds, callback fptr);

/* function is used for delay in microseconds using the interval wait delay method using interrupts
 * with the callback function excutiing when the systick_handler is excuting
 * periodic interval which means that the callback function will keep getting called each time the systick underflows
 *
 * you can disable systick to stop the function.
 *
 * param[in] uint32_t value in microseconds
 * param[in] callback pointer to function fptr (the function should be void void)
 */
void SYSTICK_periodicInterval(uint32_t microSeconds, callback fptr);

#endif /* INC_SYSTICK_INTERFACE_H_ */
