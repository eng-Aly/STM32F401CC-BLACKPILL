/*
 * GPIO_Private.h
 *
 *  Created on: Aug 18, 2025
 *      Author: JETT
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

typedef struct{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO_Memory;


/*GPIO REGIGSTERS*/
#define GPIO_PORTA_BASEADDRESS      0x40020000
#define GPIO_PORTB_BASEADDRESS      0x40020400
#define GPIO_PORTC_BASEADDRESS      0x40020800


#define GPIO_PORTA                  ((volatile GPIO_Memory*)(GPIO_PORTA_BASEADDRESS))
#define GPIO_PORTB                  ((volatile GPIO_Memory*)(GPIO_PORTB_BASEADDRESS))
#define GPIO_PORTC                  ((volatile GPIO_Memory*)(GPIO_PORTC_BASEADDRESS))

v


/*GPIO MODE -OPTIONS*/
#define GPIO_INPUT                  0
#define GPIO_OUTPUT                 1
#define GPIO_ALTERNATE_FUNCTION     2
#define GPIO_ANALOG_MODE            3


/*GPIO OUTPUT MODE -OPTIONS*/
#define GPIO_OUTPUT_PUSHPULL        0
#define GPIO_OUTPUT_OPENDRAIN       1


/*GPIO PORTS -OPTIONS*/
#define PORTA                       0
#define PORTB                       1
#define PORTC                       2


#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
