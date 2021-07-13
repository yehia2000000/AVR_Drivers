/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):USART *******************/
/***********************   DATA : 1-9-2020 **********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "USART_register.h"
#include "USART_.private.h"
#include "USART_config.h"
#include "USART_interface.h"

#include "DIO_interface.h"


static u8 State = ACTIVE;
static u8 Local_u8Counter =0 ;
static u8 USART_u8CounterREC ;
static u8 USART_u8CounterLoop =1 ;
static char * USART_charSendString = NULL ;
static u8*  USART_u8DATA  ;
void (*USART_CallBackFunc[2])(void)={NULL};

void USART_voidUDRInit (u8 Copy_u8InitValue)
{
	UDR = Copy_u8InitValue;
}

u8 USART_voidReadUDR (void)
{
	return UDR ;
}

u8 USART_voidEnable (u8 Copy_u8StateTX_RX)
{
	u8 Local_u8ErrorState = OK;
	if (Copy_u8StateTX_RX == RX_DISABLE_TX_DISABLE)
	{
		CLR_BIT(UCSRB,UCSRB_RXEN);
		CLR_BIT(UCSRB,UCSRB_TXEN);

	}
	else if (Copy_u8StateTX_RX== RX_ENABLE_TX_DISABLE)
	{
		SET_BIT(UCSRB,UCSRB_RXEN);
		CLR_BIT(UCSRB,UCSRB_TXEN);
	}
	else if (Copy_u8StateTX_RX== RX_DISABLE_TX_ENABLE )
	{
		CLR_BIT(UCSRB,UCSRB_RXEN);
		SET_BIT(UCSRB,UCSRB_TXEN);
	}
	else if (Copy_u8StateTX_RX==RX_ENABLE_TX_ENABLE  )
	{
		SET_BIT(UCSRB,UCSRB_RXEN);
		SET_BIT(UCSRB,UCSRB_TXEN);
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}

	return Local_u8ErrorState ;

}

u8 USART_u8ParityMode (u8 Copy_u8ParityMode)
{
	u8 Local_u8ErrorState =OK ;

	if (Copy_u8ParityMode ==PARITY_DIS  )
	{
		CLR_BIT(UCSRC,UCSRC_UPM0);
		CLR_BIT(UCSRC,UCSRC_UPM1);

	}
	else if (Copy_u8ParityMode  ==PARITY_DIS )
	{
		SET_BIT(UCSRC,UCSRC_UPM0);
		CLR_BIT(UCSRC,UCSRC_UPM1);

	}
	else if (Copy_u8ParityMode ==PARITY_EVEN)
	{
		CLR_BIT(UCSRC,UCSRC_UPM0);
		SET_BIT(UCSRC,UCSRC_UPM1);
	}
	else if (Copy_u8ParityMode  ==PARITY_ODD)
	{
		SET_BIT(UCSRC,UCSRC_UPM0);
		SET_BIT(UCSRC,UCSRC_UPM1);
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}


	return Local_u8ErrorState ;


}

u16 USART_u16UBRR (u16 Copy_u16BaudRate)
{

	u16 Local_u16UBRR ;

	Local_u16UBRR =  (u16)((10000000)/(16UL * (u32)Copy_u16BaudRate)) -1UL ;

	return Local_u16UBRR ;

}


void USART_voidInit (void)
{
	u8 Local_Helper =0  ;

	SET_BIT(Local_Helper,UCSRC_URSEL);

#if USART_SIZE_DATA < 5
	Local_Helper |= ((USART_SIZE_DATA-1) << UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	Local_Helper |= (USART_MODE<<UCSRC_UMSEL);
	Local_Helper |= (USART_PARITY_MODE<<UCSRC_UPM0);
	Local_Helper |= (USART_STOP_BIT_MODE<<UCSRC_USBS);



#elif USART_SIZE_DATA >= 5
	Local_Helper |= ((USART_SIZE_DATA-5) << UCSRC_UCSZ0);
	SET_BIT(UCSRB,UCSRB_UCSZ2);

	Local_Helper |= (USART_MODE<<UCSRC_UMSEL);
	Local_Helper |= (USART_PARITY_MODE<<UCSRC_UPM0);
	Local_Helper |= (USART_STOP_BIT_MODE<<UCSRC_USBS);


#else
#error "USART_SIZE_DATA is Wrong"
#endif

	UCSRC = Local_Helper ;

	UBRRL = (u8)USART_u16UBRR(USART_BAUD_RATE) ;
	UBRRH = (u8)((USART_u16UBRR(USART_BAUD_RATE))>>8);

	USART_voidEnable (RX_ENABLE_TX_ENABLE);

}

u8 USART_u8SendData (u8 Copy_u8Data)
{
	u32 Local_u32Counter =0 ;
	u8 Local_u8ErrorState = OK ;
	while ((GET_BIT(UCSRA,UCSRA_UDRE) == 0) && (Local_u32Counter < TIME_OUT_TRANS))
	{

	}
	if (Local_u32Counter < TIME_OUT_TRANS)
	{
		UDR = Copy_u8Data ;
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}
	return Local_u8ErrorState ;

}

u8 USART_u8RecieveData (u8 * Copy_u8Data)
{
	u32 Local_u32Counter =0 ;
	u8 Local_u8ErrorState = OK ;
	if (Copy_u8Data != NULL)
	{
		while ((GET_BIT(UCSRA,UCSRA_RXC) == 0) &&( Local_u32Counter < TIME_OUT_REC))
		{
			Local_u32Counter++ ;
		}
		if (Local_u32Counter < TIME_OUT_REC)
		{
			while(1)
			{
			*Copy_u8Data = UDR ;
			if (*Copy_u8Data < '0')
			{

			}
			else
			{
				break;
			}
			}

		}
		else
		{
			Local_u8ErrorState =NOK ;
		}
	}
	else
	{
		Local_u8ErrorState =NULL_POINTER ;
	}
	return Local_u8ErrorState ;

}

u8 USART_u8SendStringSyn (const char * Copy_pu8String)
{
	u8 Local_u8ErrorState =OK ;
	int i ;

	if (Copy_pu8String != NULL)
	{
		if (State == ACTIVE)
		{
			State =BUSY ;
			for (i=0 ; Copy_pu8String[i] !=0 ;i++)
			{
				USART_u8SendData(Copy_pu8String[i]);
			}


		}
		else
		{
			Local_u8ErrorState =NOK;
		}
		while (GET_BIT(UCSRA,UCSRA_UDRE)==0);
		State =ACTIVE ;

	}
	else
	{
		Local_u8ErrorState =NULL_POINTER ;
	}

	return Local_u8ErrorState ;
}

u8 USART_u8ReceiveBufferSyn (u8 * Copy_pu8Data ,  u8 Copy_u8BufferSize)
{
	u8 Local_u32Counter =0  ;
	u8 Local_u8ErrorState =OK ;
	u8 i ;
	if (Copy_pu8Data != NULL)
	{

		for (i=0 ; i<Copy_u8BufferSize ; i++ )
		{
			while ((GET_BIT(UCSRA,UCSRA_RXC) == 0) &&( Local_u32Counter < TIME_OUT_REC))
			{

			}
			if ((Local_u32Counter < TIME_OUT_REC))
			{

				Copy_pu8Data[i] = UDR ;

				if (Copy_pu8Data[i] < '0')
				{
					i--;
				}

			}
			else
			{
				Local_u8ErrorState =NOK ;
			}
		}

	}
	else
	{
		Local_u8ErrorState = NULL_POINTER  ;
	}


	return Local_u8ErrorState ;
}


u8 USART_u8SendStringAsyn ( char *Copy_charString , void (*Copy_voidNotification)(void))
{
	u8 Local_u8ErrorState =OK ;
	if (Copy_voidNotification !=NULL)
	{
		if (State == ACTIVE)
		{
			State =BUSY;
		USART_charSendString = Copy_charString ;
		USART_CallBackFunc[USART_UDE]= Copy_voidNotification ;
		USART_u8SendData(USART_charSendString[Local_u8Counter]);
		SET_BIT(UCSRB,UCSRB_UDRIE);
		}

	}
	else
	{
		Local_u8ErrorState =NOK ;
	}
	return Local_u8ErrorState ;

}
u8 USART_u8RecieveAsyn (u8 * Copy_u8Data , u8 Copy_u8BufferSize , void (*Copy_voidNotifaction)(void) )
{
	u8 Local_u8ErrorState = OK;
	if (Copy_voidNotifaction != NULL)
	{
		if (State == ACTIVE)
		{
			State =BUSY ;
		USART_u8DATA = Copy_u8Data ;
		USART_u8CounterREC = Copy_u8BufferSize ;
		USART_CallBackFunc[USART_RXC] = Copy_voidNotifaction ;
		SET_BIT(UCSRB,UCSRB_RXCIE);
		}
	}
	else
	{
		Local_u8ErrorState = NOK ;

	}

	return Local_u8ErrorState ;
}

void __vector_14 (void)			__attribute__((signal));
void __vector_14 (void)
{
	if (USART_CallBackFunc[USART_UDE] != NULL)
	{
		Local_u8Counter++;
		UDR= USART_charSendString[Local_u8Counter] ;
		if (USART_charSendString [Local_u8Counter] == 0)
		{
			State =ACTIVE ;
			Local_u8Counter =0 ;
			CLR_BIT(UCSRB,UCSRB_UDRIE);
			USART_CallBackFunc[USART_UDE]();
		}
	}
	else
	{
		/*Nothing*/
	}
}

void __vector_13 (void)			__attribute__((signal));
void __vector_13 (void)
{

	if (USART_CallBackFunc[USART_RXC] != NULL)
	{
		USART_u8DATA[USART_u8CounterLoop-1] = UDR ;

		if (USART_u8DATA[USART_u8CounterLoop-1] < '0')
		{

			USART_u8CounterLoop--;
		}
		USART_u8CounterLoop++;
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN7,DIO_u8PIN_HIGH);
		if (USART_u8CounterLoop==(USART_u8CounterREC+1))
		{
			USART_u8CounterLoop =1;
			State =ACTIVE ;
			CLR_BIT(UCSRB,UCSRB_RXCIE);
			USART_CallBackFunc[USART_RXC]();
		}

	}
	else
	{
		/*Nothing*/
	}

}
