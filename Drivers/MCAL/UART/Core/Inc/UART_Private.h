/*
 * UART_Private.h
 *
 *  Created on: Oct 14, 2023
 *      Author: karim
 */

#ifndef INC_UART_PRIVATE_H_
#define INC_UART_PRIVATE_H_

#define USART1_BASE_ADDRESS  0x40013800U
#define USART2_BASE_ADDRESS  0x40004400U
#define USART3_BASE_ADDRESS  0x40004800U
#define NULL ((void*)0)
typedef enum{

	USART1,
	USART2,
	USART3

}USARTx_t;


typedef struct{

	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t GTPR;
}
USART_reg_t;

USART_reg_t* USART_getBaseAddress(USARTx_t usart){

	switch(usart){

	case USART1: return (USART_reg_t*)USART1_BASE_ADDRESS; break;
	case USART2: return (USART_reg_t*)USART2_BASE_ADDRESS; break;
	case USART3: return (USART_reg_t*)USART3_BASE_ADDRESS; break;
	default:	 return NULL;							   break;

	}
}


/*USART status register */
#define SR_TXE     				0x00000080 //Transmit data register empty
#define SR_TC         		    0x00000040 /**< Transmission complete */
#define SR_RXNE      			0x00000020 /**< Read data register not empty */
#define SR_IDLE       			0x00000010 /**< IDLE line detected */
#define SR_ORE       			0x00000008 /**< Overrun error */
#define SR_NE         			0x00000004 /**< Noise error flag */
#define SR_FE         			0x00000002 /**< Framing error */
#define SR_PE         			0x00000001 /**< Parity error */

/*USART control register 1  */
#define CR1_UE        			0x00002000 /**< USART enable */
#define CR1_M         			0x00001000 /**< Word length */
#define CR1_PCE       			0x00000400 /**< Parity control enable */
#define CR1_PS       			0x00000200 /**< Parity selection */
#define CR1_PEIE     			0x00000100 /**< PE interrupt enable */
#define CR1_TXEIE    			0x00000080 /**< TXE interrupt enable */
#define CR1_TCIE    			0x00000040 /**< Transmission complete interrupt enable */
#define CR1_RXNEIE    			0x00000020 /**< RXNE interrupt enable */
#define CR1_IDLEIE    			0x00000010 /**< IDLE interrupt enable */
#define CR1_TE        			0x00000008 /**< Transmitter enable */
#define CR1_RE        			0x00000004 /**< Receiver enable */
#define CR1_RWU       			0x00000002 /**< Receiver wakeup */
#define CR1_SBK       			0x00000001 /**< Send break */

/*USART control register 2  */

#define CR2_LINEN     			0x00004000 /**< LIN mode enable */
#define CR2_STOP      			0x00003000 /**< STOP bits */
#define CR2_CLKEN     			0x00000400 /**< Clock enable */
#define CR2_CPOL      			0x00000200 /**< Clock polarity */
#define CR2_CPHA      			0x00000100 /**< Clock phase */
#define CR2_LBCL      			0x00000080 /**< Last bit clock pulse */
#define CR2_LBDIE     			0x00000040 /**< LIN break detection interrupt enable */
#define CR2_LBDL      			0x00000020 /**< LIN break detection length */
#define CR2_ADD       			0x0000000F /**< Address of the USART node */

/*USART control register 3  */

#define CR3_ONEBIT    			0x00008000 /**< One sample bit method enable */
#define CR3_CTSIE     			0x00000400 /**< CTS interrupt enable */
#define CR3_CTSE     			0x00000200 /**< CTS enable */
#define CR3_RTSE     			0x00000100 /**< RTS enable */
#define CR3_DMAT    		 	0x00000080 /**< DMA enable transmitter */
#define CR3_DMAR     			0x00000040 /**< DMA enable receiver */
#define CR3_SCEN      			0x00000020 /**< Smartcard mode enable */
#define CR3_NACK      			0x00000010 /**< Smartcard NACK enable */
#define CR3_HDSEL     			0x00000008 /**< Half-duplex selection */
#define CR3_IRLP      			0x00000004 /**< IrDA low-power */
#define CR3_IREN      			0x00000002 /**< IrDA mode enable */
#define CR3_EIE       			0x00000001 /**< Error interrupt enable */

#endif /* INC_UART_PRIVATE_H_ */
