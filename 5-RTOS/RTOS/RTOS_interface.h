/**********************************************************************/
/**********************************************************************/
/***********************   YEHIA SHAHIN         ***********************/
/***********************   Layer :RTOS          ***********************/
/***********************   SWC (DRIVER):RTOS_SW ***********************/
/***********************   DATA : 14-9-2020     ***********************/
/***********************   VERSION : 1.00       ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_voidCreateTask (u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTask)(void));

void RTOS_voidStart (void);



#endif