/*
 * SYSTICK_Program.c
 *
 *  Created on: Oct 3, 2023
 *      Author: karim
 */


#include "types.h"
#include "bit_math.h"
#include "SYSTICK_Interface.h"
#include "../../../SYSTICK/Core/inc/SYSTICK_Register.h"
#include "../../../SYSTICK/Core/inc/SYSTICK_Config.h"


callback callBackFunc = NULL;

static uint8_t intervalMode;

void SYSTICK_init(){

	//disable systick
	clear_Bit(SYSTICK->CTRL,0);


#if SYSTICK_INT_STATE == SYSTICK_INT_ENABLE
	set_Bit(SYSTICK->CTRL,1);
#elif SYSTICK_INT_STATE == SYSTICK_INT_DISABLE
	clear_Bit(SYSTICK->CTRL,1);
#endif

#if SYSCLK_SOURCE == SYSCLK_AHB
	set_Bit(SYSTICK->CTRL,2);
#elif SYSCLK_SOURCE == SYSCLK_AHB_DIV_8
	clear_Bit(SYSTICK->CTRL,2);

#endif

}



static void SYSTICK_start(){

	set_Bit(SYSTICK->CTRL,0);
}

static void SYSTICK_stop(){

	clear_Bit(SYSTICK->CTRL,0);
}


void SYSTICK_reset(){

	//disable systick timer
	SYSTICK->CTRL = 0;

	//clear values in val reg and reload reg
	SYSTICK->VAL = 0;
	SYSTICK->LOAD = 0;

	clear_Bit(SYSTICK->CTRL,16);


}


uint32_t SYSTICK_getCurrentVal(){

	return SYSTICK->VAL;
}


void SYSTICK_busyWait_MicroS(uint32_t microSeconds){

	//The RELOAD value can be any value in the range 0x00000001-0x00FFFFFF

	uint32_t localPreloadVal = (microSeconds * AHB_CLK)/1000000;

	SYSTICK->LOAD = localPreloadVal;

	//enable systick
	SYSTICK_start();
	// wait until systick flag returns 1
	while(!get_Bit(SYSTICK->CTRL,16));
	//disable systick
	SYSTICK_stop();

}

void SYSTICK_busyWait_MilliS(uint32_t milliSeconds){

	//The RELOAD value can be any value in the range 0x00000001-0x00FFFFFF

	uint32_t localPreloadVal = (milliSeconds * AHB_CLK)/1000;

	SYSTICK->LOAD = localPreloadVal;

	//enable systick
	SYSTICK_start();
	// wait until systick flag returns 1
	while(!get_Bit(SYSTICK->CTRL,16));
	//disable systick
	SYSTICK_stop();
}

void SYSTICK_singleInterval(uint32_t microSeconds, callback fptr){

	if(fptr != NULL){

		// assign pointer to the user callback function
		callBackFunc = fptr;

		uint32_t localPreloadVal = (microSeconds * AHB_CLK)/1000000;

			SYSTICK->LOAD = localPreloadVal;


		//set interval mode to single intetval
		intervalMode = SINGLE_INTERVAL;

		//ENABLE SYSTICK AND INTERRUPT
		set_Bit(SYSTICK->CTRL,0);
		set_Bit(SYSTICK->CTRL,1);


	}

}

void SYSTICK_periodicInterval(uint32_t microSeconds, callback fptr){

	if(fptr != NULL){

			// assign pointer to the user callback function
			callBackFunc = fptr;

			uint32_t localPreloadVal = (microSeconds * AHB_CLK)/1000000;

				SYSTICK->LOAD = localPreloadVal;


			//set interval mode to single intetval
			intervalMode = PERIODIC_INTERVAL;

			//ENABLE SYSTICK AND INTERRUPT
			set_Bit(SYSTICK->CTRL,0);
			set_Bit(SYSTICK->CTRL,1);


		}
}


void SysTick_Handler(void){



		if(callBackFunc != NULL){

			if(intervalMode == SINGLE_INTERVAL){

				SYSTICK_reset();
			}
			callBackFunc();
		}

		//clear count flag
		clear_Bit(SYSTICK->CTRL,16);

}
