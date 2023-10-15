/*
 * GPIO_Config.h
 *
 *  Created on: Sep 28, 2023
 *      Author: karim
 */

#ifndef SRC_GPIO_CONFIG_H_
#define SRC_GPIO_CONFIG_H_

#define HIGH 	1
#define LOW 	0

// Base addresses for PORT A B C

#define PORTA_BASE_ADDRESS 		0x40010800
#define PORTB_BASE_ADDRESS		0x40010C00
#define PORTC_BASE_ADDRESS		0x40011000


//registers for GPIO x ->> A , B ,C
typedef struct{

	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;


}GPIOx_t;


// create pointers to point on the GPIO struct for each port with the correct base addresses

#define GPIOA ((volatile GPIOx_t*)PORTA_BASE_ADDRESS)
#define GPIOB ((volatile GPIOx_t*)PORTB_BASE_ADDRESS)
#define GPIOC ((volatile GPIOx_t*)PORTC_BASE_ADDRESS)
#endif /* SRC_GPIO_CONFIG_H_ */
