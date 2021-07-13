/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):DIO *********************/
/***********************   DATA : 24-8-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "DAC_config.h"
#include "DAC_interface.h"
#include "DAC_private.h"

u8 DAC_u8SetAnalogVolt (u32 Copy_u8AnalogVolt)
{
	u32 Local_u8ErrorState = OK;
	u32 Local_u8OneStep ;
	u32 Local_u8Digital ;
if (Copy_u8AnalogVolt<= DAC_MAX_VOLT)
{
	Local_u8OneStep = (DAC_MAX_VOLT)/(DAC_PROBABILITY);

	Local_u8Digital = (Copy_u8AnalogVolt)/(Local_u8OneStep);

	DIO_u8SetPortValue(DAC_PORT,Local_u8Digital);
}
else

{
	Local_u8ErrorState =NOK;
}
return Local_u8ErrorState;

}
