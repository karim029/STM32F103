/*
 * DMA_Private.h
 *
 *  Created on: Oct 5, 2023
 *      Author: karim
 */

#ifndef INC_DMA_PRIVATE_H_
#define INC_DMA_PRIVATE_H_


#define DMA1_BASE_ADDRESS 0x40020000
#define NULL ((void *)0)

typedef void(*callBack)(void);


typedef struct {
    uint8_t direction;              // DMA data transfer direction (MEM_TO_MEM, PREI_TO_MEM, MEM_TO_PERI)
    uint8_t circular;               // Circular mode enable/disable (DMA_ENABLE_CIRCULAR, DMA_DISABLE_CIRCULAR)
    uint8_t peripheralIncrement;    // Peripheral increment enable/disable (PERIPHERAL_INCREMENT_ENABLE, PERIPHERAL_INCREMENT_DISABLE)
    uint8_t memoryIncrement;        // Memory increment enable/disable (MEM_INCREMENT_ENABLE, MEM_INCREMENT_DISABLE)
    uint8_t peripheralSize;         // Peripheral data size (BYTE, HALF_WORD, WORD)
    uint8_t memorySize;             // Memory data size (BYTE, HALF_WORD, WORD)
    uint8_t channelPriority;        // Channel priority (DMA_LOW, DMA_MEDIUM, DMA_HIGH, DMA_VERY_HIGH)
} DMA_ChannelConfig_t;


typedef struct{

	volatile uint32_t CCR; 		// channel x configuration register
	volatile uint32_t CNDTR;	// channel x number of data register
	volatile uint32_t CPAR;		// channel x peripheral address register
	volatile uint32_t CMAR;		// channel x memory address register
	volatile uint32_t RESERVED; // reserved 4 bytes location (seperates DMA1 AND DMA2)

}DMA_channel_t;

typedef struct{

	volatile uint32_t ISR; 			// dma interrupt register
	volatile uint32_t IFCR;			// dma interrupt flag clear register
	DMA_channel_t DMA_channel[7];
}DMA_t;

#define DMA ((volatile DMA_t*)DMA1_BASE_ADDRESS)



#endif /* INC_DMA_PRIVATE_H_ */
