/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL   ***********************/
/***********************   SWC (DRIVER):EXTI *********************/
/***********************   DATA : 14-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/



#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define MCUCR		*((volatile u8 *)0x55)               /*Microcontroller control register*/


#define MCUCR_ISC00		0								/*INT0 Sense Control Bit 0*/
#define MCUCR_ISC01		1								/*INT0 Sense Control Bit 1*/
#define MCUCR_ISC10		2								/*INT1 Sense Control Bit 0*/
#define MCUCR_ISC11		3								/*INT1 Sense Control Bit 1*/


#define MCUCSR		*((volatile u8 *)0x54)				/*Microcontroller control and status register*/
#define MCUCSR_ISC2		6								/*INT2 Sense Control */


#define GICR		*((volatile u8 *)0x5B)				/*General interrupt control register*/
#define GICR_INT0	6									/*INT0 PIE*/
#define GICR_INT1	7                                   /*INT1 PIE*/
#define GICR_INT2	5                                   /*INT2 PIE*/



#endif
