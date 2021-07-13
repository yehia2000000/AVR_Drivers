/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL   ***********************/
/***********************   SWC (DRIVER):EXTI *********************/
/***********************   DATA : 14-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/



#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*Encoding the Interrupt Pins*/
#define EXTI_INT0 		0
#define EXTI_INT1 		1
#define EXTI_INT2 		2

/*Encoding The Sense Control */
#define FALLING_EDGE	1
#define RISING_EDGE 	2
#define ON_CHANGE   	3
#define LOW_LEVEL 		4

/*Initial Function of Interrupt */
void EXTI_voidINT0Init(void); /*Initialize the Interrupt 0 */
void EXTI_voidINT1Init(void); /*Initialize the Interrupt 1 */
void EXTI_voidINT2Init(void); /*Initialize the Interrupt 2 */

/*some peripheral change in run time
 * option : 1- Sense Interrupt (Falling - ON change - Rising - Low level
 * 			2- Peripheral Interrupt Enable */

u8 EXTI_u8SetSenseControl (u8 Copy_u8IntNumber ,u8 Copy_u8Sense);

u8 EXTI_u8EnableInterrrupt (u8 Copy_u8IntNUmber);

u8 EXTI_u8DisableInterrrupt (u8 Copy_u8IntNUmber);


u8 EXTI_u8INTCallBackFunc (void (*Copy_voidPvCallBack)(void),u8 Copy_u8IntNUmber);






#endif
