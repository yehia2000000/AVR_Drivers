/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :HAL   ***********************/
/***********************   SWC (DRIVER):SSD *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/


#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SSD_interface.h"



u8 SSD_voidSetNumber(SSD_t*Copy_u8Struct)
{
	u8 Local_u8ErrorState = OK ;
	u8 Local_u8Value =0;
	u8 * Local_u8ValuePin = &Local_u8Value ;
	if (Copy_u8Struct->Struct_u8Types == ANODE)
	{
		DIO_u8GetPinValue(Copy_u8Struct->Struct_u8EnablePort,Copy_u8Struct->Sruct_u8EnablePin,Local_u8ValuePin);
		switch (*Local_u8ValuePin)
		{
		case HIGH :
			switch (Copy_u8Struct->Struct_u8LedsPort)
			{
			case DIO_u8PORTA : DIO_u8SetPortValue(DIO_u8PORTA,*(Copy_u8Struct->Struct_u8NumberArr+(Copy_u8Struct->Struct_u8Number))); break ;
			case DIO_u8PORTB : DIO_u8SetPortValue(DIO_u8PORTB,*(Copy_u8Struct->Struct_u8NumberArr+(Copy_u8Struct->Struct_u8Number))); break ;
			case DIO_u8PORTC : DIO_u8SetPortValue(DIO_u8PORTC,*(Copy_u8Struct->Struct_u8NumberArr+(Copy_u8Struct->Struct_u8Number))); break ;
            case DIO_u8PORTD : DIO_u8SetPortValue(DIO_u8PORTD,*(Copy_u8Struct->Struct_u8NumberArr+(Copy_u8Struct->Struct_u8Number))); break ;
            default: Local_u8ErrorState = NOK ;break;
			}

     	}
	}
	else  if (Copy_u8Struct->Struct_u8Types == CATHODE)
	{	DIO_u8GetPinValue(Copy_u8Struct->Struct_u8EnablePort,Copy_u8Struct->Sruct_u8EnablePin,Local_u8ValuePin);
	    switch (*Local_u8ValuePin)
	    {
	    	case LOW :
	    		switch (Copy_u8Struct->Struct_u8LedsPort)
				{
				case DIO_u8PORTA : DIO_u8SetPortValue(DIO_u8PORTA,*(Copy_u8Struct->Struct_u8NumberArr+(Copy_u8Struct->Struct_u8Number))); break ;
				case DIO_u8PORTB : DIO_u8SetPortValue(DIO_u8PORTB,*(Copy_u8Struct->Struct_u8NumberArr+(Copy_u8Struct->Struct_u8Number))); break ;
				case DIO_u8PORTC : DIO_u8SetPortValue(DIO_u8PORTC,*(Copy_u8Struct->Struct_u8NumberArr+(Copy_u8Struct->Struct_u8Number))); break ;
				case DIO_u8PORTD : DIO_u8SetPortValue(DIO_u8PORTD,*(Copy_u8Struct->Struct_u8NumberArr+(Copy_u8Struct->Struct_u8Number))); break ;
				default: Local_u8ErrorState = NOK ;break;
				}


 	}

	}

return Local_u8ErrorState;

}

