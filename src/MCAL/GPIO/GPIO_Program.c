/*
 * GPIO_Program.c
 *
 *  Created on: Aug 18, 2025
 *      Author: JETT
 */

#include "GPIO_Interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void GPIO_PinMode(u8 mode, u8 pin, u8 reg) {

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

void GPIO_DigitalWrite(u8 mode, u8 pin, u8 reg) {
	switch (reg) {
		case PORTA:
			switch (mode) {
				case LOW:
					set_bit(GPIO_PORTB->BSRR,pin+15);
					break;
				case HIGH:
					set_bit(GPIO_PORTA->BSRR,pin);
					break;
				default:
					break;	
			}
		break;
		case PORTB:
			switch (mode) {
				case LOW:
					set_bit(GPIO_PORTB->BSRR,pin+15);
					break;
				case HIGH:
					set_bit(GPIO_PORTB->BSRR,pin);
					break;
				default:
					break;	
			}
		break;
		case PORTC:
			switch (mode) {
				case LOW:
					set_bit(GPIO_PORTB->BSRR,pin+15);
					break;
				case HIGH:
					set_bit(GPIO_PORTB->BSRR,pin);
					break;
				default:
					break;	
			}
		break;
		default:
			break;		
	}
}

u8 GPIO_DigitalRead(u8 mode,u8 pin,u8 reg){

}
