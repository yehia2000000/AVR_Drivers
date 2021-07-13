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

void MOTOR_void_C_W (void)
{
	DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINA,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINB,DIO_u8PIN_HIGH);


}

void MOTOR_void_C_C_W (void)
{
	DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINB,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINA,DIO_u8PIN_HIGH);
}

void MOTOR_void_Stop (void)
{
	DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINA,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(MOTOR_u8PORT,MOTOR_u8PINB,DIO_u8PIN_LOW);
}

