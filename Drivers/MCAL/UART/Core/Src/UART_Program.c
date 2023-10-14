/*
 * UART_Program.c
 *
 *  Created on: Oct 14, 2023
 *      Author: karim
 */


// std lib
#include "types.h"
#include "bit_math.h"

//MCAL
#include "UART_Interface.h"
#include "UART_Private.h"

static void UART_parityMode(USART_reg_t* copyUsart, UARTx_config_t* config){
	if(config->parityMode == UART_PARITY_NONE)clear_Bit(copyUsart->CR1,10);
		else if(config->parityMode == UART_PARITY_EVEN){
			set_Bit(copyUsart->CR1,10);
			clear_Bit(copyUsart->CR1,9);

		}
		else if(config->parityMode == UART_PARITY_ODD){
				set_Bit(copyUsart->CR1,10);
				set_Bit(copyUsart->CR1,9);

		}
}



static void UART_wordLength(USART_reg_t* copyUsart, UARTx_config_t* config){

	if(config->wordLength == UART_WORD_8BIT)clear_Bit(copyUsart->CR1,12);
		else if(config->wordLength == UART_WORD_9BIT)set_Bit(copyUsart->CR1,12);
}

static void UART_hwFlowControl(USART_reg_t* copyUsart, UARTx_config_t* config){

	if (config->hwFlowControl == UART_FC_NONE)
	  {
		/**< Configure no hardware flow control */
		copyUsart->CR3 &= ~(CR3_RTSE | CR3_CTSE); /**< Clear the RTSE and CTSE bits for no hardware flow control */
	  }
	  else if (config->hwFlowControl == UART_FC_RTS)
	  {
		/**< Configure RTS (Request to Send) hardware flow control */
		  copyUsart->CR3 |= CR3_RTSE;    /**< Set the RTSE bit for RTS hardware flow control */
		  copyUsart->CR3 &= ~CR3_CTSE;   /**< Clear the CTSE bit */
	  }
	  else if (config->hwFlowControl == UART_FC_RTS_CTS)
	  {
		/**< Configure CTS (Clear to Send) hardware flow control */
		  copyUsart->CR3 |= CR3_CTSE;      /**< Set the CTSE bit for CTS hardware flow control */
		  copyUsart->CR3 &= ~CR3_RTSE;     /**< Clear the RTSE bit */
	  }
	  else if (config->hwFlowControl == UART_FC_RTS_CTS)
	  {
		/**< Configure RTS and CTS hardware flow control */
		  copyUsart->CR3 |= CR3_RTSE | CR3_CTSE; /**< Set both RTSE and CTSE bits for RTS and CTS hardware flow control */
	  }
}


static void UART_baudRate(USART_reg_t* copyUsart, UARTx_config_t* config){
	/*Calculate the value of the USARTDIV register based on the desired baud rate */

	float32_t usartDIV = (float32_t)USART_CLK/(16*config->baudRate);

	//calculate mantissa (int) and the floaat part of usartDiv

	uint16_t divMantissa = (uint16_t)usartDIV; // take the int part of the value
	uint16_t divFraction = (uint16_t)(((usartDIV - divMantissa)*16)+0.5);

	//check if the fraction part needs carrying

	uint8_t carry = 0;
	if(divFraction >= 16){
		divFraction -=16;
		carry =1;
	}

	if(carry){

		divMantissa +=1;
	}

		copyUsart->BRR = (divMantissa << 4) | divFraction;

}

void UART_init(USART_reg_t* copyUsart, UARTx_config_t* config){

	// config word length
	UART_wordLength(copyUsart,config);

	//config stop bits
	copyUsart->CR2 &= ~CR2_STOP; // clear the stop bits value
	copyUsart->CR2 |= config->stopBits; // set the stop bits

	// config partiy mode
	UART_parityMode(copyUsart, config);

	// config the hardware flow control
	UART_hwFlowControl(copyUsart, config);

	// baud rate calculation and config

	UART_baudRate(copyUsart, config);

	//enable UART

	copyUsart->CR1 |= CR1_UE;


}




void UART_transmit(USART_reg_t* copyUsart, uint8_t *data, uint16_t size){

	//wait until transmit buffer is empty
	while(!(copyUsart->SR & SR_TXE));

	for(uint16_t i = 0; i<size; i++){

		copyUsart->DR = data[i];

		//wait until transmission is complete
		while(!(copyUsart->SR & SR_TC));
	}

}


void UART_receive(USART_reg_t* copyUsart, uint8_t *data, uint16_t size){

	 for (uint16_t i = 0; i < size; i++)
	  {
	    /**< Wait until data is available to receive */
	    while (!(copyUsart->SR & SR_RXNE));

	    /**< Receive one byte of data */
	    data[i] = copyUsart->DR;
	  }


}
