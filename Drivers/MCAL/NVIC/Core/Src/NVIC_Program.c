/*
 * NVIC_Program.c
 *
 *  Created on: Sep 30, 2023
 *      Author: karim
 */


#include "types.h"
#include "bit_math.h"
#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "cmsis_gcc.h"

// MASK USED TO BE ANDED WITH THE IRQn value to map it to 0~31 similar to (IRQn % 32)
#define MASK_32 0b00011111
// GROUP MASK USED FOR OFFSETTING THE GROUPRI BITS TO CONFIGURE CORRECT GROUP
#define GROUP_MASK 0x05FA0300

void NVIC_enableIRQn(IRQn_Type IRQn){

	/* Function Enables the Interrupt with its number in the vector table
	 * use NVIC_interface to find the enum with all the Interrupts available for stm32f103xx
	 *
	 * IT Checks for the IRQn number then maps the IRQn to the correct ISR register
	 * and Interrupt corresponding bit
	 *
	 * the array index is dividing the IRQn number by 32 (2^5) by making a right shift operation
	 * to map it to the array corresponding to this IRQn number
	 */

	if(IRQn >= 0){

		NVIC->ISER[((uint32_t)IRQn) >> 5] = 1 << (((uint32_t)IRQn) & MASK_32);
	}

}

void NVIC_disableIRQn(IRQn_Type IRQn){

	/* Function disable the Interrupt with its number in the vector table
	 * use NVIC_interface to find the enum with all the Interrupts available for stm32f103xx
	 *
	 * IT Checks for the IRQn number then maps the IRQn to the correct ICER register
	 * and Interrupt corresponding bit
	 *
	 * the array index is dividing the IRQn number by 32 (2^5) by making a right shift operation
	 * to map it to the array corresponding to this IRQn number
	 */

	if(IRQn >= 0){

		NVIC->ICER[((uint32_t)IRQn) >> 5] = 1 << (((uint32_t)IRQn) & MASK_32);
	}
	/**
	  \brief   Data Synchronization Barrier
	  \details Acts as a special kind of Data Memory Barrier.
	           It completes when all explicit memory accesses before this instruction complete.
	 */
	__DSB();

	/**
	  \brief   Instruction Synchronization Barrier
	  \details Instruction Synchronization Barrier flushes the pipeline in the processor,
	           so that all instructions following the ISB are fetched from cache or memory,
	           after the instruction has been completed.
	 */
	__ISB();
}


uint32_t NVIC_getEnableIRQn(IRQn_Type IRQn){

	/* the function reads the status of the IRQn pending state
	 * if the result  = 1 the Interrupt is Enabled
	 * if the result  = 0 the Interrupt  is not Enabled
	 */

	uint32_t bit_no;


	if(IRQn >= 0){

		//get the correct bit number AND IRQn with 32 and shift the 1 to the correct number
		bit_no = (1 <<(((uint32_t)IRQn) & MASK_32));

		// AND the correct ISER register with the bit number of the IRQn
		return ((uint32_t)((NVIC->ISER[(((uint32_t)IRQn) >> 5)]) & (bit_no)) != 0) ? 1 : 0;

	}else{

		return 0;
	}


}

void NVIC_setPendingIRQn(IRQn_Type IRQn){

	/* Function set the Interrupt with its number in the vector table to pending state
	 * use NVIC_interface to find the enum with all the Interrupts available for stm32f103xx
	 *
	 * IT Checks for the IRQn number then maps the IRQn to the correct ISPR register
	 * and Interrupt corresponding bit
	 *
	 * the array index is dividing the IRQn number by 32 (2^5) by making a right shift operation
	 * to map it to the array corresponding to this IRQn number
	 */

	if(IRQn >= 0){

		NVIC->ISPR[((uint32_t)IRQn) >> 5] = 1 << (((uint32_t)IRQn) & MASK_32);
	}

}


void NVIC_clearPendingIRQn(IRQn_Type IRQn){

	/* Function clear the Interrupt pending bit with its number in the vector table
	 * use NVIC_interface to find the enum with all the Interrupts available for stm32f103xx
	 *
	 * IT Checks for the IRQn number then maps the IRQn to the correct ICPR register
	 * and Interrupt corresponding bit
	 *
	 * the array index is dividing the IRQn number by 32 (2^5) by making a right shift operation
	 * to map it to the array corresponding to this IRQn number
	 */

	if(IRQn >= 0){

		NVIC->ICPR[((uint32_t)IRQn) >> 5] = 1 << (((uint32_t)IRQn) & MASK_32);
	}

}


uint32_t NVIC_getPendingIRQn(IRQn_Type IRQn){

	/* the function reads the status of the IRQn pending state
	 * if the result  = 1 the Interrupt status is pending
	 * if the result  = 0 the Interrupt status is not pending
	 */

	uint32_t bit_no;


	if(IRQn >= 0){

		//get the correct bit number AND IRQn with 32 and shift the 1 to the correct number
		bit_no = (1 <<(((uint32_t)IRQn) & MASK_32));

		// AND the correct ISPR register with the bit number of the IRQn
		return ((uint32_t)((NVIC->ISPR[(((uint32_t)IRQn) >> 5)]) & (bit_no)) != 0) ? 1 : 0;



	}else{

		return 0;
	}

}

uint32_t NVIC_getActiveIRQn(IRQn_Type IRQn){

	/* the function reads the status of the IABR register
	 * if the result  = 1 the Interrupt status is active
	 * if the result  = 0 the Interrupt status is not active
	 */

	uint32_t bit_no;


	if(IRQn >= 0){

		//get the correct bit number AND IRQn with 32 and shift the 1 to the correct number
		bit_no = (1 <<(((uint32_t)IRQn) & MASK_32));

		// AND the correct IABR register with the bit number of the IRQn
		return ((uint32_t)((NVIC->IABR[(((uint32_t)IRQn) >> 5)]) & (bit_no)) != 0) ? 1 : 0;



	}else{

		return 0;
	}

}



void NVIC_setPriority(IRQn_Type IRQn,uint32_t groupNumber, uint8_t groupPriority, uint8_t subGroupPriority ){

	uint8_t priority = subGroupPriority | groupPriority <<((groupNumber - GROUP_MASK) / 0X100);

	//core - system IRQn
	if(IRQn <0){

		switch(IRQn){

		case MemoryManagement_IRQn:

			IRQn += 12;
			SCB->SHPR1 = (priority) << ((IRQn*8)+4);
			break;

		case BusFault_IRQn:

			IRQn += 12;
			SCB->SHPR1 = (priority) << ((IRQn*8)+4);
			break;

		case UsageFault_IRQn:
			IRQn += 12;
			SCB->SHPR1 = (priority) << ((IRQn*8)+4);
			break;

		case SVCall_IRQn:
			IRQn += 5;
			SCB->SHPR2 = (priority) <<((IRQn*8)+4);
			break;

		case PendSV_IRQn:
			IRQn += 4;
			SCB->SHPR3 = (priority) <<((IRQn*8)+4);
			break;

		case SysTick_IRQn:
			IRQn += 4;
			SCB->SHPR3 = (priority) <<((IRQn*8)+4);

		default:

		break;
		}




	}else if(IRQn >= 0){

		NVIC->IPR[(uint8_t)IRQn] = ((priority) << 4);

	}


	SCB->AIRCR = groupNumber;

}
