/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):SPI *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "SPI_register.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"



#include "DIO_interface.h"

static u8 * SPI_u8SendData  = NULL;
static u8 * SPI_u8RecieveData = NULL;
static u8   SPI_u8BufferSize ;
static void(*SPI_voidNotification)(void) = NULL;

u8 SPI_voidInterruptState (u8 Copy_u8StateType)
{

	u8 Local_u8ErrorState =OK ;
	if (Copy_u8StateType ==SPIE_ENABLE)
	{

		SET_BIT(SPCR,SPCR_SPIE);

	}
	else if (Copy_u8StateType == SPIE_DISABLE)
	{
		CLR_BIT(SPCR,SPCR_SPIE);
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}
	return Local_u8ErrorState ;
}

u8 SPI_voidState (u8 Copy_u8StateType)
{
	u8 Local_u8ErrorState =OK ;
	if (Copy_u8StateType ==SPI_ENABLE)
	{

		SET_BIT(SPCR,SPCR_SPE);

	}
	else if (Copy_u8StateType == SPI_DISABLE)
	{
		CLR_BIT(SPCR,SPCR_SPE);
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}
	return Local_u8ErrorState ;

}

u8 SPI_voidInit (u8 Copy_u8TypeMC)
{
	u8 Local_u8ErrorState =OK ;
	if (Copy_u8TypeMC ==SPI_MASTER)
	{

		SET_BIT(SPCR,SPCR_MSTR);


#if SPI_DORD == DORD_LSB
		SET_BIT(SPCR,SPCR_DORD);
#elif SPI_DORD == DORD_MSB
		CLR_BIT(SPCR,SPCR_DORD);
#else
#error"Wrong in Data order"
#endif

#if SPI_CPOL == CPOL_HIGH
		SET_BIT(SPCR,SPCR_DORD);
#elif SPI_CPOL == CPOL_LOW
		CLR_BIT(SPCR,SPCR_DORD);
#else
#error"Wrong in "
#endif

#if SPI_CPHA == CPHA_SETUP
		SET_BIT(SPCR,SPCR_DORD);
#elif SPI_CPHA == CPHA_SAMPLE
		CLR_BIT(SPCR,SPCR_DORD);

#else
#error"Wrong in clock phase"
#endif

#if SPI_PRE < 5
		CLR_BIT(SPSR,SPSR_SPI2X);
		SPCR&=CLEAR_SPEED;
		SPCR|=(SPI_PRE-1);
#elif SPI_PRE >= 5
		SET_BIT(SPSR,SPSR_SPI2X);
		SPCR&=CLEAR_SPEED;
		SPCR|=(SPI_PRE-5);

#else
#error "Wrong in SPI_PRE "
#endif

		SPI_voidState (SPI_ENABLE);
	}


	else if (Copy_u8TypeMC ==SPI_SLAVE)
	{

		CLR_BIT(SPCR,SPCR_MSTR);

#if SPI_DORD == DORD_LSB
		SET_BIT(SPCR,SPCR_DORD);
#elif SPI_DORD == DORD_MSB
		CLR_BIT(SPCR,SPCR_DORD);
#else
#error"Wrong in Data order"
#endif

#if SPI_CPOL == CPOL_HIGH
		SET_BIT(SPCR,SPCR_DORD);
#elif SPI_CPOL == CPOL_LOW
		CLR_BIT(SPCR,SPCR_DORD);
#else
#error"Wrong in "
#endif

#if SPI_CPHA == CPHA_SETUP
		SET_BIT(SPCR,SPCR_DORD);
#elif SPI_CPHA == CPHA_SAMPLE
		CLR_BIT(SPCR,SPCR_DORD);
#else
#error"Wrong in clock phase"
#endif

		SPI_voidState (SPI_ENABLE);

	}
	else
	{
		Local_u8ErrorState =NOK;
	}
	return Local_u8ErrorState ;
}
u8 SPI_u8Transcieve (u8 Copy_u8SendData , u8 * Copy_u8RecieveData )
{
	u8 Local_u8ErrorState =OK ;
	if (Copy_u8RecieveData != NULL)
	{
		SPDR = Copy_u8SendData;

		while (GET_BIT(SPSR,SPSR_SPIF)==0);
		*Copy_u8RecieveData= SPDR ;

	}
	else
	{
		Local_u8ErrorState =NOK ;
	}

	return Local_u8ErrorState;
}


u8 SPI_u8TranscieveBufferSyn (u8 * Copy_u8SendData, u8 * Copy_u8Recieve , u8 Copy_u8BufferSize)
{
	u8 Local_u8Counter1 ;
	u8 Local_u8ErrorState =OK ;
	if ((Copy_u8SendData != NULL)&&(Copy_u8Recieve != NULL))
	{
		for (Local_u8Counter1 =0 ;Local_u8Counter1 < Copy_u8BufferSize ;Local_u8Counter1++)
		{
			SPDR = Copy_u8SendData[Local_u8Counter1];

			while (GET_BIT(SPSR,SPSR_SPIF)==0);
			Copy_u8Recieve[Local_u8Counter1]= SPDR ;
			_delay_ms(100);

		}
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}
	return Local_u8ErrorState ;



}

u8 SPI_u8TranscieveBufferAsyn (SPI_t * Copy_SPI_tInfo)
{
	u8 Local_u8ErrorState =OK ;
	if (Copy_SPI_tInfo !=NULL)
	{

		SPI_u8SendData = Copy_SPI_tInfo ->SendData;
		SPI_u8RecieveData = Copy_SPI_tInfo ->RecieveData;
		SPI_u8BufferSize = Copy_SPI_tInfo ->BufferSize ;
		SPI_voidNotification =Copy_SPI_tInfo->Notification ;

		SPI_voidInterruptState(SPIE_ENABLE);
		SPDR = SPI_u8SendData[0];
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		_delay_ms (1);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);


	}
	else
	{
		Local_u8ErrorState =NOK;
	}
	return Local_u8ErrorState ;

}

void __vector_12 (void)			__attribute__((signal));
void __vector_12 (void)
{

	static u8 Local_u8CounterLoop = 0 ;

	if ((SPI_u8RecieveData != NULL)&&(SPI_u8SendData != NULL)&&(SPI_voidNotification != NULL))
	{

		Local_u8CounterLoop++;
		SPI_u8RecieveData[Local_u8CounterLoop-1]= SPDR ;

		if (Local_u8CounterLoop == SPI_u8BufferSize)
		{
			SPI_voidInterruptState(SPIE_DISABLE);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
					_delay_ms (1);
					DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
			SPI_voidNotification();
		}
		else
		{
			SPDR = SPI_u8SendData[Local_u8CounterLoop];

		}

	}
	else
	{

		/*Nothing*/
	}

}

