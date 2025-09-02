/*
 * USART_Interface.h
 *
 *  Created on: Sep 1, 2025
 *      Author: JETT
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

#include  "../../LIB/BIT_MATH.h"
#include  "../../LIB/STD_TYPES.H"

void USART_Init(u8 USART_NUM);
void USART_Async_Read_Data(u8 USART_NUM,u8 *Data);
void USART_Async_Write_Data(u8 USART_NUM,u8 Data);

#endif /* MCAL_USART_USART_INTERFACE_H_ */
