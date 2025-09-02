/*
 * RTOS_Program.c
 *
 *  Created on: Aug 24, 2025
 *      Author: JETT
 */


#include "RTOS_Interface.h"
#include "RTOS_Private.h"
#include "RTOS_Config.h"

Task_Structure TASK_SYSTEM[SYSTEM_TASKS_NUMBER];


RTOS_Errors RTOS_CreateTask(void (*fn_ptr)(void),u8 priority,u32 periodicity){
	if (priority >= SYSTEM_TASKS_NUMBER | priority <0){
		return OUT_OF_RANGE;
	}
	if (TASK_SYSTEM[priority].fn_ptr !=0 ){
		return RESERVED_PRIORITY_ERROR;
	}
	TASK_SYSTEM[priority].fn_ptr=fn_ptr;
	TASK_SYSTEM[priority].periodicity=periodicity;
	TASK_SYSTEM[priority].state=RUNNING;
	return RTOS_OK;
}

RTOS_Errors RTOS_SuspendedTask(u8 priority){
	if (priority >= SYSTEM_TASKS_NUMBER | priority <0){
		return OUT_OF_RANGE;
	}
	if (TASK_SYSTEM[priority].fn_ptr ==0){
		return NO_TASK;
	}
	if (TASK_SYSTEM[priority].state==RUNNING){
		TASK_SYSTEM[priority].state=SUSPENDED;
		return RTOS_OK;
	}
	else{
		return TASK_ALREADY_SUSPENDED;
	}
}

RTOS_Errors RTOS_DeleteTask(u8 priority){
	if (priority >= SYSTEM_TASKS_NUMBER | priority <0){
		return OUT_OF_RANGE;
	}
	if (TASK_SYSTEM[priority].fn_ptr ==0){
		return NO_TASK;
	}
	TASK_SYSTEM[priority].periodicity=(void) {0};
	return RTOS_OK;
}

RTOS_Errors RTOS_ResumeTask(u8 priority){
	if (priority >= SYSTEM_TASKS_NUMBER | priority <0){
		return OUT_OF_RANGE;
	}
	if (TASK_SYSTEM[priority].fn_ptr ==0){
		return NO_TASK;
	}
	if (TASK_SYSTEM[priority].state==SUSPENDED){
		TASK_SYSTEM[priority].state=RUNNING;
		return RTOS_OK;
	}
	else{
		return TASK_ALREADY_RUNNING;
	}
}


