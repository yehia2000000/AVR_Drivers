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
		MOTOR_void_C_W(255);
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
		MOTOR_void_C_C_W(255);
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
