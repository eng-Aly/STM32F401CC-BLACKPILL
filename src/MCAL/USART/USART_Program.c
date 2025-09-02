/*
 * USART_Program.c


 *
 *  Created on: Sep 1, 2025
 *      Author: JETT
 */



#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"

void USART_Init(u8 USART_NUM){

/*============================DON'T FORGET TO ADD BAUDRATE======================*/

switch(USART_NUM){
case USARTNUM1:
	set_bit(USART1->CR1,USART_ENABLE_BIT);
#if WORD_SIZE1==WORD_8BIT_SIZE
	clear_bit(USART1->CR1,WORD_LENGTH_BIT);
#elif WORD_SIZE1==WORD_9BIT_SIZE
	set_bit(USART1->CR1,WORD_LENGTH_BIT);
#endif

#if PARTIY_CONTROL1==PARTIY_DISABLE
	clear_bit(USART1->CR1,PARITY_CONTROL_BIT);
#elif PARTIY_CONTROL1==PARITY_ENABLE
		set_bit(USART1->CR1,PARITY_CONTROL_BIT);
	#if PARITY_SELECTION1==EVEN_PARITY
		clear_bit(USART1->CR1,PARITY_SELECTION_BIT);
	#elif PARITY_SELECTION1==ODD_PARITY
    	set_bit(USART1->CR1,PARITY_SELECTION_BIT)
#endif
#endif

#if   TC_INTERRUPT1==TC_DISABLE
	clear_bit(USART1->CR1,TCIE_BIT);
#elif TC_INTERRUPT1==TC_ENABLE
    set_bit(USART1->CR1,TCIE_BIT);

#endif
break;
case USARTNUM2:
	set_bit(USART2->CR1,USART_ENABLE_BIT);
#if WORD_SIZE2==WORD_8BIT_SIZE
	clear_bit(USART2->CR1,WORD_LENGTH_BIT);
#elif WORD_SIZE2==WORD_9BIT_SIZE
	set_bit(USART2->CR1,WORD_LENGTH_BIT);
#endif

#if PARTIY_CONTROL2==PARTIY_DISABLE
	clear_bit(USART2->CR1,PARITY_CONTROL_BIT);
#elif PARTIY_CONTROL2==PARITY_ENABLE
		set_bit(USART2->CR1,PARITY_CONTROL_BIT);
	#if PARITY_SELECTION2==EVEN_PARITY
		clear_bit(USART2->CR1,PARITY_SELECTION_BIT);
	#elif PARITY_SELECTION2==ODD_PARITY
    	set_bit(USART2->CR1,PARITY_SELECTION_BIT)
#endif
#endif

#if   TC_INTERRUPT2==TC_DISABLE
	clear_bit(USART2->CR1,TCIE_BIT);
#elif TC_INTERRUPT2==TC_ENABLE
    set_bit(USART2->CR1,TCIE_BIT);
#endif
break;

case USARTNUM6:
	set_bit(USART6->CR1,USART_ENABLE_BIT);
#if WORD_SIZE6==WORD_8BIT_SIZE
	clear_bit(USART6->CR1,WORD_LENGTH_BIT);
#elif WORD_SIZE6==WORD_9BIT_SIZE
	set_bit(USART6->CR1,WORD_LENGTH_BIT);
#endif

#if PARTIY_CONTROL6==PARTIY_DISABLE
	clear_bit(USART6->CR1,PARITY_CONTROL_BIT);
#elif PARTIY_CONTROL6==PARITY_ENABLE
		set_bit(USART6->CR1,PARITY_CONTROL_BIT);
	#if PARITY_SELECTION6==EVEN_PARITY
		clear_bit(USART6->CR1,PARITY_SELECTION_BIT);
	#elif PARITY_SELECTION6==ODD_PARITY
    	set_bit(USART6->CR1,PARITY_SELECTION_BIT)
	#endif
#endif

#if   TC_INTERRUPT6==TC_DISABLE
	clear_bit(USART6->CR1,TCIE_BIT);
#elif TC_INTERRUPT6==TC_ENABLE
    set_bit(USART6->CR1,TCIE_BIT);
#endif
break;
default:
	break;
}
}
void USART_Async_Write_Data(u8 USART_NUM,u8 Data){
	switch (USART_NUM)
	{
	case USARTNUM1:
		while(get_bit(USART1->SR,TXE_BIT));
		USART1->DR=Data;
		break;
	case USARTNUM2:
		while(get_bit(USART2->SR,TXE_BIT));
		USART2->DR=Data;	
		break;
	case USARTNUM6:
		while(get_bit(USART6->SR,TXE_BIT));
		USART6->DR=Data;
		break;
	default:
		break;
	}
}

void USART_Async_Read_Data(u8 USART_NUM,u8 *Data){
	switch (USART_NUM)
	{
	case USARTNUM1:
		u8 TIMEOUT=0;
		while(get_bit(USART1->SR,RXNE_BIT)==0 && TIMEOUT<1000){
			TIMEOUT++;
		}
		*Data=USART1->DR;
		break;
	case USARTNUM2:
		u8 TIMEOUT=0;
		while(get_bit(USART2->SR,RXNE_BIT)==0 && TIMEOUT<1000){
			TIMEOUT++;
		}
		*Data=USART2->DR;
		break;
	case USARTNUM6:
		u8 TIMEOUT=0;
		while(get_bit(USART6->SR,RXNE_BIT)==0 && TIMEOUT<1000){
			TIMEOUT++;
		}
		*Data=USART6->DR;
		break;
	default:
		break;
	}
}









