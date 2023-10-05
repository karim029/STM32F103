/*
 * DMA_Interface.h
 *
 *  Created on: Oct 5, 2023
 *      Author: karim
 */

#ifndef INC_DMA_INTERFACE_H_
#define INC_DMA_INTERFACE_H_

//DMA Flags
#define DMA_GIF   0		// global interrupt flag
#define DMA_TCIF  1		// channel tansfer complete flag
#define DMA_HTIF  2		// channel half transfer flag
#define DMA_TEIF  3		// channel transfer error flag
//DMA CHANNELS
#define CHANNEL1  0
#define CHANNEL2  1
#define CHANNEL3  2
#define CHANNEL4  3
#define CHANNEL5  4
#define CHANNEL6  5
#define CHANNEL7  6
//Interrupt Enable
#define DMA_TCIE  1		// transfer complete interrupt enable
#define DMA_HTIE  2		// half transfer interrupt enable
#define DMA_TEIE  3		// transfer error interrupt enable
//Enable
#define DMA_ENABLE  0
#define DMA_DISABLE 1


//DMA Configuration
//Direction
#define MEM_TO_MEM   0
#define PERIPHERAL_TO_MEM  1
#define MEM_TO_PERIPHERAL  2
//Circular
#define DMA_ENABLE_CIRCULAR  0
#define DMA_DISABLE_CIRCULAR 1
//PIN & MIN
#define PERIPHERAL_INCREMENT_ENABLE  0
#define PERIPHERAL_INCREMENT_DISABLE 1
//MIN
#define MEM_INCREMENT_ENABLE  0
#define MEM_INCREMENT_DISABLE 1
//Size
#define BYTE       0
#define HALF_WORD  1
#define WORD       2
//Channel Priority
#define DMA_LOW         0
#define DMA_MEDIUM      1
#define DMA_HIGH        2
#define DMA_VERY_HIGH   3


#endif /* INC_DMA_INTERFACE_H_ */
