/*
 * NVIC_Program.c
 *
 *  Created on: Aug 19, 2025
 *      Author: JETT
 */

#include "NVIC_Interface.h"

u8 NVIC_GROUP_PRIORITY_GLOBAL=0;

void NVIC_ENABLE_PERIPHERAL_INT(u8 pos){
	set_bit(NVIC->ISER[pos/32],pos%32);
}
void NVIC_DISABLE_PERIPHERAL_INT(u8 pos){
	set_bit(NVIC->ICER[pos/32],pos%32);
}
void NVIC_CHANGE_TO_PENDING_INT(u8 pos){
	set_bit(NVIC->ISPR[pos/32],pos%32);
}
void NVIC_REMOVE_PENDING_INT(u8 pos){
	set_bit(NVIC->ICPR[pos/32],pos%32);
}
u8 NVIC_GET_ACTIVE_FLAG(u8 pos){
    return get_bit(NVIC->IABR[pos/32],pos%32);
}

void NVIC_SET_GROUP_PRIORITY(NVIC_GROUP Group_Priority ){
	 NVIC_GROUP_PRIORITY_GLOBAL = Group_Priority;
	 *SCB_AIRCR=VECTKEY | Group_Priority;
}

void NVIC_SET_PERIPHERAL_PRIORITY(u8 pos, u8 group , u8 sub_group){
	switch(NVIC_GROUP_PRIORITY_GLOBAL){
	case NVIC_GROUP_16_SUB_0:
		NVIC->IPRx[pos]=group << 4;
		break;
	case NVIC_GROUP_8_SUB_2:
		NVIC->IPRx[pos]=group << 5 | sub_group <<4;
		break;
	case NVIC_GROUP_4_SUB_4:
		NVIC->IPRx[pos]= group << 6 | sub_group <<4;
		break;
	case NVIC_GROUP_2_SUB_8:
		NVIC->IPRx[pos]= group << 7 | sub_group <<4;
		break;
	case NVIC_GROUP_0_SUB_16:
		NVIC->IPRx[pos]= sub_group <<4;
		break;
	default:
		break;

	}
}



