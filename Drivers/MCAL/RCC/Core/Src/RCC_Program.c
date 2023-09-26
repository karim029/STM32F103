/*
 * RCC_Program.c
 *
 *  Created on: Sep 24, 2023
 *      Author: karim
 */

#include "types.h"
#include "../Inc/bit_math.h"
#include "../Inc/RCC_Interface.h"
#include "../Inc/RCC_Config.h"
#include "../Inc/RCC_Private.h"


void RCC_enableHSI_8MHZ(){

	set_Bit(RCC->RCC_CR,HSION); // SET HSION bit in RCC_CR to select HSI clk
	while(!get_Bit(RCC->RCC_CR,HSIRDY)); // POLL UNTIL HSIRDY is 1
	set_Bit(RCC->RCC_CIR,HSIRDYC); // CLEAR HSIRDYF flag
	clear_Bit(RCC->RCC_CFGR,SW0); // clear sw0 to select hsi as sysclk
	clear_Bit(RCC->RCC_CFGR,SW1); // clear sw1 to select hsi as sysclk

}

void RCC_enableHSE(){

	set_Bit(RCC->RCC_CR,HSEON);// enable HSEON BIT
	while(!get_Bit(RCC->RCC_CR,HSERDY)); // pol until HSERDY is set
	set_Bit(RCC->RCC_CIR,HSERDYC); //clear HSERDY flag
	set_Bit(RCC->RCC_CFGR,SW0);//select HSE as SYSCLK
	clear_Bit(RCC->RCC_CFGR,SW1);

}

void RCC_enablePLL(uint8_t PLL_CLKsource,uint8_t PLL_value){

	set_Bit(RCC->RCC_CR,PLLON);//enable pll
	while(!get_Bit(RCC->RCC_CR,PLLRDY)); // poll until pll is ready
	set_Bit(RCC->RCC_CIR,PLLRDYC); //clear PLLRDY flag
	switch(PLL_CLKsource){

	case half_HSI:
		clear_Bit(RCC->RCC_CFGR,PLLSRC);
		break;
	case half_HSE:
		set_Bit(RCC->RCC_CFGR,PLLSRC);
		set_Bit(RCC->RCC_CFGR,PLLXTPRE);
		break;
	case HSE:
		set_Bit(RCC->RCC_CFGR,PLLSRC);
		clear_Bit(RCC->RCC_CFGR,PLLXTPRE);
		break;

	}

	//mask the cfgr register to reset the multiplication bits
			// and add the pl multiplication value

			RCC->RCC_CFGR &= ( 0xFFC3FFFF) | (PLL_value<<PLLMUL0);
}



void RCC_enableLSI(){

	set_Bit(RCC->RCC_CSR,LSION); // enable LSI
	while(!get_Bit(RCC->RCC_CSR,LSIRDY)); // poll until clk is ready
	set_Bit(RCC->RCC_CIR,LSIRDYC); // clear the flag
	//select the clock source for RTC
	clear_Bit(RCC->RCC_BDCR,RTCSEL0);
	set_Bit(RCC->RCC_BDCR,RTCSEL1);


}

void RCC_enableLSE(){
	set_Bit(RCC->RCC_BDCR,LSEON); // enable LSE
	while(!get_Bit(RCC->RCC_BDCR,LSERDY)); // poll until LSE ready
	set_Bit(RCC->RCC_CIR,LSERDYC); // clear flag
	//select the clock source for RTC
	set_Bit(RCC->RCC_BDCR,RTCSEL0);
	clear_Bit(RCC->RCC_BDCR,RTCSEL1);

}

void RCC_enableRTC(){

	set_Bit(RCC->RCC_BDCR,RTCEN); //enable RTC
}

void RCC_MCO_CLK(uint8_t MCO_CLKsource){
	//set the microcontroller clock output

	RCC->RCC_CFGR &= (0xF8FFFFFF)|(MCO_CLKsource << MCO0);

}


void RCC_AHB_prescaler(uint8_t AHB_prescalerVal){

	// SET THE AHB CLOCK PRESCALER VALUE
	RCC->RCC_CFGR &= (0XFFFFFF0F)|(AHB_prescalerVal <<HPRE0);

}


void RCC_APB1_prescaler(uint8_t APB1_prescalerVal){
	// SET THE APB1 CLOCK PRESCALER VALUE
	RCC->RCC_CFGR &= (0xFFFFF8FF) | (APB1_prescalerVal << PPRE10);

}

void RCC_APB2_prescaler(uint8_t APB2_prescalerVal){
	// SET THE APB2 CLOCK PRESCALER VALUE
	RCC->RCC_CFGR &= (0xFFFFC7FF) | (APB2_prescalerVal << PPRE20);

}

void RCC_ADC_prescaler(uint8_t ADC_prescalerVal){
	// SET THE ADC CLOCK PRESCALER VALUE
	RCC->RCC_CFGR &=  (0xFFFF3FFF) | (ADC_prescalerVal<<ADCPRE0);

}

void RCC_USB_prescaler(uint8_t USB_prescalerVal){
	// SET THE USB CLOCK PRESCALER VALUE
	RCC->RCC_CFGR &=  (0xFFBFFFFF) | (USB_prescalerVal<<USBPRE);

}

void RCC_resetModule(uint8_t peripheral_ID){

	if(PERIPHERAL_RCC_APB2RSTR){ // check if the desired peripheral is in the register APB2RSRTR
		set_Bit(RCC->RCC_APB2RSTR,peripheral_ID); // RESET THE MODULE
	}else if(PERIPHERAL_RCC_APB2RSTR){
		//map the id to be within the 32 range
		// peripheral_ID = peripheral_ID -32
		peripheral_ID %= REGISTER_SIZE;
		//reset the desired module
		set_Bit(RCC->RCC_APB1RSTR, peripheral_ID);

	}

}


void RCC_clearResetFlag(){

	set_Bit(RCC->RCC_CSR,RMVF); // CLEAR THE RESET FLAG
}



void RCC_enableClock(uint8_t peripheral_ID){
	if(PERIPHERAL_RCC_AHBENR){
		set_Bit(RCC->RCC_AHBENR,peripheral_ID);
	}
	else if(PERIPHERAL_RCC_APB2ENR){
		peripheral_ID %= REGISTER_SIZE;
		set_Bit(RCC->RCC_APB2ENR,peripheral_ID);
	}
	else if(PERIPHERAL_RCC_APB1ENR){
		peripheral_ID %= REGISTER_SIZE;
		set_Bit(RCC->RCC_APB1ENR,peripheral_ID);

	}

}

void RCC_disableClock(uint8_t peripheral_ID){
	if(PERIPHERAL_RCC_AHBENR){
		clear_Bit(RCC->RCC_AHBENR,peripheral_ID);
	}
	else if(PERIPHERAL_RCC_APB2ENR){
		peripheral_ID %= REGISTER_SIZE;
		clear_Bit(RCC->RCC_APB2ENR,peripheral_ID);
	}
	else if(PERIPHERAL_RCC_APB1ENR){
		peripheral_ID %= REGISTER_SIZE;
		clear_Bit(RCC->RCC_APB1ENR,peripheral_ID);

	}

}



void RCC_Config(){

#if(ENABLE_HSI)
	RCC_enableHSI_8MHZ();


#elif(ENABLE_HSE)
	RCC_enableHSE();

#elif(ENABLE_PLL)
	RCC_enablePLL(PLL_CLK_SOURCE, PLL_MULTIPLICATION_FACTOR);
#endif

#if(ENABLE_LSI)
	RCC_enableLSI();
#endif

#if(ENABLE_LSE)
	RCC_enableLSE();
#endif

#if(ENABLE_RTC)
	RCC_enableRTC();
#endif

#if(ENABLE_AHB)
	RCC_AHB_prescaler(AHB_PRESCALER);
#endif

#if(ENABLE_APB1)
	RCC_APB1_prescaler(APB1_PRESCALER);
#endif

#if(ENABLE_APB2)
	RCC_APB2_prescaler(APB2_PRESCALER);
#endif


#if(ENABLE_ADC_CLK)
	RCC_ADC_prescaler(ADC_PRESCALER);

#endif

#if(ENABLE_MCO)
	RCC_MCO_CLK(MCO_PRESCALER);
#endif
#if(ENABLE_USB_CLK)
	RCC_USB_prescaler(USB_PRESCALER);
#endif
}
