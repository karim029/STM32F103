/*
 * OS_Interface.h
 *
 *  Created on: Oct 4, 2023
 *      Author: karim
 */

#ifndef INC_OS_INTERFACE_H_
#define INC_OS_INTERFACE_H_



/*Functions for user to use */

/*
 * function to create the task and set its priority
 * note that the lower the priority number the higher its priority
 * the lowest priority to use is 0 and the maximum is numTasks -1 (in the config file)
 *
 * param[in] taskPriority
 * param[in] taskPeriodicity (the time for the task to be excuted each time.
 * param[in] a pointer to the task function
 * param[in] taskFirstDelay a delay to be ran when the task is created then the task start excuting
 *
 * param[out] none
 *
 * */
void OS_createTask(uint8_t taskPriority, uint16_t taskPeriodicity, void(*fptr)(void), uint16_t taskFirstDelay);


/* function must be called after setting the tasks in order for the scheduler to work
 * it sets up the systick timer to be used and the scheduler to be called when the systick interrupt is generated
 *
 *
 */
void OS_start();

#endif /* INC_OS_INTERFACE_H_ */
