/*
 * EXTI_program.c
 *
 *  Created on: Oct 2, 2023
 *      Author: karim
 */


#include "types.h"
#include "EXTI_Interface.h"
#include "../../../AFIO/Core/Inc/AFIO_Interface.h"
#include "bit_math.h"


// pointer to the callback function for the the exti lines
EXTI_callBack extiCallBack[16];


void EXTI_init(uint8_t EXTI_line,uint8_t port ,uint8_t mode){

	if(EXTI_line <16){
	AFIO_setEXTI_config(EXTI_line, port);
	switch(mode){
	case RISING_EDGE: set_Bit(EXTI->RTSR,EXTI_line); break;
	case FALLING_EDGE: set_Bit(EXTI->FTSR,EXTI_line);  break;
	case ON_CHANGE: set_Bit(EXTI->RTSR,EXTI_line); set_Bit(EXTI->FTSR,EXTI_line); break;
		}
	}
}

void EXTI_enableLine(uint8_t EXTI_line){

	if(EXTI_line <16)
	set_Bit(EXTI->IMR,EXTI_line);
}

void EXTI_disableLine(uint8_t EXTI_line){

	if(EXTI_line <16)
	clear_Bit(EXTI->IMR,EXTI_line);

}


void EXTI_softWareTrigger(uint8_t EXTI_line){

	if(EXTI_line <16)
	set_Bit(EXTI->SWIER,EXTI_line);
}

void set_CallBackFunction(uint8_t EXTI_line, EXTI_callBack callBackFunc){

	if(EXTI_line < 16)
		extiCallBack[EXTI_line] = callBackFunc;

}

void EXTI0_IRQHandler(void) {
    if (extiCallBack[0] != NULL) {
    	extiCallBack[0](); // Call the callback function for EXTI0
    }

    set_Bit(EXTI->PR,EXTI_LINE0);
}


void EXTI1_IRQHandler(void) {
    if (extiCallBack[1] != NULL) {
    	extiCallBack[1](); // Call the callback function for EXTI1
    }

    set_Bit(EXTI->PR,EXTI_LINE1);
}

void EXTI2_IRQHandler(void) {
    if (extiCallBack[2] != NULL) {
    	extiCallBack[2](); // Call the callback function for EXTI2
    }

    set_Bit(EXTI->PR,EXTI_LINE2);
}

void EXTI3_IRQHandler(void) {
    if (extiCallBack[3] != NULL) {
    	extiCallBack[3](); // Call the callback function for EXTI3
    }

    set_Bit(EXTI->PR,EXTI_LINE3);
}

void EXTI4_IRQHandler(void) {
    if (extiCallBack[4] != NULL) {
    	extiCallBack[4](); // Call the callback function for EXTI4
    }

    set_Bit(EXTI->PR,EXTI_LINE4);
}

void EXTI5_IRQHandler(void) {
    if (extiCallBack[5] != NULL) {
    	extiCallBack[5](); // Call the callback function for EXTI5
    }

    set_Bit(EXTI->PR,EXTI_LINE5);
}


void EXTI6_IRQHandler(void) {
    if (extiCallBack[6] != NULL) {
    	extiCallBack[6](); // Call the callback function for EXTI6
    }

    set_Bit(EXTI->PR,EXTI_LINE6);
}
void EXTI7_IRQHandler(void) {
    if (extiCallBack[7] != NULL) {
    	extiCallBack[7](); // Call the callback function for EXTI7
    }

    set_Bit(EXTI->PR,EXTI_LINE7);
}
void EXTI8_IRQHandler(void) {
    if (extiCallBack[8] != NULL) {
    	extiCallBack[8](); // Call the callback function for EXTI8
    }

    set_Bit(EXTI->PR,EXTI_LINE8);
}
void EXTI9_IRQHandler(void) {
    if (extiCallBack[9] != NULL) {
    	extiCallBack[9](); // Call the callback function for EXTI9
    }

    set_Bit(EXTI->PR,EXTI_LINE9);
}
void EXTI10_IRQHandler(void) {
    if (extiCallBack[10] != NULL) {
    	extiCallBack[10](); // Call the callback function for EXTI10
    }

    set_Bit(EXTI->PR,EXTI_LINE10);
}
void EXTI11_IRQHandler(void) {
    if (extiCallBack[11] != NULL) {
    	extiCallBack[11](); // Call the callback function for EXTI11
    }

    set_Bit(EXTI->PR,EXTI_LINE11);
}
void EXTI12_IRQHandler(void) {
    if (extiCallBack[12] != NULL) {
    	extiCallBack[12](); // Call the callback function for EXTI12
    }

    set_Bit(EXTI->PR,EXTI_LINE12);
}
void EXTI13_IRQHandler(void) {
    if (extiCallBack[13] != NULL) {
    	extiCallBack[13](); // Call the callback function for EXTI13
    }

    set_Bit(EXTI->PR,EXTI_LINE13);
}
void EXTI14_IRQHandler(void) {
    if (extiCallBack[14] != NULL) {
    	extiCallBack[14](); // Call the callback function for EXTI14
    }

    set_Bit(EXTI->PR,EXTI_LINE14);
}
void EXTI15_IRQHandler(void) {
    if (extiCallBack[15] != NULL) {
    	extiCallBack[15](); // Call the callback function for EXTI15
    }

    set_Bit(EXTI->PR,EXTI_LINE15);
}
