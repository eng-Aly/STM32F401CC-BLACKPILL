/*
 * SPI_Config.h
 *
 *  Created on: Sep 2, 2025
 *      Author: JETT
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

/*SPI_MS_TYPE  --OPTIONS
  MASTER      0
  SLAVE       1
 */
#define SPI1_MS_TYPE         MASTER
#define SPI2_MS_TYPE         SLAVE
#define SPI3_MS_TYPE         MASTER
/* SPI_DATA_FRAME_FORMAT  --OPTIONS
  DFF_8BIT    0
  DFF_16BIT   1
 */
#define SPI1_DFF             DFF_8BIT
#define SPI2_DFF             DFF_16BIT
#define SPI3_DFF             DFF_16BIT
/* SPI_POLARITY  --OPTIONS
  IDLE_LOW    0
  IDLE_HIGH   1
 */
#define SPI1_POL              IDLE_LOW
#define SPI2_POL              IDLE_HIGH
#define SPI3_POL              IDLE_LOW
/* SPI_PHASE  --OPTIONS
  LEADING_EDGE  0
  TRAILING_EDGE 1
 */
#define SPI1_PHASE            LEADING_EDGE
#define SPI2_PHASE            TRAILING_EDGE
#define SPI3_PHASE            LEADING_EDGE


#define SPI1_BAUDRATE         1000000
#define SPI2_BAUDRATE         1000000
#define SPI3_BAUDRATE         1000000

#endif /* MCAL_SPI_SPI_CONFIG_H_ */
