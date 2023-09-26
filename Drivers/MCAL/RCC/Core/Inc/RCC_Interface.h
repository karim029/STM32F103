/*
 * RCC_Interface.h
 *
 *  Created on: Sep 24, 2023
 *      Author: karim
 */




#ifndef INC_RCC_INTERFACE_H_
#define INC_RCC_INTERFACE_H_


#include "bit_math.h"


/************************
 * 	  RCC REGISTERS     *
 ************************/
#define RCC_BASE_ADDRESS (0x40021000)

/*
 * these are memory mapped registers with fixed offset of 4 bytes
 * we will use a pointer of type RCC_Regsiters_t to access each register with the correct memory address
 */
typedef struct {

	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_AHBENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;


}RCC_Registers_t;

// pointer to rcc struct that contains the registers
// it points to the base memory location for the stm32f103xx family

#define RCC ((RCC_Registers_t*)(RCC_BASE_ADDRESS))

/******************
 * MCO prescaling *
 * 		and       *
 * 	clock source  *
 *                *
 *****************/

enum MCO_prescaler{
	MCO_No_clock,
	MCO_SYSCLK_selected = 4,
	MCO_HSI_selected,
	MCO_HSE_selected,
	MCO_PLL_div_2_selected

};

/******************
 * PLL CLK Source *
 *****************/

// THESE BITS CAN ONLY BE WRITTEN WHEN PLL IS DISBALED
enum PLLSRC{

	half_HSI,
	half_HSE,
	HSE

};

/******************
 * PLL MUL FACTOR *
 *****************/

// bits should be written when pll is disabled
// pll output freq must not exceed 72mhz
enum PLLMUL{

	PLL_input_clock_x2,
	PLL_input_clock_x3,
	PLL_input_clock_x4,
	PLL_input_clock_x5,
	PLL_input_clock_x6,
	PLL_input_clock_x7,
	PLL_input_clock_x8,
	PLL_input_clock_x9,
	PLL_input_clock_x10,
	PLL_input_clock_x11,
	PLL_input_clock_x12,
	PLL_input_clock_x13,
	PLL_input_clock_x14,
	PLL_input_clock_x15,
	PLL_input_clock_x16
};

/*
 *  control the division factor for the AHB clk
 */
enum AHB_prescaler{
	AHB_SYSCLK_not_divided,
	AHB_SYSCLK_divided_2 = 8,
	AHB_SYSCLK_divided_4,
	AHB_SYSCLK_divided_8,
	AHB_SYSCLK_divided_16,
	AHB_SYSCLK_divided_64,
	AHB_SYSCLK_divided_128,
	AHB_SYSCLK_divided_256,
	AHB_SYSCLK_divided_512
};


enum APB1_prescaler{

	APB1_HCLK_not_divided,
	APB1_HCLK_divided_2 = 4,
	APB1_HCLK_divided_4,
	APB1_HCLK_divided_8,
	APB1_HCLK_divided_16
};

enum APB2_prescaler{
	APB2_HCLK_not_divided,
	APB2_HCLK_divided_2 = 4,
	APB2_HCLK_divided_4,
	APB2_HCLK_divided_8,
	APB2_HCLK_divided_16
};

enum ADC_prescaler{
	ADC_PCLK2_divided_2,
	ADC_PCLK2_divided_4,
	ADC_PCLK2_divided_6,
	ADC_PCLK2_divided_8
};

enum USB_prescaler{

	USB_PLL_clock_divided_by_oneHalf,
	USB_PLL_not_divided
};

/*********************
 * RCC_APB2RSTR bits *
 ********************/

enum RCC_APB2RSTR{
	AFIORST,
	IOPARST = 2,
	IOPBRST,
	IOPCRST,
	IOPDRST,
	IOPERST,
	IOPFRST,
	IOPGRST,
	ADC1RST,
	ADC2RST,
	TIM1RST,
	SPI1RST,
	TIM8RST,
	USART1RST,
	ADC3RST,
	TIM9RST = 19,
	TIM10RST,
	TIM11RST
};

/*********************
 * RCC_APB1RSTR bits *
 ********************/
enum RCC_APB1RSTR{
	TIM2RST = 32,
	TIM3RST,
	TIM4RST,
	TIM5RST,
	TIM6RST,
	TIM7RST,
	TIM12RST,
	TIM13RST,
	TIM14RST,
	WWDGRST = 43,
	SPI2RST = 46,
	SPI3RST,
	USART2RST = 49,
	USASRT3RST,
	UART4RST,
	UART5RST,
	I2C1RST,
	I2C2RST,
	USBRST,
	CANRST = 57,
	BKPRST = 59,
	PWRRST,
	DACRST

};
/*********************
 * RCC_AHBENR bits   *
 ********************/

enum RCC_AHBENR{
	DMA1EN,
	DMA2EN,
	SRAMEN,
	FLITFEN = 4,
	CRCEN = 6,
	FSMCEN = 8,
	SDIOEN = 10
};


/*******************
 * RCC_APB2ENR bits*
 ******************/

enum RCC_APB2ENR{

	AFIOEN = 32,
	IOPAEN = 34,
	IOPBEN,
	IOPCEN,
	IOPDEN,
	IOPEEN,
	IOPFEN,
	IOPGEN,
	ADC1EN,
	ADC2EN,
	TIM1REN,
	SPI1EN,
	TIM8EN,
	USART1EN,
	ADC3EN,
	TIM9EN = 51,
	TIM10EN,
	TIM11EN
};
/*******************
 * RCC_APB1ENR bits*
 ******************/
enum RCC_APB1ENR{
	TIM2EN = 64,
	TIM3EN,
	TIM4EN,
	TIM5EN,
	TIM6EN,
	TIM7EN,
	TIM12EN,
	TIM13EN,
	TIM14EN,
	WWDGEN = 75,
	SPI2EN = 78,
	SPI3EN,
	USART2EN = 81,
	USART3EN,
	UART4EN,
	UART5EN,
	I2C1EN,
	I2C2EN,
	USBEN,
	CANEN = 89,
	BKPEN = 91,
	PWREN,
	DACEN
};


/*********************************
 *                               *
 * API FUNCTIONS FOR USER TO USE *
 *                               *
 ********************************/

/* Function name: RCC_clearResetFlag
 * (Input): None
 * (Output): None
 *
 * Clears the Reset Flag in the CSR register
 */
void RCC_clearResetFlag();

/* Function name: RCC_resetModule
 * (Input): peripheral_ID Choose the disered peripheral
 * from enum RCC_APB1ENR and enum RCC_APB2ENR
 *
 * YOU SHOULD USE THE ENUMS ONLY IN ORDER FOR THE FUNCTION TO WORK CORRECTLY
 *
 * (Output): None
 *
 * Resets the HW module
 */
void RCC_resetModule(uint8_t peripheral_ID);


/* Function name: RCC_enableClock
 *
 * (Input): peripheral_ID Choose the disered peripheral
 * from enum RCC_APB2ENR and enum RCC_APB1ENR and enum RCC_AHBENR in the interface file
 *
 * YOU SHOULD USE THE ENUMS ONLY IN ORDER FOR THE FUNCTION TO WORK CORRECTLY
 *
 * (Output): None
 *
 * Enable the peripheral desired
 */

void RCC_enableClock(uint8_t peripheral_ID);



/* Function name: RCC_disableClock
 *
 * (Input): peripheral_ID Choose the disered peripheral
 * from enum RCC_APB1ENR and enum RCC_APB2ENR and enum RCC_AHBENR in the interface file
 *
 * YOU SHOULD USE THE ENUMS ONLY IN ORDER FOR THE FUNCTION TO WORK CORRECTLY
 *
 * (Output): None
 *
 * disable the peripheral desired
 */

void RCC_disableClock(uint8_t peripheral_ID);



/* Function name: RCC_Config
 *
 * (Input): None
 *
 * (Output): None
 *
 * initialize the system clock (modes and prescaler)
 * the initialization is based on your configuration in the RCC_Config.h file
 * enable or disable the types of clocks and choose the correct prescaler before calling this function
 *
 */

void RCC_Config();


#endif /* INC_RCC_INTERFACE_H_ */
