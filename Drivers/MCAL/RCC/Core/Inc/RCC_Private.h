/*
 * RCC_Private.h
 *
 *  Created on: Sep 24, 2023
 *      Author: karim
 */

#ifndef INC_RCC_PRIVATE_H_
#define INC_RCC_PRIVATE_H_

//STM32F103XX register size is 32bit
#define REGISTER_SIZE 32

//Mapping for the peripherals and their corresponding bus
/*
 * will be used in functions to select the correct peripheral
 *
 */
#define PERIPHERAL_RCC_APB2RSTR (peripheral_ID <32)

#define PERIPHERAL_RCC_APB1RSTR (peripheral_ID <64)

#define PERIPHERAL_RCC_AHBENR (peripheral_ID <32)

#define PERIPHERAL_RCC_APB2ENR (peripheral_ID <64)

#define PERIPHERAL_RCC_APB1ENR (peripheral_ID <94)
/*********************
 *    RCC_CR bits    *
 ********************/

enum RCC_CR{

	HSION,
	HSIRDY,
	HSITRIM0 = 3,
	HSITRIM1,
	HSITRIM2,
	HSITRIM3,
	HSITRIM4,
	HSICAL0,
	HSICAL1,
	HSICAL2,
	HSICAL3,
	HSICAL4,
	HSICAL5,
	HSICAL6,
	HSICAL7,
	HSEON,
	HSERDY,
	HSEBYP,
	CSSON,
	PLLON = 24,
	PLLRDY,


};

/*********************
 *    RCC_CFGR bits  *
 ********************/

enum RCC_CFGR{

	SW0,
	SW1,
	SWS0,
	SWS1,
	HPRE0,
	HPRE1,
	HPRE2,
	HPRE3,
	PPRE10,
	PPRE11,
	PPRE12,
	PPRE20,
	PPRE21,
	PPREE22,
	ADCPRE0,
	ADCPRE1,
	PLLSRC,
	PLLXTPRE,
	PLLMUL0,
	PLLMUL1,
	PLLMUL2,
	PLLMUL3,
	USBPRE,
	MCO0 = 24,
	MCO1,
	MCO2

};

/*********************
 *    RCC_CIR bits    *
 ********************/
enum RCC_CIR{

	LSIRDYF,
	LSERDYF,
	HSIRDYF,
	HSERDYF,
	PLLRDYF,
	CSSF = 7,
	LSIRDYIE,
	LSERDYIE,
	HSIRDYIE,
	HSERDYIE,
	PLLRDYIE,
	LSIRDYC=16,
	LSERDYC,
	HSIRDYC,
	HSERDYC,
	PLLRDYC,
	CSSC = 23


};

/*********************
 *    RCC_BDCR bits  *
 ********************/

enum RCC_BDCR{
	LSEON,
	LSERDY,
	LSEBYP,
	RTCSEL0 = 8,
	RTCSEL1,
	RTCEN = 15,
	BDRST

};

/*********************
 *    RCC_CSR bits   *
 ********************/

enum RCC_CSR{
	LSION,
	LSIRDY,
	RMVF = 24,
	PINRSTF = 26,
	PORRSTF,
	SFTRSTF,
	IWDGRSTF,
	WWDGRSTF,
	LPWRRSTF,


};
#endif /* INC_RCC_PRIVATE_H_ */
