/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):ADC *********************/
/***********************   DATA : 20-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"




/*use the  static because use the pointer in this file only */
u16*ADC_Result = NULL;
static void (*ADC_PvNotification)(void) =NULL ;

/*Global flag is indicated the ADC Work or Not */
u8 ADC_u8State = IDLE ;

/*its indicate the Number of active thhe adc peripherial*/
u8 Local_u8CounterLoop ;
/*global pointer to indicate the result of the adc*/
u16* ADC_Res;
/*global flag to chosse the type of the converion in the  isr */
u8 ADC_u8ConversionSource ;

static u8 *ADC_pu8channel ;
static u8 ADC_u8ChainSize ;
static void(*ADC_pvChainNotification)(void);
static u16 *ADC_pu8Result ;

/*global Counter Check index*/
u8 ADC_u8Index ;


void ADC_voidInit (void)
{

	/*The Selectable Referance Voltage :
	 * Options :1-AREF_EXT : Access AREF by External Voltage
	 * 			2-AREF_AVCC: Access AREF by AVCC
	 * 			3-AREF_DEFAULT: Access AREF by Internal Voltage
	 * */
#if REF_SELECT==AREF_EXT
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif REF_SELECT==AREF_AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif REF_SELECT==AREF_DEFAULT
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#error "REF Selectable is WRONG"
#endif

	/*The Configuration of Upper and Lower Register
	 * Options :	1-Left_adjust :"when use 8 -bit Only"
	 * 				2-Right_adjust "When use 10-bit "*/
#if VALUE_REG_CONFIG == STORE_8BIT
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif VALUE_REG_CONFIG ==STORE_10BIT
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "WRONG IN CONFIGURATION VALUE REGISTER"
#endif

	/*Configuration The Prescaler Division
	 * Options : 1-DIVISON_BY_2
	 * 			 2-DIVISON_BY_2
	 * 			 3-DIVISON_BY_4
	 * 			 4-DIVISON_BY_8
	 * 			 5-DIVISON_BY_16
	 * 			 6-DIVISON_BY_32
	 * 			 7-DIVISON_BY_64
	 * 			 8-DIVISON_BY_128
	 * */
	ADCSRA &= 0b11111000;
	ADCSRA|=ADC_PRESCALER;

	/*Configuration Of The State Of ADC
	 * Options : 1-ENABLE
	 * 			 2-DISABLE
	 * 			 */

#if ADC_STATE==ENABLE
	SET_BIT(ADCSRA,ADCSRA_ADEN);
#elif ADC_STATE==DISABLE
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
#else
#error "WRONG IN THE ADC STAE"
#endif

}

/*Sych Start Conversion is used in the critical instructions*/


u8 ADC_u8StartSingleConversionSyn (u8 Copy_u8Channnel , u16 * Copy_u16Result)
{
	/*the indication the operation is execute or not
	 * Options :1 - OK  : the Function is successed
	 * 			2- NOK : the Function is not successed
	 * 			3- NULL_Pointer :the Pointer not indicate any location in memory
	 * 																				*/
	u8 Local_u8ErrorState = OK;

	u32 Local_u32CounterLimit =0 ;

	if (Copy_u16Result !=NULL)
	{
		if (ADC_u8State ==IDLE)
		{
			ADC_u8ConversionSource =SINGLE_STATE;
			ADC_u8State =BUSY;
			/*Clear the channel Code*/
			ADMUX &= MUX_CLEAR ;
			/*Set the Cannel Code */
			ADMUX |= Copy_u8Channnel ;
			/*Start Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			while ((GET_BIT(ADCSRA,ADCSRA_ADIF)==0)&&(Local_u32CounterLimit <ADC_LIMIT_WAITING))
			{
				Local_u32CounterLimit++;
			}
			if (Local_u32CounterLimit ==ADC_LIMIT_WAITING)
			{
				Local_u8ErrorState = TIMEOUT_STATE ;
			}
			else
			{

				SET_BIT(ADCSRA,ADCSRA_ADIF);

#if VALUE_REG_CONFIG == STORE_8BIT
				*Copy_u16Result =ADCH ;
#elif VALUE_REG_CONFIG == STORE_10BIT
				*Copy_u16Result =ADC ;
#else
#error "WRONG IN VALUE_REG_CONFIG"
#endif


			}
			ADC_u8State = IDLE ;
		}

		else
		{
			Local_u8ErrorState = BUSY_STATE ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState ;


}

u8 ADC_u8StartSingleConversionAsyn (u8 Copy_u8Channel ,u16 *Copy_u16Result , void (*Copy_PvNotification)(void))
{
	u8 Local_u8ErrorState =OK;
	if ((Copy_u16Result !=NULL)&&(Copy_PvNotification!=NULL))
	{
		if (ADC_u8State ==IDLE)
		{
			ADC_u8ConversionSource = SINGLE_STATE ;
			ADC_u8State =BUSY ;
			/*convert the result to the global variable*/
			ADC_Result=Copy_u16Result  ;
			/*convert the pointer of the function to global */
			ADC_PvNotification =Copy_PvNotification;

			/*Clear the Channel Code */
			ADMUX &= MUX_CLEAR;
			/*Set the channel Code*/
			ADMUX |= Copy_u8Channel ;
			/*Star tConversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*enable the adc interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			Local_u8ErrorState =BUSY_STATE ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8ChainConversion1 (void(* Copy_PvNotification)(void),u16 Copy_Results[8])
{

	u8 Local_u8ErrorState =OK;

	u8 Local_u8Check ;
	if (( Copy_PvNotification!=NULL)&&(Copy_Results!=NULL))
	{
		ADC_u8ConversionSource = CHAIN_STATE1 ;
		ADC_PvNotification =Copy_PvNotification;
		ADC_Res = Copy_Results ;
		for (Local_u8CounterLoop =0 ;Local_u8CounterLoop<8;Local_u8CounterLoop++)
		{
			Local_u8Check = 1&(Active_ADC_PORT>>Local_u8CounterLoop);
			if (Local_u8Check == 1)
			{
				/*Clear the Channel Code */
				ADMUX &= MUX_CLEAR;
				/*Set the channel Code*/
				ADMUX |= Local_u8CounterLoop;
				/*Star tConversion */
				SET_BIT(ADCSRA,ADCSRA_ADSC);
				/*enable the adc interrupt*/
				SET_BIT(ADCSRA,ADCSRA_ADIE);

				break ;
			}

		}

		/*enable the adc interrupt*/
		SET_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else
	{
		Local_u8ErrorState =NOK;

	}
	return Local_u8ErrorState ;

}

u8 ADC_u8ChainConversion2 (chain_t * Copy_Chain)
{
	u8 Local_u8ErrorState =OK;
	if ((Copy_Chain != NULL)&& (Copy_Chain->Notification != NULL)&&(Copy_Chain->Result != NULL)&& (Copy_Chain->channel != NULL))
	{
		if (ADC_u8State == IDLE)
		{
			/*Enable the busy state when the conversion is started*/
			ADC_u8State = BUSY;

			/*Enable The Chain_State2 to enable the ISR of the Chain2*/
			ADC_u8ConversionSource =CHAIN_STATE2;

			/*Convert the local Argument to the Global*/
			ADC_pu8channel =Copy_Chain->channel;
			ADC_u8ChainSize= Copy_Chain->chain_size ;
			ADC_pvChainNotification=Copy_Chain->Notification;
			ADC_pu8Result =Copy_Chain->Result ;

			/*Initialize the Conversion */

			/*initial the index is 0 , its the first channel*/
			ADC_u8Index =0 ;

			/*Clear the bits of the channel */
			ADMUX&=MUX_CLEAR ;

			/*Set the cde of the first channel*/
			ADMUX|=ADC_pu8channel[ADC_u8Index] ;

			/*Start the conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*enable the adc interrupt */
			SET_BIT(ADCSRA, ADCSRA_ADIE);


		}
		else
		{
			Local_u8ErrorState = BUSY_STATE ;
		}

	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;

	}
	return Local_u8ErrorState;
}


void __vector_16 (void)			__attribute__((signal));
void __vector_16 (void)
{
	if (ADC_u8ConversionSource == SINGLE_STATE)
	{
#if VALUE_REG_CONFIG == STORE_8BIT
		*ADC_Result =ADCH ;
#elif VALUE_REG_CONFIG == STORE_10BIT
		*ADC_Result =ADC ;
#else
#error "WRONG IN VALUE_REG_CONFIG"
#endif

		ADC_u8State =IDLE;
		ADC_PvNotification();

		CLR_BIT(ADCSRA,ADCSRA_ADIE);



	}
	else if (ADC_u8ConversionSource == CHAIN_STATE1)
	{
		u8 Local_u8Check ;
#if VALUE_REG_CONFIG == STORE_8BIT
		ADC_Res[Local_u8CounterLoop] =ADCH ;
#elif VALUE_REG_CONFIG == STORE_10BIT
		ADC_u16Results[Local_u8CounterLoop] =ADCH ;
#else
#error "WRONG IN VALUE_REG_CONFIG"
#endif


		for (Local_u8CounterLoop =Local_u8CounterLoop+1 ;Local_u8CounterLoop<8;Local_u8CounterLoop++)
		{
			Local_u8Check = 1&(Active_ADC_PORT>>Local_u8CounterLoop);
			if (Local_u8Check == 1)
			{

				ADMUX &= MUX_CLEAR;

				ADMUX |= Local_u8CounterLoop;

				SET_BIT(ADCSRA,ADCSRA_ADSC);


				break ;
			}

		}

		ADC_PvNotification();

		if (Local_u8CounterLoop == 8)
		{
			Local_u8CounterLoop =0 ;
			CLR_BIT(ADCSRA,ADCSRA_ADIE);

		}
	}
	else
	{
#if VALUE_REG_CONFIG == STORE_8BIT
		ADC_pu8Result[ADC_u8Index] = ADCH ;
#elif VALUE_REG_CONFIG == STORE_10BIT
		ADC_pu8Result[ADC_u8Index] = ADC ;
#else
#error "WRONG IN VALUE_REG_CONFIG"
#endif
		ADC_u8Index++;

		if (ADC_u8Index == ADC_u8ChainSize)
		{
			ADC_u8State = IDLE;

			CLR_BIT(ADCSRA,ADCSRA_ADIE);

			ADC_pvChainNotification();

		}
		else
		{

			/*Clear the bits of the channel */
			ADMUX&=MUX_CLEAR ;

			/*Set the cde of the first channel*/
			ADMUX|=ADC_pu8channel[ADC_u8Index] ;

			/*Start the conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);


		}



	}


}


