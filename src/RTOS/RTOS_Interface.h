/*
 * RTOS_Interface.h
 *
 *  Created on: Aug 24, 2025
 *      Author: JETT
 */

#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "RTOS_Private.h"
#include "RTOS_Config.h"

void RTOS_Start();
RTOS_Errors RTOS_CreateTask(void (*fn_ptr)(void),u8 priority,u32 periodicity);


#endif /* RTOS_RTOS_INTERFACE_H_ */


