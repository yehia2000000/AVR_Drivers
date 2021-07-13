/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :hal   ***********************/
/***********************   SWC (DRIVER):interface *********************/
/***********************   DATA : 14-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MAPP_interface.h"

#include "TIMER_interface.h"

#include "SERVO_private.h"
#include "SERVO_config.h"
#include "SERVO_interface.h"

u16 SERVO_u8Direction (s32 Copy_u8Value ,u16* Copy_u8ovfValue ,s32 Copy_u8MaxRang , s32 Copy_u8MinRang )
{
	s32 Local_u8TimesofServo ;
	u16 Local_u8CompValue ;

	*Copy_u8ovfValue =(u16)((20000*10UL)/(SERVO_PRE)) ;
	Local_u8TimesofServo = MAPP_S32Rang(Copy_u8MinRang,Copy_u8MaxRang,750,2500,Copy_u8Value);

	Local_u8CompValue = (u16)((Local_u8TimesofServo*10UL)/(SERVO_PRE)) ;

	return Local_u8CompValue ;

}
