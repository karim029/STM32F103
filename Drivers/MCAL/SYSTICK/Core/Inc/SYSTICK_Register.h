/*
 * SYSTICK_Register.h
 *
 *  Created on: Oct 3, 2023
 *      Author: karim
 */

#ifndef INC_SYSTICK_REGISTER_H_
#define INC_SYSTICK_REGISTER_H_


#define SYSTICK_BASE_ADDRESS 0xE000E010

typedef struct{

	volatile uint32_t CTRL; /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
	volatile uint32_t LOAD; /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
	volatile uint32_t VAL;  /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
	volatile uint32_t CAL;  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */

}SYSTICK_t;

#define SYSTICK ((volatile SYSTICK_t*)SYSTICK_BASE_ADDRESS)




#endif /* INC_SYSTICK_REGISTER_H_ */
