/**********************************************************************/
/**********************************************************************/
/***********************   YEHIA SHAHIN         ***********************/
/***********************   Layer :RTOS          ***********************/
/***********************   SWC (DRIVER):RTOS_SW ***********************/
/***********************   DATA : 14-9-2020     ***********************/
/***********************   VERSION : 1.00       ***********************/
/**********************************************************************/
/**********************************************************************/

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct
{
	u16 Periodicity ;
	void (*TaskFunc)(void);
	u8 state ;
	u8 First_u8Delay ;

}Task_t;

#define TASK_RESUME 		0
#define TASK_SUSPEND		1



static void VoidScheduler (void);



#endif
