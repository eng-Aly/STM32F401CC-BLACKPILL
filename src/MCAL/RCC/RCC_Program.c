/*
 * RCC_Program.c
 *
 *  Created on: Sep 5, 2025
 *      Author: JETT
 */




#include "RCC_Interface.h"
#include "RCC_Private.h"

void RCC_Init(){
#if RCC_SYS_CLK==HSE_CLK
	clear_bit(RCC->CR,HSION);
#if HSE_BYPASS==RC_CLK
	set_bit(RCC->CR,HSEBYP);
#elif HSE_BYPASS==MECHANICAL_CLK
	clear_bit(RCC->CR,HSEBYP);
#endif
	set_bit(RCC->CR,16);
	while(get_bit(RCC->CR,17)==0);
	clear_bit(RCC->CFGR, 1);
	set_bit(RCC->CFGR, 0);


#elif RCC_SYS_CLK==HSI_CLK
	set_bit(RCC->CR,HSION);

	while(!get_bit(RCC->CR,HSIRDY));
	clear_bit(RCC->CFGR,SW0);
	clear_bit(RCC->CFGR,SW1);

#elif RCC_SYS_CLK==PLI_CLK
	set_bit(RCC->CR,PLION);


#endif

}




void RCC_Enable(u8 bus ,u8 peripheral){
	switch(bus){
	case RCC_AHB1:
		switch(peripheral){
		case RCC_GPIOA:
			set_bit(RCC->AHB1ENR,GPIOAEN);
			break;
		case RCC_GPIOB:
			set_bit(RCC->AHB1ENR,GPIOBEN);
			break;
		default:
			break;

		}
		set_bit(RCC->AHB1ENR,peripheral);
		break;
	case RCC_AHB2:
		set_bit(RCC->AHB2ENR,peripheral);
		break;
	case RCC_APB1:
		set_bit(RCC->APB1ENR,peripheral);
		break;
	case RCC_APB2:
		set_bit(RCC->APB2ENR,peripheral);
		break;
	}
}


