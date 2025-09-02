/*
 * SPI_Program.c
 *
 *  Created on: Sep 2, 2025
 *      Author: JETT
 */


#include "SPI_Interface.h"


  void SPI_Init(u8 SPI_NUM){
  switch (SPI_NUM)
  {
  case SPI_NUM1:
  SPI1->CR1=0x11b | 
  #if SPI1_MS_TYPE==MASTER
    set_bit(SPI1->CR1, SSM_BIT);
    set_bit(SPI1->CR1, SSI_BIT);
    set_bit(SPI1->CR1, MSTR_BIT);


  #elif SPI1_MS_TYPE==SLAVE
    set_bit(SPI1->CR1, SSM_BIT);
    clear_bit(SPI1->CR1, SSI_BIT);
    clear_bit(SPI1->CR1,MSTR_BIT);

  #endif
  #if SPI1_DFF==DFF_8BIT
    clear_bit(SPI1->CR1, DFF_BIT);
  #elif SPI1_DFF==DFF_16BIT
    set_bit(SPI1->CR1, DFF_BIT);
  #endif
  #if SPI1_POLARITY==IDLE_LOW
    clear_bit(SPI1->CR1, CPOL_BIT);
  #elif SPI1_POLARITY==IDLE_HIGH
    set_bit(SPI1->CR1, CPOL_BIT);
  #endif
    break;
  case SPI_NUM2:
  #if SPI2_MS_TYPE==MASTER
    set_bit(SPI2->CR1, SSM_BIT);
    set_bit(SPI2->CR1, SSI_BIT);
    set_bit(SPI2->CR1, MSTR_BIT);
  #elif SPI2_MS_TYPE==SLAVE
    set_bit(SPI2->CR1, SSM_BIT);
    clear_bit(SPI2->CR1, SSI_BIT);
    clear_bit(SPI2->CR1,MSTR_BIT);
  #endif
  #if SPI2_POLARITY==IDLE_LOW
    clear_bit(SPI2->CR1, CPOL_BIT);
  #elif SPI2_POLARITY==IDLE_HIGH
    set_bit(SPI2->CR1, CPOL_BIT);
  #endif
  #if SPI2_PHASE==LEADING_EDGE
    set_bit(SPI2->CR1, CPHA_BIT);
  #elif SPI2_PHASE==TRAILING_EDGE
    clear_bit(SPI2->CR1, CPHA_BIT);
  #endif
  #if SPI2_POLARITY==IDLE_LOW
    clear_bit(SPI2->CR1, CPOL_BIT);
  #elif SPI2_POLARITY==IDLE_HIGH
    set_bit(SPI2->CR1, CPOL_BIT);
  #endif
  #if SPI2_PHASE==LEADING_EDGE
    set_bit(SPI2->CR1, CPHA_BIT);
  #elif SPI2_PHASE==TRAILING_EDGE
    clear_bit(SPI2->CR1, CPHA_BIT);
  #endif
    break;
  case SPI_NUM3:
  #if SPI3_MS_TYPE==MASTER
    set_bit(SPI3->CR1, SSM_BIT);
    set_bit(SPI3->CR1, SSI_BIT);
    set_bit(SPI3->CR1, MSTR_BIT);
  #elif SPI3_MS_TYPE==SLAVE
    set_bit(SPI3->CR1, SSM_BIT);
    clear_bit(SPI3->CR1, SSI_BIT);
    clear_bit(SPI3->CR1,MSTR_BIT);
  #endif
  #if SPI3_DFF==DFF_8BIT
    clear_bit(SPI3->CR1, DFF_BIT);
  #elif SPI3_DFF==DFF_16BIT
    set_bit(SPI3->CR1, DFF_BIT);
  #endif
  #if SPI3_POLARITY==IDLE_LOW
    clear_bit(SPI3->CR1, CPOL_BIT);
  #elif SPI3_POLARITY==IDLE_HIGH
    set_bit(SPI3->CR1, CPOL_BIT);
  #endif
  #if SPI3_PHASE==LEADING_EDGE
    set_bit(SPI3->CR1, CPHA_BIT);
  #elif SPI3_PHASE==TRAILING_EDGE
    clear_bit(SPI3->CR1, CPHA_BIT);
  #endif
    break;
  default:
    break;
  }  
  } 
  
  
  void SPI_Transmit_8bit(u8 SPI_NUM,u8 data){
    switch (SPI_NUM)
    {
    case SPI_NUM1:
        u16 TIMEOUT=0;
        while (get_bit(SPI1->SR,TXE_BIT)==0 && TIMEOUT<1000){
            TIMEOUT++;      
        }
        SPI1->DR = data;
        break;
    case SPI_NUM2:
        u16 TIMEOUT=0;
        while (get_bit(SPI2->SR,TXE_BIT)==0 && TIMEOUT<1000){
            TIMEOUT++;      
        }
        SPI2->DR = data;
        break;
    case SPI_NUM3:
        u16 TIMEOUT=0;
        while (get_bit(SPI3->SR,TXE_BIT)==0 && TIMEOUT<1000){
            TIMEOUT++;      
        }
        SPI3->DR = data;
        break;
    default:
        break;
    }
  }

  void SPI_Receive_8bit(u32 SPI_NUM,u8* data){
    switch (SPI_NUM)
    {
    case SPI_NUM1:
        u16 TIMEOUT=0;
        while (get_bit(SPI1->SR,RXNE_BIT)==0 && TIMEOUT<1000){
            TIMEOUT++;      
        }
        *data = SPI1->DR;
        break;
    case SPI_NUM2:
        u16 TIMEOUT=0;
        while (get_bit(SPI2->SR,RXNE_BIT)==0 && TIMEOUT<1000){
            TIMEOUT++;      
        }
        *data = SPI2->DR;
        break;
    case SPI_NUM3:
        u16 TIMEOUT=0;
        while (get_bit(SPI3->SR,RXNE_BIT)==0 && TIMEOUT<1000){
            TIMEOUT++;      
        }
        *data = SPI3->DR;
        break;
    default:
        break;
    }
}