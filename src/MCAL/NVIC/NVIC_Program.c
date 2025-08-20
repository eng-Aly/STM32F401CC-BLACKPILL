/*
 * NVIC_Program.c
 *
 *  Created on: Aug 19, 2025
 *      Author: JETT
 */

#include "NVIC_Interface.h"

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

void NVIC_SET_GROUP_PRIORITY(u8 pos,NVIC_GROUP,u8 ){

}

void NVIC_SET

test
test
