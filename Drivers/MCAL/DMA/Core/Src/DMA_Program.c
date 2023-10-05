/*
 * DMA_Program.c
 *
 *  Created on: Oct 5, 2023
 *      Author: karim
 */


#include "types.h"
#include "bit_math.h"

#include "DMA_Interface.h"
#include "DMA_Private.h"



callBack callBackFunc[7] = {NULL};

void DMA_SetChannelConfiguration(uint8_t channel, DMA_ChannelConfig_t* config) {
    // Disable DMA channel
    clear_Bit(DMA->DMA_channel[channel].CCR, 0);

    // Wait until DMA channel is disabled
    while (get_Bit(DMA->DMA_channel[channel].CCR, 0) == 1);

    // Configure DMA direction
    if (config->direction == MEM_TO_MEM) {
        set_Bit(DMA->DMA_channel[channel].CCR, 14);
    } else if (config->direction == PERIPHERAL_TO_MEM) {
        clear_Bit(DMA->DMA_channel[channel].CCR, 4);
    } else if (config->direction == MEM_TO_PERIPHERAL) {
        set_Bit(DMA->DMA_channel[channel].CCR, 4);
    }

    // Configure DMA circular mode
    if (config->circular == DMA_ENABLE_CIRCULAR) {
        set_Bit(DMA->DMA_channel[channel].CCR, 5);
    } else if (config->circular == DMA_DISABLE_CIRCULAR) {
        clear_Bit(DMA->DMA_channel[channel].CCR, 5);
    }

    // Configure peripheral increment
    if (config->peripheralIncrement == PERIPHERAL_INCREMENT_ENABLE) {
        clear_Bit(DMA->DMA_channel[channel].CCR, 6);
    } else if (config->peripheralIncrement == PERIPHERAL_INCREMENT_DISABLE) {
        clear_Bit(DMA->DMA_channel[channel].CCR, 6);
    }

    // Configure memory increment
    if (config->memoryIncrement == MEM_INCREMENT_ENABLE) {
        set_Bit(DMA->DMA_channel[channel].CCR, 7);
    } else if (config->memoryIncrement == MEM_INCREMENT_DISABLE) {
        clear_Bit(DMA->DMA_channel[channel].CCR, 7);
    }

    // Configure memory size
    if (config->memorySize == BYTE) {
        clear_Bit(DMA->DMA_channel[channel].CCR, 10);
        clear_Bit(DMA->DMA_channel[channel].CCR, 11);
    } else if (config->memorySize == HALF_WORD) {
        set_Bit(DMA->DMA_channel[channel].CCR, 10);
        clear_Bit(DMA->DMA_channel[channel].CCR, 11);
    } else if (config->memorySize == WORD) {
        clear_Bit(DMA->DMA_channel[channel].CCR, 10);
        set_Bit(DMA->DMA_channel[channel].CCR, 11);
    }

    // Configure peripheral size
    if (config->peripheralSize == BYTE) {
        clear_Bit(DMA->DMA_channel[channel].CCR, 8);
        clear_Bit(DMA->DMA_channel[channel].CCR, 9);
    } else if (config->peripheralSize == HALF_WORD) {
        set_Bit(DMA->DMA_channel[channel].CCR, 8);
        clear_Bit(DMA->DMA_channel[channel].CCR, 9);
    } else if (config->peripheralSize == WORD) {
        clear_Bit(DMA->DMA_channel[channel].CCR, 8);
        set_Bit(DMA->DMA_channel[channel].CCR, 9);
    }

    // Configure channel priority
    if (config->channelPriority == DMA_LOW) {
        clear_Bit(DMA->DMA_channel[channel].CCR, 12);
        clear_Bit(DMA->DMA_channel[channel].CCR, 13);
    } else if (config->channelPriority == DMA_MEDIUM) {
        set_Bit(DMA->DMA_channel[channel].CCR, 12);
        clear_Bit(DMA->DMA_channel[channel].CCR, 13);
    } else if (config->channelPriority == DMA_HIGH) {
        clear_Bit(DMA->DMA_channel[channel].CCR, 12);
        set_Bit(DMA->DMA_channel[channel].CCR, 13);
    } else if (config->channelPriority == DMA_VERY_HIGH) {
        set_Bit(DMA->DMA_channel[channel].CCR, 12);
        set_Bit(DMA->DMA_channel[channel].CCR, 13);
    }
}


void DMA_clearFlag(uint8_t channelNum, uint8_t flag){

	channelNum *=4;

	set_Bit(DMA->IFCR,(channelNum+flag));
}

void DMA_enable(uint8_t channelNum){

	DMA_clearFlag(channelNum, DMA_GIF);
	DMA_clearFlag(channelNum, DMA_TCIF);
	DMA_clearFlag(channelNum, DMA_HTIF);
	DMA_clearFlag(channelNum, DMA_TEIF);

	set_Bit(DMA->DMA_channel[channelNum].CCR,DMA_ENABLE);

}

void DMA_disable(uint8_t channelNum){

	clear_Bit(DMA->DMA_channel[channelNum].CCR,0);


}


void DMA_interruptConfig(uint8_t channelNum, uint8_t intSource, uint8_t intState){


	if(intState == DMA_ENABLE){

		set_Bit(DMA->DMA_channel[channelNum].CCR,intSource);
	}else{
		clear_Bit(DMA->DMA_channel[channelNum].CCR,intSource);
	}

}


void DMA_addressSetup(uint8_t channelNum, uint32_t* peripheralAddress, uint32_t* memoryAddress, uint16_t dataSize){


	DMA->DMA_channel[channelNum].CPAR = (uint32_t)peripheralAddress;
	DMA->DMA_channel[channelNum].CMAR = (uint32_t)memoryAddress;
	DMA->DMA_channel[channelNum].CNDTR = dataSize;


}

uint8_t DMA_readFlag(uint8_t channelNum,uint8_t flag){

	channelNum *=4;

	return get_Bit(DMA->ISR,(channelNum + flag));
}


static void DMA_ISRclearFlags(uint8_t channelNum){

	DMA_clearFlag(channelNum, DMA_GIF);
	DMA_clearFlag(channelNum, DMA_TCIF);
	DMA_clearFlag(channelNum, DMA_HTIF);
	DMA_clearFlag(channelNum, DMA_TEIF);
}

void DMA_setCallBack(uint8_t channelNum, callBack fptr){

	if(channelNum >= 0 && channelNum <7){
		if(fptr != NULL){

			callBackFunc[channelNum] = fptr;
		}
	}
}

void DMA1_Channel1_IRQHandler(){

	if(callBackFunc[CHANNEL1] != NULL){

		callBackFunc[CHANNEL1]();
	}

	DMA_ISRclearFlags(CHANNEL1);

}

void DMA1_Channel2_IRQHandler(){

	if(callBackFunc[CHANNEL2] != NULL){

		callBackFunc[CHANNEL2]();
	}

	DMA_ISRclearFlags(CHANNEL2);

}

void DMA1_Channel3_IRQHandler(){

	if(callBackFunc[CHANNEL3] != NULL){

		callBackFunc[CHANNEL3]();
	}

	DMA_ISRclearFlags(CHANNEL3);

}

void DMA1_Channel4_IRQHandler(){

	if(callBackFunc[CHANNEL4] != NULL){

		callBackFunc[CHANNEL4]();
	}

	DMA_ISRclearFlags(CHANNEL4);

}

void DMA1_Channel5_IRQHandler(){

	if(callBackFunc[CHANNEL5] != NULL){

		callBackFunc[CHANNEL5]();
	}

	DMA_ISRclearFlags(CHANNEL5);

}

void DMA1_Channel6_IRQHandler(){

	if(callBackFunc[CHANNEL6] != NULL){

		callBackFunc[CHANNEL6]();
	}

	DMA_ISRclearFlags(CHANNEL6);

}

void DMA1_Channel7_IRQHandler(){

	if(callBackFunc[CHANNEL7] != NULL){

		callBackFunc[CHANNEL7]();
	}

	DMA_ISRclearFlags(CHANNEL7);

}
