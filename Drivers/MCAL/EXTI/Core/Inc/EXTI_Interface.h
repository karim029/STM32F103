/*
 * EXTI_Interface.h
 *
 *  Created on: Oct 2, 2023
 *      Author: karim
 */

#ifndef INC_EXTI_INTERFACE_H_
#define INC_EXTI_INTERFACE_H_

#define NULL ((void*)0)

//////////////////External Interrupt Lines

#define EXTI_LINE0  0
#define EXTI_LINE1  1
#define EXTI_LINE2  2
#define EXTI_LINE3  3

#define EXTI_LINE4  4
#define EXTI_LINE5  5
#define EXTI_LINE6  6
#define EXTI_LINE7  7

#define EXTI_LINE8  8
#define EXTI_LINE9  9
#define EXTI_LINE10 10
#define EXTI_LINE11 11

#define EXTI_LINE12 12
#define EXTI_LINE13 13
#define EXTI_LINE14 14
#define EXTI_LINE15 15


/////////////////////////External Interrupt Modes

#define RISING_EDGE    0
#define FALLING_EDGE   1
#define ON_CHANGE      2


typedef void(*EXTI_callBack)(void);

typedef struct{

	volatile uint32_t IMR; 		// interrupt mask register
	volatile uint32_t EMR; 		// event mask register
	volatile uint32_t RTSR;		// rising trigger select register
	volatile uint32_t FTSR; 	// falling trigger select register
	volatile uint32_t SWIER;	// software interrupt event trigger register
	volatile uint32_t PR;		// pending register

}EXTI_t;

#define EXTI ((volatile EXTI_t*)0x40010400)


/* Functions Declaration */

/* function initialiaze the exti line by configuring the port and pin number also the trigger mode
 *
 * param[in] EXTI_line (macros defined in the exti_interface.h file for each line
 * param[in] port macros are defined in the AFIO_interface file make sure to include it
 * or you can use 0 for portA and 1 for portB and 2 for portC
 *
 * param[in] mode macros are defined in the exti_interface file
 * there are 3 modes rising edge falling edge and on change
 *
 * param[out] void
 */
void EXTI_init(uint8_t EXTI_line,uint8_t port ,uint8_t mode);


/* function enable the exti line
 * param[in] EXTI_line
 * param[out] void
 */
void EXTI_enableLine(uint8_t EXTI_line);


/* function enable the exti line
 * param[in] EXTI_line
 * param[out] void
 */
void EXTI_disableLine(uint8_t EXTI_line);

/* function used to trigger the IRQHandler of the exti line using the software by calling this function
 * param[in] EXTI_line
 * param[out] void
 */
void EXTI_softWareTrigger(uint8_t EXTI_line);


/* Function to set the callback function for each EXTI_line
 *
 * param[in] EXTI_line
 * param[in} your callBackFunc address
 */
void set_CallBackFunction(uint8_t EXTI_line, EXTI_callBack callBackFunc);

#endif /* INC_EXTI_INTERFACE_H_ */
