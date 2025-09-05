/*
 * GPIO_Program.c
 *
 *  Created on: Aug 18, 2025
 *      Author: JETT
 */

#include "GPIO_Interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void GPIO_PinMode(u8 reg, u8 pin, u8 mode) {
	if ((reg == PORTA) & (pin == 13 | pin == 14 | pin ==15)){
		break;
	}
	if ((reg == PORTB) & (pin == 4 | pin ==3)){
		break;
	}
	switch (reg) {
	case PORTA:
		GPIO_PORTA->MODER &= ~(0b11 << (pin * 2));
		GPIO_PORTA->MODER |= (mode << (pin * 2));
		break;
	case PORTB:
		GPIO_PORTB->MODER &= ~(0b11 << (pin * 2));
		GPIO_PORTB->MODER |= (mode << (pin * 2));
		break;
	case PORTC:
		GPIO_PORTC->MODER &= ~(0b11 << (pin * 2));
		GPIO_PORTC->MODER |= (mode << (pin * 2));
		break;
	}
}

void GPIO_SetOutputType(u8 reg,u8 pin,u8 type){
	if ((reg == PORTA) & (pin == 13 | pin == 14 | pin ==15)){
		break;
	}
	if ((reg == PORTB) & (pin == 4 | pin ==3)){
		break;
	}
	if (type == GPIO_OUTPUT_PUSHPULL){
		switch(reg){
		case PORTA:
			clear_bit(GPIO_PORTA->OTYPER,pin);
			break;
		case PORTB:
			clear_bit(GPIO_PORTB->OTYPER,pin);
			break;
		case PORTC:
			clear_bit(GPIO_PORTC->OTYPER,pin);
			break;
		default:
			break;
		}
	}
	else if (type ==GPIO_OUTPUT_OPENDRAIN){
		switch(reg){
		case PORTA:
			set_bit(GPIO_PORTA->OTYPER,pin);
			break;
		case PORTB:
			set_bit(GPIO_PORTB->OTYPER,pin);
			break;
		case PORTC:
			set_bit(GPIO_PORTC->OTYPER,pin);
			break;
		default:
			break;
		}
	}
}


void GPIO_SetPullType(u8 reg ,u8 pin ,u8 mode){
	if ((reg == PORTA) & (pin == 13 | pin == 14 | pin ==15)){
		break;
	}
	if ((reg == PORTB) & (pin == 4 | pin ==3)){
		break;
	}
	switch(reg){
	case PORTA:
		GPIO_PORTA->PUPDR &= ~(0b11 << (pin * 2));
		GPIO_PORTA->PUPDR |= (mode << (pin * 2));
		break;
	case PORTB:
		GPIO_PORTB->PUPDR &= ~(0b11 << (pin * 2));
		GPIO_PORTB->PUPDR |= (mode << (pin * 2));
		break;
	case PORTC:
		GPIO_PORTC->PUPDR &= ~(0b11 << (pin * 2));
		GPIO_PORTC->PUPDR |= (mode << (pin * 2));
		break;
	default:
		break;
	}
}

void GPIO_SetOutputSpeed(u8 reg ,u8 pin ,u8 speed){
	if ((reg == PORTA) & (pin == 13 | pin == 14 | pin ==15)){
		break;
	}
	if ((reg == PORTB) & (pin == 4 | pin ==3)){
		break;
	}
	switch(reg){
	case PORTA:
		GPIO_PORTA->OSPEEDR &= ~(0b11 << (pin * 2));
		GPIO_PORTA->OSPEEDR |= (speed << (pin * 2));
		break;
	case PORTB:
		GPIO_PORTB->OSPEEDR &= ~(0b11 << (pin * 2));
		GPIO_PORTB->OSPEEDR |= (speed << (pin * 2));
		break;
	case PORTC:
		GPIO_PORTC->OSPEEDR &= ~(0b11 << (pin * 2));
		GPIO_PORTC->OSPEEDR |= (speed << (pin * 2));
		break;
	default:
		break;
	}

}

void GPIO_DigitalWrite(u8 reg, u8 pin, u8 state) {
	if ((reg == PORTA) & (pin == 13 | pin == 14 | pin ==15)){
		break;
	}
	if ((reg == PORTB) & (pin == 4 | pin ==3)){
		break;
	}
	switch (reg) {
		case PORTA:
			if(state==LOW){
				set_bit(GPIO_PORTA->BSRR,pin+15);
			}
			else if(state==HIGH){
				set_bit(GPIO_PORTA->BSRR,pin);
			}
			break;
		case PORTB:
			if(state==LOW){
				set_bit(GPIO_PORTB->BSRR,pin+15);
			}
			else if(state==HIGH){
				set_bit(GPIO_PORTB->BSRR,pin);
			}
			break;
		case PORTC:
			if(state==LOW){
				set_bit(GPIO_PORTC->BSRR,pin+15);
			}
			else if(state==HIGH){
				set_bit(GPIO_PORTC->BSRR,pin);
			}
			break;
		default:
			break;		
	}
}

u8 GPIO_DigitalRead(u8 reg,u8 pin){
	if ((reg == PORTA) & (pin == 13 | pin == 14 | pin ==15)){
		return ERROR;
		break;
	}
	if ((reg == PORTB) & (pin == 4 | pin ==3)){
		return ERROR;
		break;
	}
	switch (reg){
	case PORTA:
		return get_bit(GPIO_PORTA->IDR,pin);
		break;
	case PORTB:
		return get_bit(GPIO_PORTB->IDR,pin);
		break;
	case PORTC:
		return get_bit(GPIO_PORTC->IDR,pin);
		break;
	default:
		return ERROR;
		break;
	}
}

void GPIO_SetAlternateFunc(u8 reg, u8 pin ,u8 AltFunc){
	if(pin<8){
		switch(reg){
		case PORTA:
			GPIO_PORTA->AFRL &= ~(0b1111<<pin*4);
			GPIO_PORTA->AFRL |= (AltFunc<<pin*4);
			break;
		case PORTB:
			GPIO_PORTB->AFRL &= ~(0b1111<<pin*4);
			GPIO_PORTB->AFRL |= (AltFunc<<pin*4);
			break;
		case PORTC:
			GPIO_PORTC->AFRL &= ~(0b1111<<pin*4);
			GPIO_PORTC->AFRL |= (AltFunc<<pin*4);
			break;
		default:
			break;
		}
	}
	else if (pin>=8 && pin<16){
		switch(reg){
		case PORTA:
			GPIO_PORTA->AFRH &= ~(0b1111<<(pin-8)*4);
			GPIO_PORTA->AFRH |= (AltFunc<<(pin-8)*4);
			break;
		case PORTB:
			GPIO_PORTB->AFRH &= ~(0b1111<<(pin-8)*4);
			GPIO_PORTB->AFRH |= (AltFunc<<(pin-8)*4);
			break;
		case PORTC:
			GPIO_PORTC->AFRH &= ~(0b1111<<(pin-8)*4);
			GPIO_PORTC->AFRH |= (AltFunc<<(pin-8)*4);
			break;
		default:
			break;
		}

	}
}


void GPIO_Init(GPIO_PINConfig PIN){
	GPIO_PinMode(PIN->Port,PIN->Pin,  PIN->Mode);
	GPIO_SetOutputType(PIN->Port,PIN->Pin,PIN->OutputType);
	GPIO_SetPullType(PIN->Port,PIN->Pin,PIN->Pulltype);
	GPIO_SetOutputSpeed(PIN->Port,PIN->Pin,PIN->Speed);
	GPIO_SetAlternateFunc(PIN->Port,PIN->Pin,PIN->AltFunc);
}
