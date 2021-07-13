/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL   ***********************/
/***********************   SWC (DRIVER):EXTI *********************/
/***********************   DATA : 14-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_private.h"
/*-----------------------GLOBAL -------------------------------------------------*/
void (*EXTI_voidINTPvCallBack[3])(void)={NULL};


/*------------------------------INITIAL THE EXTERNAL INTERRRUPT AT PREPROCESSOR ----------------------------------------------*/
void EXTI_voidINT0Init(void)
{
/*the conditions of the INT0 Sense  Control*/
#if EXTI_INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#else
#error "WRONG IN EXTI_INT0_SENSE "
#endif

/*The conditions of the INT0 Enable OR Disable */
#if EXTI_INT0_INITIAL_STATE == ENABLE
	SET_BIT(GICR,GICR_INT0);
#elif EXTI_INT0_INITIAL_STATE == DISABLE
	CLR_BIT(GICR,GICR_INT0);
#else
#error "WRONG IN EXTI_INT0_INITIAL_STATE"

#endif

}

void EXTI_voidINT1Init(void)
{
	/*the conditions of the INT0 Sense  Control*/
#if EXTI_INT1_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_INT1_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_INT1_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_INT1_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#else
#error"WRONG IN EXTI_INT1_SENSE "

#endif

/*Condition of  EXTI_INT1_INITIAL_STATE*/
#if EXTI_INT1_INITIAL_STATE == ENABLE
	SET_BIT(GICR,GICR_INT1);
#elif EXTI_INT1_INITIAL_STATE== DISABLE
	CLR_BIT(GICR,GICR_INT1);
#else
#error "WRONG IN EXTI_INT1_INITIAL_STATE "

#endif

}
void EXTI_voidINT2Init(void)
{
	/*Condition of EXTI_voidINT2_Sense_State */
#if EXTI_INT2_SENSE == FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
#elif EXTI_INT2_SENSE == RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#else
#error "WRONG IN  EXTI_INT2_SENSE"

#endif


/*Condition of  EXTI_INT2_INITIAL_STATE*/
#if EXTI_INT2_INITIAL_STATE == ENABLE
	SET_BIT(GICR,GICR_INT2);
#elif EXTI_INT2_INITIAL_STATE== DISABLE
	CLR_BIT(GICR,GICR_INT2);
#else
#error "WRONG IN EXTI_INT2_INITIAL_STATE "

#endif

}

/*------------------------------------CONFIGUATION AT RUN TIME -----------------------------------------------------*/
u8 EXTI_u8SetSenseControl (u8 Copy_u8IntNumber ,u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8IntNumber)
	{

	case EXTI_INT0 :
	switch (Copy_u8Sense)
	{
	case FALLING_EDGE : CLR_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01); break ;
	case RISING_EDGE  : SET_BIT(MCUCR,MCUCR_ISC00);SET_BIT(MCUCR,MCUCR_ISC01); break ;
	case ON_CHANGE    : SET_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01); break ;
	case LOW_LEVEL 	  : CLR_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01); break ;
	default : Local_u8ErrorState =NOK ; break ;
	}
	break ;

	case EXTI_INT1 :
	switch (Copy_u8Sense)
	{
	case FALLING_EDGE : CLR_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11); break ;
	case RISING_EDGE  : SET_BIT(MCUCR,MCUCR_ISC10);SET_BIT(MCUCR,MCUCR_ISC11); break ;
	case ON_CHANGE    : SET_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11); break ;
	case LOW_LEVEL 	  : CLR_BIT(MCUCR,MCUCR_ISC10);CLR_BIT(MCUCR,MCUCR_ISC11); break ;
	default : Local_u8ErrorState =NOK ; break ;
	}
	break ;


	case EXTI_INT2 :
	switch (Copy_u8Sense)
	{
	case FALLING_EDGE : CLR_BIT(MCUCSR,MCUCSR_ISC2);break;
	case RISING_EDGE  : SET_BIT(MCUCSR,MCUCSR_ISC2);break;
	default : Local_u8ErrorState =NOK ; break ;
	}
	break ;

	default :Local_u8ErrorState =NOK ; break;
	}
return Local_u8ErrorState;
}


u8 EXTI_u8EnableInterrrupt (u8 Copy_u8IntNUmber)
{
	u8 Local_u8ErrorState = OK ;
	switch (Copy_u8IntNUmber)
	{
	  case EXTI_INT0 : SET_BIT(GICR,GICR_INT0); break;
	  case EXTI_INT1 : SET_BIT(GICR,GICR_INT1); break;
	  case EXTI_INT2 : SET_BIT(GICR,GICR_INT2); break;
	  default : Local_u8ErrorState =NOK;

	}

	return Local_u8ErrorState ;
}

u8 EXTI_u8DisableInterrrupt (u8 Copy_u8IntNUmber)
{
	u8 Local_u8ErrorState = OK ;
	switch (Copy_u8IntNUmber)
	{
	  case EXTI_INT0 : CLR_BIT(GICR,GICR_INT0); break;
	  case EXTI_INT1 : CLR_BIT(GICR,GICR_INT1); break;
	  case EXTI_INT2 : CLR_BIT(GICR,GICR_INT2); break;
	  default : Local_u8ErrorState =NOK;

	}

	return Local_u8ErrorState ;

}

u8 EXTI_u8INTCallBackFunc (void (*Copy_voidPvCallBack)(void),u8 Copy_u8IntNUmber)
{
	u8 Local_u8ErrorState = OK ;
	if (Copy_voidPvCallBack !=NULL)
	{
		EXTI_voidINTPvCallBack[Copy_u8IntNUmber] = Copy_voidPvCallBack ;
	}
	else
	{
		Local_u8ErrorState =NOK;
	}
	return Local_u8ErrorState;
}




void __vector_1 (void)			__attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_voidINTPvCallBack[EXTI_INT0] != NULL)
	{
		EXTI_voidINTPvCallBack[EXTI_INT0]();
	}
	else
	{
		/*Do nothing*/
	}

}
void __vector_2 (void)			__attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_voidINTPvCallBack[EXTI_INT0] != NULL)
		{
			EXTI_voidINTPvCallBack[EXTI_INT0]();
		}
		else
		{
			/*Do nothing*/
		}

}
void __vector_3 (void)			__attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_voidINTPvCallBack[EXTI_INT0] != NULL)
		{
			EXTI_voidINTPvCallBack[EXTI_INT0]();
		}
		else
		{
			/*Do nothing*/
		}

}

