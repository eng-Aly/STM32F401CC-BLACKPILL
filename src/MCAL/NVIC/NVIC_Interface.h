/*
 * NVIC_Interface.h
 *
 *  Created on: Aug 19, 2025
 *      Author: JETT
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#include "NVIC_Private.h"
#include "NVIC_Config.h"

void NVIC_ENABLE_PERIPHERAL_INT(u8 pos);
void NVIC_DISABLE_PERIPHERAL_INT(u8 pos);
void NVIC_CHANGE_TO_PENDING_INT(u8 pos);
void NVIC_REMOVE_PENDING_INT(u8 pos);
u8 NVIC_GET_ACTIVE_FLAG(u8 pos);
void NVIC_SET_GROUP_PRIORITY(NVIC_GROUP Group_Priority );
void NVIC_SET_PERIPHERAL_PRIORITY(u8 pos, u8 group , u8 sub_group);




#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
