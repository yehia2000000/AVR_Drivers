/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL   ***********************/
/***********************   SWC (DRIVER):EXTI *********************/
/***********************   DATA : 14-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/



#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
/*choose the INT1 sense control :
 * options : 1-FALLING_EDGE
 * 			 2-RISING_EDGE
 * 			 3-ON_CHANGE
 * 			 4-LOW_LEVEL*/

#define EXTI_INT0_SENSE 	RISING_EDGE

/*choose the INT0 initial State :
 * options : 1-ENABLE
 * 			 2-DISABLE
*/

#define EXTI_INT0_INITIAL_STATE 	ENABLE

/*---------------------------------------------------------------------------------------*/

/*choose the INT1 sense control :
 * options : 1-FALLING_EDGE
 * 			 2-RISING_EDGE
 * 			 3-ON_CHANGE
 * 			 4-LOW_LEVEL*/

#define EXTI_INT1_SENSE 	FALLING_EDGE

/*choose the INT1 initial State :
 * options : 1-ENABLE
 * 			 2-DISABLE
*/

#define EXTI_INT1_INITIAL_STATE 	ENABLE

/*---------------------------------------------------------------------------------------*/
/*choose the INT1 sense control :
 * options : 1-FALLING_EDGE
 * 			 2-RISING_EDGE
 * 			 					*/

#define EXTI_INT2_SENSE 	FALLING_EDGE

/*choose the INT1 initial State :
 * options : 1-ENABLE
 * 			 2-DISABLE
*/

#define EXTI_INT2_INITIAL_STATE 	ENABLE


#endif
