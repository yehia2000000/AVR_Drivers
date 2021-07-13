/**********************************************************************/
/**********************************************************************/
/***********************   YEHIA SHAHIN         ***********************/
/***********************   Layer :RTOS          ***********************/
/***********************   SWC (DRIVER):RTOS_SW ***********************/
/***********************   DATA : 14-9-2020     ***********************/
/***********************   VERSION : 1.00       ***********************/
/**********************************************************************/
/**********************************************************************/

#include "STD_TYPES.h"

#include "TIMER_interface.h"

#include "RTOS_private.h"
#include "RTOS_config.h"
#include "RTOS_interface.h"

Task_t SystemTask [TASK_NUM]= {{NULL}};

u8 RTOS_voidCreateTask (u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTask)(void))
{
	u8 Local_u8ErrorState = OK ;
	if (SystemTask[Copy_u8Priority].TaskFunc == NULL)
	{
		SystemTask[Copy_u8Priority].Periodicity =Copy_u16Periodicity ;
		SystemTask[Copy_u8Priority].TaskFunc =Copy_pvTask;
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}

	return Local_u8ErrorState ;

}

void RTOS_voidStart (void)
{
	Timer_u8CallBackFunc(&VoidScheduler,OCIE0);
	Timer0_Init();
	Timer_Enable(TIMER0);

}
void RTOS_voidSuspend (u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].state = TASK_SUSPEND ;
}

void RTOS_voidResume (u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].state = TASK_RESUME ;

}

void RTOS_voidDelete (u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].TaskFunc= NULL;
}


static void VoidScheduler (void)
{
	static u16 Local_u16Counter =0 ;

	u8 Local_u8CounterLoop ;

	Local_u16Counter++;

	for (Local_u8CounterLoop =0 ;Local_u8CounterLoop <TASK_NUM ; Local_u8CounterLoop++)
	{
		if (((Local_u16Counter % SystemTask[Local_u8CounterLoop].Periodicity) == 0)&&(SystemTask[Local_u8CounterLoop].state == TASK_RESUME ))
		{
			if (SystemTask[Local_u8CounterLoop].TaskFunc != NULL)
			{
				SystemTask[Local_u8CounterLoop].TaskFunc();
			}
		}
	}

}
