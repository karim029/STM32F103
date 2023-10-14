/*
 * UART_Interface.h
 *
 *  Created on: Oct 14, 2023
 *      Author: karim
 */

#ifndef INC_UART_INTERFACE_H_
#define INC_UART_INTERFACE_H_


#include "UART_Private.h"


#define USART_CLK		8000000U

/* UART Parity bit options
 *
 */

typedef enum{

	UART_PARITY_NONE,
	UART_PARITY_EVEN,
	UART_PARITY_ODD

}UART_Parity_t;

/*	UART stop bit number
 *
 */

typedef enum{

	UART_STOP_BIT_1,
	UART_STOP_BIT_0_5,
	UART_STOP_BIT_2,
	UART_STOP_BIT_1_5

}UART_stopBits_t;


/* UART DATA WORD LENGTHS
 *
 */

typedef enum{

	UART_WORD_8BIT,
	UART_WORD_9BIT

}UART_dataBits_t;


/* UART baud rate options
 *
 */
typedef enum{

	BAUD_RATE_9600,
	BAUD_RATE_115200,
	BAUD_RATE_57600,
	BAUD_RATE_38400

}UART_baudRate_t;

/*
 *  UART flow control modes
 *
 */
typedef enum{

	UART_FC_NONE,
	UART_FC_RTS,
	UART_FC,CTS,
	UART_FC_RTS_CTS

}UART_flowControl_t;

typedef struct{

	uint8_t hwFlowControl:2;
	uint8_t parityMode:2;
	uint8_t baudRate:2;
	uint8_t stopBits:2;
	uint8_t wordLength:1;
	uint8_t :7; //padding

}UARTx_config_t;



/* API functions */

USART_reg_t* USART_getBaseAddress(USARTx_t usart);
void UART_receive(USART_reg_t* copyUsart, uint8_t *data, uint16_t size);
void UART_transmit(USART_reg_t* copyUsart, uint8_t *data, uint16_t size);
void UART_init(USART_reg_t* copyUsart, UARTx_config_t* config);





#endif /* INC_UART_INTERFACE_H_ */
