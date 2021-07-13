/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL   ***********************/
/***********************   SWC (DRIVER):TIMER *********************/
/***********************   DATA : 14-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_interface.h"

void (*Timer_pvCallBackFunc[8])(void)={NULL};

void Timer0_Init (void)
{
#if TIMER0_MODE ==  TIMER0_NORMAL
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/*clear the output comp value */
	TCCR0 &= Timer02_CLEAR_OC0_OC2 ;
	/*Set the output comp value */
	TCCR0 |= TIMER0_NORMAL_CTC_OCO ;

	/*Set the PreLoad Value*/
	Timer_u8PreLoad (TIMER0_PRELOAD_INIT ,TIMER0);

	/*Set the interrupt state*/
	Timer_u8InterruptState  (DISABLE , TOIE0 , TIMER0);
	Timer_u8InterruptState  (DISABLE , OCIE0 , TIMER0);

#elif TIMER0_MODE ==  TIMER0_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	TCCR0 &= Timer02_CLEAR_OC0_OC2 ;
	/*Set the output comp value */
	TCCR0 |= TIMER0_PWM_OCO;

	/*Set the PreLoad Value*/
	Timer_u8PreLoad (TIMER0_PRELOAD_INIT ,TIMER0);
	/*Set the compare value*/
	Timer_u8SetCompValue (TIMER0_COMPARE_INIT ,TIMER0 ,NO_CHANNEL);

	/*Set the interrupt state*/
	Timer_u8InterruptState  (DISABLE , TOIE0 , TIMER0);
	Timer_u8InterruptState  (DISABLE , OCIE0 , TIMER0);

#elif TIMER0_MODE ==  TIMER0_CTC
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	TCCR0 &= Timer02_CLEAR_OC0_OC2 ;
	/*Set the output comp value */
	TCCR0 |= TIMER0_NORMAL_CTC_OCO ;

	/*Set the PreLoad Value*/
	Timer_u8PreLoad (TIMER0_PRELOAD_INIT ,TIMER0);
	/*Set the compare value*/
	Timer_u8SetCompValue (TIMER0_COMPARE_INIT ,TIMER0 ,NO_CHANNEL);

	/*Set the interrupt state*/
	Timer_u8InterruptState  (DISABLE , TOIE0 , TIMER0);
	Timer_u8InterruptState  (ENABLE , OCIE0 , TIMER0);

#elif TIMER0_MODE ==  TIMER0_FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	TCCR0 &= Timer02_CLEAR_OC0_OC2 ;
	/*Set the output comp value */
	TCCR0 |= TIMER0_FAST_PWM_OCO ;


	/*Set the PreLoad Value*/
	Timer_u8PreLoad (TIMER0_PRELOAD_INIT ,TIMER0);
	/*Set the compare value*/
	Timer_u8SetCompValue (TIMER0_COMPARE_INIT ,TIMER0 ,NO_CHANNEL);


	/*Set the interrupt state*/
	Timer_u8InterruptState  (DISABLE , TOIE0 , TIMER0);
	Timer_u8InterruptState  (DISABLE , OCIE0 , TIMER0);

#else
#error "WRONG IN TIMER0_MODE"
#endif


}


void Timer1_Init (void)
{
#if   TIMER1_MODE ==  TIMER1_NORMAL
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |=TIMER1_NORMAL_CTC_MODE_CHANNELA ;
	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |=TIMER1_NORMAL_CTC_MODE_CHANNELB ;


	/*enter the preload value*/
	Timer_u8PreLoad (TIMER1_PRELOAD_INIT , TIMER1);

	/*Enable the Ovf */
	SET_BIT(TIMSK,TIMSK_TOIE1);


	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);







#elif TIMER1_MODE ==  TIMER1_PWM_8BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |=TIMER1_PWM_MODE_CHANNELA ;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |= TIMER1_PWM_MODE_CHANNELB;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_PWM_9BIT
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |= TIMER1_PWM_MODE_CHANNELA;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |= TIMER1_PWM_MODE_CHANNELB;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_PWM_10BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |= TIMER1_PWM_MODE_CHANNELA;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |=TIMER1_PWM_MODE_CHANNELB ;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_CTC0
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |= TIMER1_NORMAL_CTC_MODE_CHANNELA;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |=TIMER1_NORMAL_CTC_MODE_CHANNELB ;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_FAST_PWM_8BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |= TIMER1_FAST_PWM_MODE_CHANNELA;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |= TIMER1_FAST_PWM_MODE_CHANNELB;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_FAST_PWM_9BIT
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |= TIMER1_FAST_PWM_MODE_CHANNELA;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |= TIMER1_FAST_PWM_MODE_CHANNELB;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_FAST_PWM_10BIT
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |= TIMER1_FAST_PWM_MODE_CHANNELA;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |= TIMER1_FAST_PWM_MODE_CHANNELB;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_PHASE_FREQ_CORRECT0
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |= TIMER1_PWM_MODE_CHANNELA;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |= TIMER1_PWM_MODE_CHANNELB;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_PHASE_FREQ_CORRECT1
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |=TIMER1_PWM_MODE_CHANNELA ;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |=TIMER1_PWM_MODE_CHANNELB ;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_PWM0
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |= TIMER1_PWM_MODE_CHANNELA;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |=TIMER1_PWM_MODE_CHANNELB ;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);





#elif TIMER1_MODE ==  TIMER1_PWM1
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |= TIMER1_PWM_MODE_CHANNELA;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |= TIMER1_PWM_MODE_CHANNELB;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_CTC1
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |= TIMER1_NORMAL_CTC_MODE_CHANNELA ;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |=TIMER1_NORMAL_CTC_MODE_CHANNELB ;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;

	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);

	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_FAST_PWM0
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |=TIMER1_FAST_PWM_MODE_CHANNELA ;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |=TIMER1_FAST_PWM_MODE_CHANNELB ;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;
	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);
	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);






#elif TIMER1_MODE ==  TIMER1_FAST_PWM1
	SET_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*CLear the output compare mode*/
	/*Select the output compare mode */
	TCCR1A &= TIMER1_CLEAR_CHANNELA ;
	TCCR1A |=TIMER1_FAST_PWM_MODE_CHANNELA ;

	TCCR1A &= TIMER1_CLEAR_CHANNELB ;
	TCCR1A |=TIMER1_FAST_PWM_MODE_CHANNELB ;

	/*Enter the type of trigger in input capture mode */
	Timer1_u8SetTrigger (RISING) ;
	/*enter the preload value*/
	Timer_u8PreLoad (0 , TIMER1);
	/*enter the comp mode value of channel a and b */
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELA);
	Timer_u8SetCompValue ( 0 , TIMER1 , CHANNELB);







#else
#error "WRONG IN TIMER1_MODE"
#endif

}

void  Timer2_Init (void)
{
#if   TIMER2_MODE == TIMER2_NORMAL

	CLR_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);

	/*clear the output comp value */
	TCCR2 &= Timer02_CLEAR_OC0_OC2 ;
	/*Set the output comp value */
	TCCR2 |= TIMER2_NORMAL_CTC_OC2 ;

	/*Set the PreLoad Value*/
	Timer_u8PreLoad (TIMER2_PRELOAD_INIT ,TIMER2);

	/*Set the interrupt state*/
	Timer_u8InterruptState  (DISABLE , TOIE2 , TIMER2);
	Timer_u8InterruptState  (DISABLE , OCIE2 , TIMER2);


#elif TIMER2_MODE == TIMER2_PWM
	SET_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);

	TCCR2 &= Timer02_CLEAR_OC0_OC2 ;
	/*Set the output comp value */
	TCCR2 |= TIMER2_PWM_OC2;

	/*Set the PreLoad Value*/
	Timer_u8PreLoad (TIMER2_PRELOAD_INIT ,TIMER0);
	/*Set the compare value*/
	Timer_u8SetCompValue (TIMER2_COMPARE_INIT ,TIMER2 ,NO_CHANNEL);

	/*Set the interrupt state*/
	Timer_u8InterruptState  (DISABLE , TOIE2 , TIMER2);
	Timer_u8InterruptState  (DISABLE , OCIE2 , TIMER2);

#elif TIMER2_MODE == TIMER2_CTC

	CLR_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

	TCCR2 &= Timer02_CLEAR_OC0_OC2 ;
	/*Set the output comp value */
	TCCR2 |= TIMER2_NORMAL_CTC_OC2 ;

	/*Set the PreLoad Value*/
	Timer_u8PreLoad (TIMER2_PRELOAD_INIT ,TIMER2);
	/*Set the compare value*/
	Timer_u8SetCompValue (TIMER2_COMPARE_INIT ,TIMER2,NO_CHANNEL);

	/*Set the interrupt state*/
	Timer_u8InterruptState  (DISABLE , TOIE2 , TIMER2);
	Timer_u8InterruptState  (DISABLE , OCIE2 , TIMER2);

#elif TIMER2_MODE == TIMER2_FAST_PWM
	SET_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);

	TCCR0 &= Timer02_CLEAR_OC0_OC2 ;
	/*Set the output comp value */
	TCCR0 |= TIMER2_FAST_PWM_OC2 ;

	/*Set the PreLoad Value*/
	Timer_u8PreLoad (TIMER2_PRELOAD_INIT ,TIMER2);
	/*Set the compare value*/
	Timer_u8SetCompValue (TIMER2_COMPARE_INIT ,TIMER2 ,NO_CHANNEL);

	/*Set the interrupt state*/
	Timer_u8InterruptState  (DISABLE , TOIE2 , TIMER2);
	Timer_u8InterruptState  (DISABLE , OCIE2 , TIMER2);

#else
#error "WRONG IN Timer2_mode"
#endif

}

u8 Timer_u8PreLoad (u16 Copy_u8Value , u8 Copy_u8TypeTimer)
{
	u8 Local_u8ErrorState =OK ;
	switch (Copy_u8TypeTimer)
	{
	case TIMER0 :TCNT0= Copy_u8Value; break;
	case TIMER1 :TCNT1= Copy_u8Value; break;
	case TIMER2 :TCNT2 =Copy_u8Value; break ;
	default : Local_u8ErrorState =NOK ;
	}
	return Local_u8ErrorState ;
}

u8 Timer_u8SetCompValue ( u16 Copy_u8Value , u8 Copy_u8TypeTimer , u8 Copy_u8Channel)
{
	u8 Local_u8ErrorState =OK ;
	switch (Copy_u8TypeTimer)
	{
	case TIMER0 :OCR0= Copy_u8Value; break;
	case TIMER1 :
		switch (Copy_u8Channel)
		{
		case CHANNELA :
			OCR1A =Copy_u8Value ; break ;
		case CHANNELB :
			OCR1B = Copy_u8Value; break;
		default :Local_u8ErrorState =NOK ; break;
		}
		break ;
		case TIMER2 :OCR2 =Copy_u8Value; break ;
		default : Local_u8ErrorState =NOK ; break;
	}
	return Local_u8ErrorState ;

}

u8 Timer_u8InterruptState  (u8 Copy_InterruptState , u8 Copy_InterruptPin , u8 Copy_u8TypeTimer)
{
	u8 Local_u8ErrorState =OK ;

	if (Copy_u8TypeTimer == TIMER0 )
	{
		if (Copy_InterruptPin  == OCIE0 )
		{
          if (Copy_InterruptState == ENABLE)
          {
          	 SET_BIT(TIMSK,TIMSK_OCIE0);
          }
          else if (Copy_InterruptState == DISABLE)
          {
          	  CLR_BIT(TIMSK,TIMSK_OCIE0);
          }
			else
		  {
				Local_u8ErrorState =NOK;
          }
		}
		else if (Copy_InterruptPin  == TOIE0)
		{
          if (Copy_InterruptState == ENABLE)
          {
          	   SET_BIT(TIMSK,TIMSK_TOIE0);
          }
          else if (Copy_InterruptState == DISABLE)
          {
          	   CLR_BIT(TIMSK,TIMSK_TOIE0);
          }
          else
          {
          	Local_u8ErrorState =NOK;
          }
		}
		else
		{
			Local_u8ErrorState =NOK ;
		}
	}
	else if (Copy_u8TypeTimer  == TIMER1)
	{
		if (Copy_InterruptPin == TICIE)
		{

			if (Copy_InterruptState == ENABLE)
			{
                SET_BIT(TIMSK,TIMSK_TICIE);
			}
			else if (Copy_InterruptState == DISABLE)
			{
                 CLR_BIT(TIMSK,TIMSK_TICIE);
			}
			else
			{
				Local_u8ErrorState =NOK;
			}

		}
		else if (Copy_InterruptPin == OCIE1A)
		{


			if (Copy_InterruptState == ENABLE)
			{
               SET_BIT(TIMSK,TIMSK_OCIE1A);
			}
			else if (Copy_InterruptState == DISABLE)
			{
                CLR_BIT(TIMSK,TIMSK_OCIE1A);
			}
			else
			{
				Local_u8ErrorState =NOK;
			}




		}
		else if (Copy_InterruptPin == OCIE1B)
		{

			if (Copy_InterruptState == ENABLE)
			{
                SET_BIT(TIMSK,TIMSK_OCIE1B);
			}
			else if (Copy_InterruptState == DISABLE)
			{
               CLR_BIT(TIMSK,TIMSK_OCIE1B);
			}
			else
			{
				Local_u8ErrorState =NOK;
			}




		}
		else if (Copy_InterruptPin == TOIE1)
		{


			 if (Copy_InterruptState == ENABLE)
			 {
                 SET_BIT(TIMSK,TIMSK_TOIE1);
			 }
			 else if (Copy_InterruptState == DISABLE)
			 {
                 SET_BIT(TIMSK,TIMSK_TOIE1);
			 }
			 else
			 {
			 	Local_u8ErrorState =NOK;
			 }

		}
		else
		{
			Local_u8ErrorState =NOK ;
		}


	}
	else if (Copy_u8TypeTimer == TIMER2 )
	{
		if (Copy_InterruptPin == OCIE2)
		{
			if (Copy_InterruptState == ENABLE)
			{
               SET_BIT(TIMSK,TIMSK_OCIE2);
			}
			else if (Copy_InterruptState == DISABLE)
			{
               CLR_BIT(TIMSK,TIMSK_OCIE2);
			}
			else
			{
				Local_u8ErrorState =NOK;
			}

		}
		else if (Copy_InterruptPin == TOIE2)
		{

			if (Copy_InterruptState == ENABLE)
			{
                 SET_BIT(TIMSK,TIMSK_TOIE2 );
			}
			else if (Copy_InterruptState == DISABLE)
			{
                CLR_BIT(TIMSK,TIMSK_TOIE2 );
			}
			else
			{
				Local_u8ErrorState =NOK;
			}



		}
		else
		{
			Local_u8ErrorState =NOK ;
		}
	}
	else
	{
		Local_u8ErrorState =NOK;
	}

	return Local_u8ErrorState ;
}

u8 Timer1_u8SetTrigger (u8 Copy_u8TypeTrigger)
{
	u8 Local_u8ErrorState =OK;

	switch (Copy_u8TypeTrigger)
	{
	case RISING :SET_BIT(TCCR1B,TCCR1B_ICES1);break;
	case FALLING :CLR_BIT(TCCR1B,TCCR1B_ICES1); break;
	default : Local_u8ErrorState =NOK; break;
	}

	return Local_u8ErrorState;

}

u16 Timer1_u16ReadValue (void)
{
	return TCNT1 ;
}
u16 Timer1_u16IcuReadValue (void)
{
	return ICR1 ;
}
u8 Timer0_u8ReadValue (void)
{
	return TCNT0 ;
}
u8 Timer2_ReadValue (void)
{
	return TCNT2;
}


void ICU_Gen_Init (void)
{
	/*Set the Trigger */
	Timer1_u8SetTrigger(RISING);

	/*Set the the interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE);

}

u8 Timer_u8CallBackFunc (void (*Copy_pvNotification)(void), u8 Copy_u8NumberInterrupt)
{
	u8 Local_u8ErrorState =OK ;

	if (Copy_pvNotification != NULL)
	{
		Timer_pvCallBackFunc[Copy_u8NumberInterrupt] = Copy_pvNotification ;
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}


	return Local_u8ErrorState ;
}

void WDT_voidEnable (void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}
void WDT_voidDissable (void)
{
	WDTCR = (1<<WDTCR_WDE)|(1<<WDTCR_WDTOE);

	WDTCR =0 ;

}
u8 WDT_u8Sleep (u8 Copy_u8SleepTime)
{
	u8 Local_u8ErrorState =OK;
	if (Copy_u8SleepTime <8)
	{
		WDTCR &=0b11111000 ;
		WDTCR |=Copy_u8SleepTime ;

	}
	else
	{
		Local_u8ErrorState =NOK ;
	}
	return Local_u8ErrorState ;
}
void Clear (void)
{
	while (TCNT0 !=255)
	{

	}
	TCNT0 =0 ;
}

void Timer1_SetOnTop (u16 Copy_u16TopValue)
{
	ICR1 = Copy_u16TopValue ;
}
u8 Timer_Enable (u8 Copy_u8TypeTimer)
{
	u8 Local_u8ErrorState = OK;
	if (Copy_u8TypeTimer == TIMER0)
	{
		/*Clear the prescaler */
		TCCR0 &= TIMER_CLEAR_PRE ;
		/*Set the Prescaler*/
		TCCR0 |= TIMER0_PRE ;
	}
	else if (Copy_u8TypeTimer == TIMER1)
	{
		/*clear and set Prescaler*/
		TCCR1B &= TIMER_CLEAR_PRE ;
		TCCR1B |= TIMER1_PRE ;

	}
	else if (Copy_u8TypeTimer == TIMER2)
	{

		/*Clear the prescaler */
		TCCR2 &= TIMER_CLEAR_PRE ;
		/*Set the Prescaler*/
		TCCR2 |= TIMER2_PRE ;

	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState ;

}

void __vector_4 (void)   		__attribute__((signal)); /*timer2 comp match value event */
void __vector_4 (void)
{
	if (Timer_pvCallBackFunc[OCIE2] != NULL)
	{
		Timer_pvCallBackFunc[OCIE2]();
	}
	else
	{
		/*nothing*/
	}
}
void __vector_5(void)   		__attribute__((signal)); /*timer2 ovf value event*/
void __vector_5(void)
{
	if (Timer_pvCallBackFunc[TOIE2] != NULL)
	{
		Timer_pvCallBackFunc[TOIE2]();
	}
	else
	{
		/*nothing*/
	}
}
void __vector_6 (void)   		__attribute__((signal)); /*timer1 Capture */
void __vector_6 (void)
{
	if (Timer_pvCallBackFunc[TICIE] != NULL)
	{
		Timer_pvCallBackFunc[TICIE]();
	}
	else
	{
		/*nothing*/
	}
}
void __vector_7 (void)   		__attribute__((signal)); /*timer1 compA*/
void __vector_7 (void)
{
	if (Timer_pvCallBackFunc[OCIE1A] != NULL)
	{
		Timer_pvCallBackFunc[OCIE1A]();
	}
	else
	{
		/*nothing*/
	}
}
void __vector_8 (void)   		__attribute__((signal)); /*timer1 compB*/
void __vector_8 (void)
{
	if (Timer_pvCallBackFunc[OCIE1B] != NULL)
	{
		Timer_pvCallBackFunc[OCIE1B]();
	}
	else
	{
		/*nothing*/
	}
}
void __vector_9 (void)   		__attribute__((signal)); /*timer 1 ovf */
void __vector_9 (void)
{
	if (Timer_pvCallBackFunc[TOIE1] != NULL)
	{
		Timer_pvCallBackFunc[TOIE1]();
	}
	else
	{
		/*nothing*/
	}
}
void __vector_10 (void)   		__attribute__((signal)); /*timer0 comp */
void __vector_10 (void)
{
	if (Timer_pvCallBackFunc[OCIE0] != NULL)
	{
		Timer_pvCallBackFunc[OCIE0]();
	}
	else
	{
		/*nothing*/
	}
}
void __vector_11 (void)   		__attribute__((signal)); /*timer 0 ovf */
void __vector_11 (void)
{
	if (Timer_pvCallBackFunc[TOIE0] != NULL)
	{
		Timer_pvCallBackFunc[TOIE0]();
	}
	else
	{
		/*nothing*/
	}
}


