/*
 * AFIO_Program.c
 *
 *  Created on: Oct 2, 2023
 *      Author: karim
 */


#include "types.h"
#include "../../../AFIO/Core/Inc/AFIO_Interface.h"


void AFIO_setEXTI_config(uint8_t EXTI_line, uint8_t port){

	/*
	 *  function to select the desired port and exti line
	 *
	 */
	uint8_t registerIndex = EXTI_line / 4;

	EXTI_line %= 4;

	// read modify write
	AFIO->EXTICRx[registerIndex] &= ~((0b1111) << (EXTI_line * 4)); // clear the bits for the corresponding exti
	AFIO->EXTICRx[registerIndex] |= ((port)<<(EXTI_line * 4));

}
