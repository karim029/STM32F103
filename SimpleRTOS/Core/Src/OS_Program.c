/*
 * OS_Program.c
 *
 *  Created on: Oct 4, 2023
 *      Author: karim
 */

//standard
#include "types.h"
#include "bit_math.h"

//MCAL
#include "SYSTICK_Interface.h"

//os services
#include "OS_Config.h"
#include "OS_Interface.h"
#include "OS_Private.h"


void OS_createTask(uint8_t taskPriority, uint16_t taskPeriodicity, void(*fptr)(void), uint16_t taskFirstDelay){

	if(fptr!= NULL){

		osTasks[taskPriority].periodicity = taskPeriodicity;
		osTasks[taskPriority].firstDelay = taskFirstDelay;
		osTasks[taskPriority].fptr = fptr;

	}

}


void OS_start(){


	SYSTICK_init();

	SYSTICK_periodicInterval(OS_TICKTIME, OS_scheduler);

}

static void OS_scheduler(){


	for(uint8_t i =0; i<numTasks;i++){

		if(osTasks[i].fptr != NULL){

			if(osTasks[i].firstDelay == 0){


				osTasks[i].firstDelay = ((osTasks[i].periodicity) - 1);
				osTasks[i].fptr();

			}else{

				osTasks[i].firstDelay--;
			}


		}


	}

}

