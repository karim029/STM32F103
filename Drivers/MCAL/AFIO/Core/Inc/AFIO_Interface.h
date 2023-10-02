/*
 * AFIO_Interface.h
 *
 *  Created on: Oct 2, 2023
 *      Author: karim
 */

#ifndef INC_AFIO_INTERFACE_H_
#define INC_AFIO_INTERFACE_H_

#define AFIO_REG_BASE_ADDRESS 0x40010000


typedef struct{

	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICRx[4];
	volatile uint32_t MAPR2;


}AFIO_t;

// pointer that points to the base address of the AFIO registers
#define AFIO ((volatile AFIO_t*)0x40010000)


/* EXTI LINES NUMBER */
#define AFIO_EXTI0					0     /**< The line number for interrupt line 0.  */
#define AFIO_EXTI1					1     /**< The line number for interrupt line 1.  */
#define AFIO_EXTI2					2     /**< The line number for interrupt line 2.  */
#define AFIO_EXTI3					3     /**< The line number for interrupt line 3.  */
#define AFIO_EXTI4					4     /**< The line number for interrupt line 4.  */
#define AFIO_EXTI5					5     /**< The line number for interrupt line 5.  */
#define AFIO_EXTI6					6     /**< The line number for interrupt line 6.  */
#define AFIO_EXTI7					7     /**< The line number for interrupt line 7.  */
#define AFIO_EXTI8					8     /**< The line number for interrupt line 8.  */
#define AFIO_EXTI9					9     /**< The line number for interrupt line 9.  */
#define AFIO_EXTI10 				10    /**< The line number for interrupt line 10. */
#define AFIO_EXTI11 				11    /**< The line number for interrupt line 11. */
#define AFIO_EXTI12 				12    /**< The line number for interrupt line 12. */
#define AFIO_EXTI13 				13    /**< The line number for interrupt line 13. */
#define AFIO_EXTI14 				14    /**< The line number for interrupt line 14. */
#define AFIO_EXTI15					15    /**< The line number for interrupt line 15. */

/* PORTS */
#define AFIO_PORTA                0b0000 /**< The binary value for Port A pins. */
#define AFIO_PORTB                0b0001 /**< The binary value for Port B pins. */
#define AFIO_PORTC                0b0010 /**< The binary value for Port C pins. */


/* functions declaration */
void AFIO_setEXTI_config(uint8_t EXTI_line, uint8_t port);

#endif /* INC_AFIO_INTERFACE_H_ */
