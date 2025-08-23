/*
 * GPIO_Interface.h
 *
 *  Created on: Aug 18, 2025
 *      Author: JETT
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#include "GPIO_Config.h"
#include "GPIO_Private.h"

void GPIO_PinMode();
void GPIO_SetOutputType(u8 reg,u8 pin,u8 type);
void GPIO_SetPullType(u8 reg ,u8 pin ,u8 mode);
void GPIO_SetOutputSpeed(u8 reg ,u8 pin ,u8 speed);
void GPIO_DigitalWrite(u8 reg, u8 pin, u8 state);
u8 GPIO_DigitalRead(u8 reg,u8 pin);






#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
