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
#include "SSD_interface.h"
#include "SWITCH_interface.h"

u8 SWITCH_voidStatusPin (SWITCH_t * Struct_pu8Switch)
{
	u8 Local_u8StatusPin=0;
	if (Struct_pu8Switch->Struct_u8Connection ==PULL_UP)
	{
		DIO_u8GetPinValue(Struct_pu8Switch->Struct_u8Port,Struct_pu8Switch->Struct_u8Pin,&Local_u8StatusPin);
		if (Local_u8StatusPin ==0)
		{
			 Local_u8StatusPin =1;
			return Local_u8StatusPin;
		}
		else if (Local_u8StatusPin ==1)
		{
			Local_u8StatusPin =0;
			return Local_u8StatusPin;
		}
	}
	else if ( Struct_pu8Switch->Struct_u8Connection ==PULL_DOWN)
	{
		DIO_u8GetPinValue(Struct_pu8Switch->Struct_u8Port,Struct_pu8Switch->Struct_u8Pin,&Local_u8StatusPin);
		return Local_u8StatusPin;

	}
	return Local_u8StatusPin;

}
