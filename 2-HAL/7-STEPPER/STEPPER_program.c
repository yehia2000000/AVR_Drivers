/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :HAL    ***********************/
/***********************   SWC (DRIVER):STEPPER_MOTOR *********************/
/***********************   DATA : 8-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "STEPPER_config.h"
#include "MOTOR_interface.h"
#include <util/delay.h>

void STEEPER_voidCon (void)
{
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_LOW);
	_delay_ms(2);
}
void STEEPER_voidCWAngle (u16 Copy_u16Angle)
{
	u16 Local_u16LoopCounter ;

	u16 Local_u16NumberSteps = (u16)(((((u32)Copy_u16Angle)*(2048UL))/(360UL))/(4UL));

	for (Local_u16LoopCounter =0 ;Local_u16LoopCounter<Local_u16NumberSteps;Local_u16LoopCounter++)
	{
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_HIGH);
			_delay_ms(5);

			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_HIGH);
			_delay_ms(5);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_HIGH);
			_delay_ms(5);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_LOW);
			_delay_ms(5);
	}
}

void STEEPER_voidCCWAngle (u16 Copy_u16Angle)
{
	u16 Local_u16LoopCounter ;

	u16 Local_u16NumberSteps = (u16)((((u32)Copy_u16Angle)*(2048UL))/(360UL));
		Local_u16NumberSteps/=4;
	for (Local_u16LoopCounter =0 ;Local_u16LoopCounter<Local_u16NumberSteps;Local_u16LoopCounter++)
	{
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_LOW);
			_delay_ms(5);

			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_HIGH);
			_delay_ms(5);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_HIGH);
			_delay_ms(5);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(PORT_u8STEPPER,PIN_u8STEPPER3,DIO_u8PIN_HIGH);
			_delay_ms(5);
	}
}


void STEPPER_voidAllMotor (void)
{
	char arr[]="Welcome to motor dash board application";
	char arr1[]="FOR->DCM:1";
	char arr2[]="CW :1  CCW :2";
	u8 Local_u8StatePin ;
	u16 Local_u8ValueAngle =0 ;

	s8 Local_u8LoopCounter ;
	char Hamoksha[8] = {
	0b01110,
	0b00100,
	0b01110,
	0b10101,
	0b00100,
	0b00100,
	0b00100,
	0b01010
};
for (Local_u8LoopCounter=0;Local_u8LoopCounter<15;Local_u8LoopCounter++)
{
	CLCD_voidWriteSpecialCharacter(Hamoksha,0,(0+Local_u8LoopCounter),0);
	_delay_ms(200);
	CLCD_voidSendCommand(1);
	_delay_ms(100);

}
CLCD_voidSendCommand(1);
CLCD_voidFullLcd(arr,0,0);
_delay_ms(2000);
CLCD_voidSendCommand(1);

CLCD_voidFullLcd(arr1,0,0);
CLCD_voidFullLcd("STM:2__EXIT:3",0x40,0);

Local_u8StatePin =KPD_u8PressKey();
while (Local_u8StatePin == 0xff)
{
	Local_u8StatePin =KPD_u8PressKey();

}

if (Local_u8StatePin == 1)
{
	CLCD_voidSendCommand(1);
	CLCD_voidFullLcd(arr2,0,0);
	CLCD_voidFullLcd("STOP:3",0X40,0);
	Local_u8StatePin =KPD_u8PressKey();
	while (Local_u8StatePin == 0xff)
	{
		Local_u8StatePin =KPD_u8PressKey();

	}
	if (Local_u8StatePin==1)
	{
		CLCD_voidSendCommand(1);
		CLCD_voidFullLcd("DC MOTOR RUN CW",0,0);
		MOTOR_void_C_W();
		Local_u8StatePin =KPD_u8PressKey();
		while (Local_u8StatePin == 0xff)
		{
			Local_u8StatePin =KPD_u8PressKey();

		}

	}
	else if (Local_u8StatePin ==2)
	{
		CLCD_voidSendCommand(1);
		CLCD_voidFullLcd("DC MOTOR RUN CCW",0,0);
		MOTOR_void_C_C_W();
		Local_u8StatePin =KPD_u8PressKey();
		while (Local_u8StatePin == 0xff)
		{
			Local_u8StatePin =KPD_u8PressKey();

		}
	}
	else if (Local_u8StatePin ==3)
		{
			CLCD_voidSendCommand(1);
			CLCD_voidFullLcd("DC MOTOR STOP",0,0);
			MOTOR_void_Stop();
			Local_u8StatePin =KPD_u8PressKey();
			while (Local_u8StatePin == 0xff)
			{
				Local_u8StatePin =KPD_u8PressKey();

			}
		}


	else
	{
		CLCD_voidSendCommand(1);
		CLCD_voidFullLcd("PLEASE TRY AGAIN",0,0);
		return;

	}
}
else if (Local_u8StatePin ==2)
{
	CLCD_voidSendCommand(1);
		CLCD_voidFullLcd(arr2,0,0);
		Local_u8StatePin =KPD_u8PressKey();
		while (Local_u8StatePin == 0xff)
		{
			Local_u8StatePin =KPD_u8PressKey();

		}
		if (Local_u8StatePin==2)
		{
			CLCD_voidSendCommand(1);
			CLCD_voidFullLcd("ENTER THE ANGLE :",0,0);
			Local_u8StatePin =KPD_u8PressKey();
		    while (Local_u8StatePin == 0xff)
		    {
		    	Local_u8StatePin =KPD_u8PressKey();

		    }
		    while ((Local_u8StatePin !='S')&&(Local_u8StatePin !='R')&&(Local_u8StatePin !='L')&&(Local_u8StatePin !='C'))
		    {
		    	CLCD_voidSendData('0'+Local_u8StatePin);
		    	Local_u8ValueAngle = (Local_u8ValueAngle *10) +(u16)Local_u8StatePin;
		    	Local_u8StatePin =KPD_u8PressKey();
		    	 while (Local_u8StatePin == 0xff)
		    	 {
		    	 	Local_u8StatePin =KPD_u8PressKey();

		    	 }
		    }
		    while (Local_u8ValueAngle>360)
		    {
		    	Local_u8ValueAngle =Local_u8ValueAngle -360 ;
		    }
			CLCD_voidFullLcd("STEPPER MOTOR RUN CW",0,0);
			STEEPER_voidCWAngle(Local_u8ValueAngle);
			Local_u8StatePin =KPD_u8PressKey();
			while (Local_u8StatePin == 0xff)
			{
				Local_u8StatePin =KPD_u8PressKey();

			}
		}
		else if (Local_u8StatePin ==1)
		{
			CLCD_voidSendCommand(1);
			CLCD_voidFullLcd("ENTER THE ANGLE :",0,0);
			Local_u8StatePin =KPD_u8PressKey();
			while (Local_u8StatePin == 0xff)
			{
				Local_u8StatePin =KPD_u8PressKey();

			}
			while ((Local_u8StatePin !='S')&&(Local_u8StatePin !='R')&&(Local_u8StatePin !='L')&&(Local_u8StatePin !='C'))
			{
				CLCD_voidSendData('0'+Local_u8StatePin);
				Local_u8ValueAngle = (Local_u8ValueAngle *10) +(u16)Local_u8StatePin;
				Local_u8StatePin =KPD_u8PressKey();
				 while (Local_u8StatePin == 0xff)
				 {
				 	Local_u8StatePin =KPD_u8PressKey();

				 }
			}
			while (Local_u8ValueAngle>360)
			{
				Local_u8ValueAngle =Local_u8ValueAngle -360 ;
			}
			CLCD_voidFullLcd("STEPPER MOTOR RUN CW",0,0);
			STEEPER_voidCCWAngle(Local_u8ValueAngle);
			Local_u8StatePin =KPD_u8PressKey();
			while (Local_u8StatePin == 0xff)
			{
				Local_u8StatePin =KPD_u8PressKey();

			}
		}
		else
		{
			CLCD_voidSendCommand(1);
			CLCD_voidFullLcd("PLEASE TRY AGAIN",0,0);
			return;

		}

}
else if (Local_u8StatePin == 3)
{
	CLCD_voidSendCommand(1);
	CLCD_voidFullLcd("THANK YOU",4,0);
	for (Local_u8LoopCounter =14 ;Local_u8LoopCounter>=0;Local_u8LoopCounter--)
	{
		CLCD_voidWriteSpecialCharacter(Hamoksha,0,(0x40+Local_u8LoopCounter),1);
		_delay_ms(200);
		CLCD_voidSendCommand(1);
		CLCD_voidFullLcd("THANK YOU",4,0);


	}

Local_u8StatePin =KPD_u8PressKey();
 while (Local_u8StatePin == 0xff)
{
	Local_u8StatePin =KPD_u8PressKey();

}
while (Local_u8StatePin != 'R')
{
	Local_u8StatePin =KPD_u8PressKey();
	 while (Local_u8StatePin == 0xff)
	{
		Local_u8StatePin =KPD_u8PressKey();

	}
}
CLCD_voidSendCommand(1);

}


CLCD_voidSendCommand(1);


}
