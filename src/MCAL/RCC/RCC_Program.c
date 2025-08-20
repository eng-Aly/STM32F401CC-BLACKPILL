/*
 * RCC_Program.c
 *
 *  Created on: Aug 17, 2025
 *      Author: JETT
 */


#include "RCC_Interface.h"

void MRCC_Init(){
#if RCC_SYS_CLK==HSE_CLK
	clear_bit(RCC->CR,HSION);

#if HSE_BYPASS==RC_CLK
	set_bit(RCC->CR,HSEBYP);
#elif HSE_BYPASS==MECHANICAL_CLK
	clear_bit(RCC->CR,HSEBYP);
#endif
	set_bit(RCC->CR,HSEBYP);
	while(get_bit(RCC->CR,HSERDY)==0);
	clear_bit(RCC->CFGR,HSERDY);


#elif RCC_SYS_CLK==HSI_CLK
	set_bit(RCC->CR,HSION);

	while(!get_bit(RCC->CR,HSIRDY));
	clear_bit(RCC->CFGR,SW0);
	clear_bit(RCC->CFGR,SW1);

#elif RCC_SYS_CLK==PLI_CLK
	set_bit(RCC->CR,PLION);


#endif	

}


void MRCC_Enable(u8 A_BusID , u8 A ){}
