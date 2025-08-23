/*
 * GPIO_Config.h
 *
 *  Created on: Aug 18, 2025
 *      Author: JETT
 */

#ifndef MCAL_GPIO_GPIO_CONFIG_H_
#define MCAL_GPIO_GPIO_CONFIG_H_

#include "GPIO_Private.h"


/* GPIO PORT OPTIONS
 * PORTA
 * PORTB
 * PORTC
 */

/* GPIO MODE OPTIONS */
#define GPIO_INPUT                                         0b00
#define GPIO_OUTPUT                                        0b01
#define GPIO_ALTERNATE_FUNCTION                            0b10
#define GPIO_ANALOG_MODE                                   0b11

#define HIGH                                               1
#define LOW                                                0



/* GPIO OUTPUT MODE OPTIONS
 *GPIO_OUTPUT_PUSHPULL        0
 *GPIO_OUTPUT_OPENDRAIN       1
*/

/*GPIO PULL MODE -OPTIONS
 * NOPULL                      0
 * PULLUP                      1
 * PULLDOWN                    2
*/


#endif
