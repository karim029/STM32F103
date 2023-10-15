/*
 * GPIO_Interface.h
 *
 *  Created on: Sep 28, 2023
 *      Author: karim
 */

#include "GPIO_Config.h"

#define HIGH_PORTL 0x00FF
#define HIGH_PORTH 0xFF00

//PORTS
#define PORTA		0
#define PORTB		1
#define PORTC		2

//pins
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14
#define PIN15		15

/******************************************************/
/*                    INPUT MODES                     */
/******************************************************/
#define GPIO_INPUT_ANALOG			0b0000
#define GPIO_INPUT_FLOATING 		0b0100
#define GPIO_INPUT_PULLUP			0b1000
#define GPIO_INPUT_PULlDOWN			0b1000
/******************************************************/
/*             OUTPUT MODES-10MHZ                     */
/******************************************************/
#define GPIO_OUTPUT_10MHZ_PP		0b0001 //push pull
#define GPIO_OUTPUT_10MHZ_OD		0b0101 // open drain
#define GPIO_OUTPUT_10MHZ_AFPP		0b1001 //alternate function - push pull
#define GPIO_OUTPUT_10MHZ_AFOD		0b1101 //alternate function - open drain
/******************************************************/
/*             OUTPUT MODES-2MHZ                      */
/******************************************************/
#define GPIO_OUTPUT_2MHZ_PP			0b0010 //push pull
#define GPIO_OUTPUT_2MHZ_OD			0b0110 // open drain
#define GPIO_OUTPUT_2MHZ_AFPP		0b1010 //alternate function - push pull
#define GPIO_OUTPUT_2MHZ_AFOD		0b1110 //alternate function - open drain
/******************************************************/
/*             OUTPUT MODES-50MHZ                     */
/******************************************************/
#define GPIO_OUTPUT_50MHZ_PP		0b0011 //push pull
#define GPIO_OUTPUT_50MHZ_OD		0b0111 // open drain
#define GPIO_OUTPUT_50MHZ_AFPP		0b1011 //alternate function - push pull
#define GPIO_OUTPUT_50MHZ_AFOD		0b1111 //alternate function - open drain





void GPIO_togglePin(GPIOx_t *port, uint8_t copy_uint8_pin);
void GPIO_setPinValue(GPIOx_t* port,uint8_t copy_uint8_pin, uint8_t copy_uint8_value);
uint8_t GPIO_readPinValue(GPIOx_t* port,uint8_t copy_uint8_pin);
void GPIO_setPortDirection(GPIOx_t* port,uint8_t position, uint8_t copy_uint8_mode );
uint16_t GPIO_getPortValue(GPIOx_t* port,uint8_t position);
