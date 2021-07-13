/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):PORT *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_config.h"
#include "LED_interface.h"

void LED_voidControl (LED_t * Struct_pu8Led,u8 Copy_u8Control)
{
	if (Struct_pu8Led->Struct_u8ConnectionType==SINK)
	{
		switch (Copy_u8Control)
		{
		case LED_ON:
			DIO_u8SetPinValue(Struct_pu8Led->Struct_u8Port,Struct_pu8Led->Struct_u8Pin,DIO_u8PIN_LOW); break;
		case LED_OFF:
			DIO_u8SetPinValue(Struct_pu8Led->Struct_u8Port,Struct_pu8Led->Struct_u8Pin,DIO_u8PIN_HIGH); break;

		}

	}
	else if (Struct_pu8Led->Struct_u8ConnectionType==SOURCE)
	{
		switch (Copy_u8Control)
		{
		case LED_ON:
			DIO_u8SetPinValue(Struct_pu8Led->Struct_u8Port,Struct_pu8Led->Struct_u8Pin,DIO_u8PIN_HIGH);break;
		case LED_OFF:
			DIO_u8SetPinValue(Struct_pu8Led->Struct_u8Port,Struct_pu8Led->Struct_u8Pin,DIO_u8PIN_LOW); break;

		}

	}
}
void LED_voidToggle (LED_t * Struct_pu8Led)
{
	DIO_u8TogglePinValue(Struct_pu8Led->Struct_u8Port,Struct_pu8Led->Struct_u8Pin);
}

