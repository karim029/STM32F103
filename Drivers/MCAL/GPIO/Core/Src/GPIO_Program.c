/*
 * GPIO_Program.c
 *
 *  Created on: Sep 28, 2023
 *      Author: karim
 */


#include "types.h"
#include "bit_math.h"
#include "GPIO_Config.h"
#include "GPIO_Interface.h"


#define LOW_PINS_NUMBER 		7
#define HIGH_PINS_NUMBER 		15
//NUMBER OF CONTROL BITS IN THE CONTROL REGISTER FOR EACH PIN 2 MODE AND 2 CONFIG TOTAL 4
#define NUM_OF_BITS_IN_CR 		4
#define BIT_MASK 				0b1111
#define NUM_OF_PINS_IN_CR		8

void GPIO_setPinDirection(GPIOx_t* port,uint8_t copy_uint8_pin, uint8_t copy_uint8_mode ){


		if(copy_uint8_pin <= LOW_PINS_NUMBER){
			// read modify write access
			port->CRL &= ~((BIT_MASK) << (copy_uint8_pin * NUM_OF_BITS_IN_CR));
			port->CRL |= ((copy_uint8_mode) << (copy_uint8_pin * NUM_OF_BITS_IN_CR));

		}else if(copy_uint8_pin <= HIGH_PINS_NUMBER){
			//Map pin number from 8 to 15 into 0 - 7 values
			copy_uint8_pin -= NUM_OF_PINS_IN_CR;

			// read modify write access
			port->CRH &= ~((BIT_MASK) << (copy_uint8_pin * NUM_OF_BITS_IN_CR));
			port->CRH |= ((copy_uint8_mode) << (copy_uint8_pin * NUM_OF_BITS_IN_CR));
		}


}


void GPIO_setPinValue(GPIOx_t* port,uint8_t copy_uint8_pin, uint8_t copy_uint8_value ){


	// temp pointer to GPIO struct port
	GPIOx_t *tempGPIO = port;

		//read BSSR value and store it in variable
		uint32_t bssrValue = tempGPIO->BSRR;

		if(copy_uint8_value == LOW){
			// the upper 16 bits in the BSSR are for reset so w map the pin number accordingly
			copy_uint8_pin+=16;
		}

		// set the pin (modify) and then write the new value in BSSR (write)
		bssrValue &= (1<<copy_uint8_pin);
		tempGPIO->BSRR = bssrValue;


}

uint8_t GPIO_readPinValue(GPIOx_t* port,uint8_t copy_uint8_pin){

	// temp pointer to GPIO struct port
	GPIOx_t *tempGPIO = port;

				//read the idr value and store it in a variable
			uint32_t idrValue = tempGPIO->IDR;

			//if the same bit == 1 then return 1
			if((idrValue) & (1<<copy_uint8_pin)){
				return HIGH;
			}else{
				return LOW;
			}
}

void GPIO_setPortDirection(GPIOx_t* port,uint8_t position, uint8_t copy_uint8_mode ){


				if(position == LOW){

				port->CRL = (copy_uint8_mode << 0) | (copy_uint8_mode << 4) | (copy_uint8_mode << 8) | (copy_uint8_mode << 12) |
							(copy_uint8_mode << 16) | (copy_uint8_mode << 20) | (copy_uint8_mode << 24) | (copy_uint8_mode << 28);

			}else if(position == HIGH){
				port->CRH = (copy_uint8_mode << 0) | (copy_uint8_mode << 4) | (copy_uint8_mode << 8) | (copy_uint8_mode << 12) |
							(copy_uint8_mode << 16) | (copy_uint8_mode << 20) | (copy_uint8_mode << 24) | (copy_uint8_mode << 28);

			}

}

uint16_t GPIO_getPortValue(GPIOx_t* port,uint8_t position){

	uint16_t portVal = port->CRL;

	if(position == LOW)
		portVal &= HIGH_PORTL;
	else if(position = HIGH)
		portVal &= HIGH_PORTH;

	return portVal;

}
