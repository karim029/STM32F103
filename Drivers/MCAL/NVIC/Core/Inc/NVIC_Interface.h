/*
 * NVIC_Interface.h
 *
 *  Created on: Sep 30, 2023
 *      Author: karim
 */

#ifndef INC_NVIC_INTERFACE_H_
#define INC_NVIC_INTERFACE_H_

#define NVIC_BASE_ADDRESS 			0xE000E100
#define NVIC_STIR_BASE_ADDRESS		0xE000EF00

// each element in the struct has the correct address with the correct Offset
typedef struct{

	volatile uint32_t ISER		[32]; // Interrupt Set Enable Registers
	volatile uint32_t ICER		[32]; // Interrupt clear Enable Registers
	volatile uint32_t ISPR		[32]; // Interrupt Set Pending Registers
	volatile uint32_t ICPR		[32]; // Interrupt Clear Pendign Registers
	volatile uint32_t IABR		[32]; // Interrupt Active Bit Registers
	volatile uint32_t RESERVED	[32]; // Reserved for padding so the next element in the struct is IPR
	volatile uint8_t  IPR		[128]; // Interrupt priority Registers


}NVIC_t;

// POinter that points to the NVIC Registers
#define NVIC ((volatile NVIC_t*)NVIC_BASE_ADDRESS)


//Pointer that points to Software Interrupt trigger register
/*
 * not included inside the struct because it is located in another block
 */
#define STIR ((volatile u32*)NVIC_STIR_BASE_ADDRESS)


typedef struct{

	volatile uint32_t CPUID; // CPU ID base Register
	volatile uint32_t ICSR;  // Interrupt Control and State Register
	volatile uint32_t VTOR;  // Vector Table Offset Register
	volatile uint32_t AIRCR; // Application Interrupt and Reset Control Register
	volatile uint32_t SCR;   // System Control Register
	volatile uint32_t CCR;	 // Configuration and Control Register
	volatile uint32_t SHPR1; // System Handler Priority register 1
	volatile uint32_t SHPR2; // System Handler Priority register 2
	volatile uint32_t SHPR3; // System Handler Priority register 3
	volatile uint32_t SHCSR; // system Handler Control and State register
	volatile uint32_t CFSR;  // Configurable Fault Status register
	volatile uint32_t HFSR;  // Hard Fault Status register
	volatile uint32_t RESERVED; // Reserved for correct Registers offset addresses
	volatile uint32_t MMFAR; // Memory management fault address register
	volatile uint32_t BFAR;  // Bus fault address register


}SCB_t;

//pointer  to points to system control block Registers
#define SCB ((volatile SCB_t*)0xE000ED00)




/*GROUPS FOR PRIORITY AND SUBPRIORITY*/
#define NVIC_16GROUP_0SUB   0x05FA0300 /**< 16 Priority Levels, No Sub-priority */
#define NVIC_8GROUP_2SUB    0x05FA0400 /**< 8 Priority Levels, 2 Sub-priority Levels */
#define NVIC_4GROUP_4SUB    0x05FA0500 /**< 4 Priority Levels, 4 Sub-priority Levels */
#define NVIC_2GROUP_8SUB    0x05FA0600 /**< 2 Priority Levels, 8 Sub-priority Levels */
#define NVIC_0GROUP_16SUB   0x05FA0700 /**< No Grouping, 16 Sub-priority Levels */




/*!< Interrupt Number Definition */
typedef enum
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
 NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
 HardFault_IRQn              = -13,    /*!< 3 Cortex-M3 Hard Fault Interrupt                     */
 MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt              */
 BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                      */
 UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                    */
 SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                       */
 DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                 */
 PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                       */
 SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                   */

/******  STM32 specific Interrupt Numbers *********************************************************/
 WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                            */
 PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt            */
 TAMPER_IRQn                 = 2,      /*!< Tamper Interrupt                                     */
 RTC_IRQn                    = 3,      /*!< RTC global Interrupt                                 */
 FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                               */
 RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                 */
 EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                 */
 EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                 */
 EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                 */
 EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                 */
 EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                 */
 DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                      */
 DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                      */
 DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                      */
 DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                      */
 DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                      */
 DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                      */
 DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                      */
 ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
 CAN1_TX_IRQn		         = 19,     /*!< CAN1 TX Interrupts       							 */
 CAN1_RX0_IRQn		         = 20,     /*!< CAN1 RX0 Interrupts       							 */
 CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
 CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
 EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
 TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                 */
 TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                */
 TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
 TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
 TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
 TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
 TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
 I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
 I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
 I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
 I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
 SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
 SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
 USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
 USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
 USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
 EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
 RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
 USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
 TIM5_IRQn					 = 50,     /*!< TIM5 global Interrupt  								 */
 SPI3_IRQn					 = 51,     /*!< SPI3 global Interrupt 								 */
 UART4_IRQn					 = 52,     /*!< UART4 global Interrupt 								 */
 UART5_IRQn					 = 53,     /*!< UART5 global Interrupt 							     */
 TIM6_IRQn					 = 54,	   /*!< TIM6 global Interrupt 								 */
 TIM7_IRQn					 = 55,	   /*!< TIM7 global Interrupt 								 */
 DMA2_Channel1_IRQn			 = 56, 	   /*!< DMA2 channel 1 global Interrupt 					 */
 DMA2_Channel2_IRQn			 = 57, 	   /*!< DMA2 channel 2 global Interrupt 					 */
 DMA2_Channel3_IRQn			 = 58, 	   /*!< DMA2 channel 3 global Interrupt 					 */
 DMA2_Channel4_IRQn			 = 59, 	   /*!< DMA2 channel 4 global Interrupt 					 */
 DMA2_Channel5_IRQn			 = 60, 	   /*!< DMA2 channel 5 global Interrupt 					 */
 ETH_IRQn					 = 61,	   /*!<	ETHERNET global Interrupt			   				 */
 ETH_WKUP_IRQn				 = 62,     /*!<	ETHERNET wakeup through EXTI line Interrupt		 	 */
 CAN2_TX_IRQn				 = 63,	   /*!<	CAN2 TX Interrupts		 		   				     */
 CAN2_RX0_IRQn				 = 64,	   /*!<	CAN2 RX0 Interrupts		 		   				     */
 CAN2_RX1_IRQn				 = 65,	   /*!<	CAN2 RX1 Interrupts		 		   				     */
 CAN2_SCE_IRQn				 = 66,	   /*!<	CAN2 SCE Interrupts		 		   				     */
 OTG_FS_IRQn				 = 67      /*!< USB on the Go */
} IRQn_Type;

/* Functions declaration */
void NVIC_enableIRQn(IRQn_Type IRQn);
void NVIC_disableIRQn(IRQn_Type IRQn);
uint32_t NVIC_getEnableIRQn(IRQn_Type IRQn);
void NVIC_setPendingIRQn(IRQn_Type IRQn);
void NVIC_clearPendingIRQn(IRQn_Type IRQn);
uint32_t NVIC_getPendingIRQn(IRQn_Type IRQn);
uint32_t NVIC_getActiveIRQn(IRQn_Type IRQn);
void NVIC_setPriority(IRQn_Type IRQn,uint32_t groupNumber, uint8_t groupPriority, uint8_t subGroupPriority );


#endif /* INC_NVIC_INTERFACE_H_ */
