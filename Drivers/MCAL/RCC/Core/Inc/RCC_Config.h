/*
 * RCC_Config.h
 *
 *  Created on: Sep 24, 2023
 *      Author: karim
 */

#ifndef INC_RCC_CONFIG_H_
#define INC_RCC_CONFIG_H_



#include "../Inc/RCC_Interface.h"



/*HSI as SYSCLK*/
#define ENABLE_HSI				0

/* HSE as SYSCLK*/
#define ENABLE_HSE				0

/* PPL as SYSCLK*/
#define ENABLE_PLL 				1


#if(ENABLE_PLL)

/*
 *  choose PLL clock Source in RCC_Interface.h from enum PLLSRC
 *  possible values half_HSI
 *  				half_HSE
 *  				HSE
 *
 */

#define PLL_CLK_SOURCE			HSE

/*
 *  choose multiplication factor in RCC_Interface.h from PLLMUL enum
 *	possible values are down below
 */
/*
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
	PLL_input_clock_x16,

 */

#define PLL_MULTIPLICATION_FACTOR	PLL_input_clock_x16
#endif


#define ENABLE_LSI 			0
/*
 *  low speed internal RC (40khz)
 *  used to drive the IWD and optionally the RTCCLK
 */


#define ENABLE_LSE			0
/*
 *  low speed external crystal (32.768khz)
 *  can drive the RTCCLK
 *
 */

#define ENABLE_RTC			0

#define ENABLE_AHB 			0

#if(ENABLE_AHB)
/*
 *  choose prescaler value from the enum AHB_prescaler in RCC_Interface.h
 *  possible values down below
 */
/*
 AHB_SYSCLK_not_divided,
	AHB_SYSCLK_divided_2 = 8,
	AHB_SYSCLK_divided_4,
	AHB_SYSCLK_divided_8,
	AHB_SYSCLK_divided_16,
	AHB_SYSCLK_divided_64,
	AHB_SYSCLK_divided_128,
	AHB_SYSCLK_divided_256,
	AHB_SYSCLK_divided_512


 */
#define AHB_PRESCALER 		AHB_SYSCLK_not_divided
#endif

#define ENABLE_APB1		0

#if(ENABLE_APB1)

/*
 *  choose prescaler value from the enum APB1_prescaler in RCC_Interface.h
 *  possible values down below
 */


/*
APB1_HCLK_not_divided,
	APB1_HCLK_divided_2 = 4,
	APB1_HCLK_divided_4,
	APB1_HCLK_divided_8,
	APB1_HCLK_divided_16
 */

#define APB1_PRESCALER		APB1_HCLK_not_divided
#endif

#define ENABLE_APB2						0
#if(ENABLE_APB2)
/*
 *  choose prescaler value from the enum APB2_prescaler in RCC_Interface.h
 *  possible values down below
 */
/*
APB2_HCLK_not_divided,
	APB2_HCLK_divided_2,
	APB2_HCLK_divided_4,
	APB2_HCLK_divided_8,
	APB2_HCLK_divided_16
 */
#define APB2_PRESCALER			APB2_HCLK_not_divided
#endif


#define ENABLE_MCO				0
#if(ENABLE_MCO)
/*
 *  choose prescaler value from the enum MCO_prescaler in RCC_Interface.h
 *  possible values down below
 */

/*
 MCO_No_clock,
	MCO_SYSCLK_selected = 4,
	MCO_HSI_selected,
	MCO_HSE_selected,
	MCO_PLL_div_2_selected
 */
#define MCO_PRESCALER	   MCO_PLL_div_2_selected
#endif



#define ENABLE_ADC_CLK		0
#if(ENABLE_ADC_CLK)

/*
 * choose prescaler value from the enum ADC_prescaler in RCC_Interface.h
 *  possible values down below
 */

/*
 	ADC_PCLK2_divided_2,
	ADC_PCLK2_divided_4,
	ADC_PCLK2_divided_6,
	ADC_PCLK2_divided_8
 */
#define ADC_PRESCALER 			ADC_PCLK2_divided_2
#endif


#define ENABLE_USB_CLK		0
#if(ENABLE_USB_CLK)
/*
 * choose prescaler value from the enum USB_prescaler in RCC_Interface.h
 *  possible values down below
 */

/*
 USB_PLL_clock_divided_by_oneHalf,
	USB_PLL_not_dividedx
 */
#define USB_PRESCALER 		USB_PLL_not_divided
#endif
#endif /* INC_RCC_CONFIG_H_ */
