/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :HAL    ***********************/
/***********************   SWC (DRIVER):MOTOR *********************/
/***********************   DATA : 5-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "MOTOR_config.h"
#include "MOTOR_interface.h"

#include <avr/delay.h>

void MOTOR_void_C_W (u16 Copy_delay )
{

	if (Copy_delay ==255)
	{
		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINA,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINB,DIO_u8PIN_HIGH);
	}
	else if (Copy_delay < 5)
	{
		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINB,DIO_u8PIN_LOW);

		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINA,DIO_u8PIN_LOW);


	}
	else
	{
		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINA,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINB,DIO_u8PIN_LOW);

        _delay_ms(255-Copy_delay);
		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINB,DIO_u8PIN_HIGH);
        _delay_ms(Copy_delay);

	}


}

void MOTOR_void_C_C_W (u16 Copy_delay )
{

	if (Copy_delay ==255)
	{
		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINB,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINA,DIO_u8PIN_HIGH);
	}
	else if (Copy_delay < 5)
	{
		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINA,DIO_u8PIN_LOW);

		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINB,DIO_u8PIN_LOW);


	}
	else
	{
		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINB,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINA,DIO_u8PIN_LOW);

        _delay_ms(255-Copy_delay);
		DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINA,DIO_u8PIN_HIGH);
        _delay_ms(Copy_delay);

	}


}

void MOTOR_void_Stop (void)
{
	DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINA,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINB,DIO_u8PIN_LOW);
}

