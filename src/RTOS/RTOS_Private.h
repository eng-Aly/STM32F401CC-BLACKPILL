/*
 * RTOS_Private.h
 *
 *  Created on: Aug 24, 2025
 *      Author: JETT
 */

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_


#define RUNNING    0
#define SUSPENDED  1

#define SYSTEM_TASKS_NUMBER               1

typedef struct {
	void (*fn_ptr)(void);
	u8 state;
	u8 priority;
	u32 periodicity;
	u32 first_delay;
}Task_Structure;

typedef enum {
	RTOS_OK,
	OUT_OF_RANGE,
	RESERVED_PRIORITY_ERROR,
	TASK_ALREADY_SUSPENDED,
	NO_TASK,
	TASK_ALREADY_RUNNING
}RTOS_Errors;


#endif /* RTOS_PRIVATE_H_ */
