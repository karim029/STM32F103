/*
 * OS_Private.h
 *
 *  Created on: Oct 4, 2023
 *      Author: karim
 */

#ifndef INC_OS_PRIVATE_H_
#define INC_OS_PRIVATE_H_


#define NULL ((void *)0)

typedef struct{

	uint16_t periodicity;
	void(*fptr)(void);
	uint16_t firstDelay;


}TASK_t;

TASK_t osTasks[numTasks] = {NULL};


/* user should not use this function
 * this function gets called every 1000 microseconds by the os
 *
 */
static void OS_scheduler();


#endif /* INC_OS_PRIVATE_H_ */
