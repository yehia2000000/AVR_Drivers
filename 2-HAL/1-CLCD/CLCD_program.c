/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :	HAL    ***********************/
/***********************   SWC (DRIVER):DIO *********************/
/***********************   DATA : 25-8-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

//library
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

//mcal layer
#include "DIO_interface.h"
#include "KPD_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"



void CLCD_voidSendCommand (u8 Copy_u8Command)
{
	//set the register select to zero to active command mode
	 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	 //set RW to zero to active the effect command on the lcd
	 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

#if CLCD_MODE==MODE_8_BIT
	 DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	 //read the command by enable pin
	 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	 _delay_ms (2);
	 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
#elif CLCD_MODE==MODE_4_BIT
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Command,7));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Command,6));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Command,5));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Command,4));

	 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	 _delay_ms (2);
	 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Command,3));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Command,2));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Command,1));
	 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Command,0));

	 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	 _delay_ms (2);
	 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);


#else
#error "WRONG IN SEND COMMAND"
#endif
}
void CLCD_voidSendData (u8 Copy_u8Data)
{
	//set the register select to one to active command mode
	DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	 //set RW to zero to active the effect command on the lcd
	DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);


#if CLCD_MODE==MODE_8_BIT
	//put data on the data port
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	 //read the data by enable pin
	DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms (2);
	DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
#elif CLCD_MODE==MODE_4_BIT
	     DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Data,7));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Data,6));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Data,5));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Data,4));

		 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
		 _delay_ms (2);
		 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN7,GET_BIT(Copy_u8Data,3));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN6,GET_BIT(Copy_u8Data,2));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN5,GET_BIT(Copy_u8Data,1));
		 DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN4,GET_BIT(Copy_u8Data,0));

		 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
		 _delay_ms (2);
		 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

#else
#error "WRONG IN SEND DATA"
#endif

}
void CLCD_voidInit (void)
{
#if CLCD_MODE==MODE_8_BIT
	_delay_ms (40);
#elif CLCD_MODE==MODE_4_BIT
	_delay_ms (40);
//set the register select to zero to active command mode
 DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
 //set RW to zero to active the effect command on the lcd
 DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
 //put command on the command port

DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN7,0);
DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN6,0);
DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN5,1);
DIO_u8SetPinValue(CLCD_DATA_PORT,DIO_u8PIN4,0);

DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
_delay_ms (2);
DIO_u8SetPinValue (CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
#else
#error "WRONG IN INITIALIZATION"
#endif

	// wait for more than 30 ms

	//function set Set command 2lines , font =5*7
	CLCD_voidSendCommand(0b00101000);

	CLCD_voidSendCommand(0b00001100);

	CLCD_voidSendCommand(0b00000001);


}
void CLCD_voidSendString(const char * Copy_phString )
{
   u8 Local_LoopCounter;
   for (Local_LoopCounter=0;(*(Copy_phString+Local_LoopCounter))!=0;Local_LoopCounter++)
   {
	   CLCD_voidSendData(*(Copy_phString+Local_LoopCounter));

   }
}
void CLCD_voidSendNumber (u32 Copy_u32Number)
{
	u8 Local_u8Counter=0;
	u8 Local_u8Counter1=0;
	u8 Local_u8Counter3 ;
	u32 Local_u8Temp =Copy_u32Number;
	u32 Local_u8Temp2 =Copy_u32Number;
	u32 Local_u8result;
	do {
		Local_u8Temp /=10 ;
		Local_u8Counter++;
}while(Local_u8Temp !=0);
	Local_u8Counter3 =Local_u8Counter;
for (Local_u8Counter1 =0;Local_u8Counter1<Local_u8Counter;Local_u8Counter1++)
{
do
{
	Local_u8result =Local_u8Temp2 %10;
	Local_u8Temp2 /=10 ;
	Local_u8Counter3--;
}
while (Local_u8Counter3>Local_u8Counter1);
Local_u8Counter3 = Local_u8Counter;
Local_u8Temp2 =Copy_u32Number;
CLCD_voidSendData('0'+Local_u8result);

}

}
void CLCD_voidCalcu (void)
{
	u8 Local_u8Value0 ;
	u8 Local_u8Value1 ;
	u8 Local_u8Value2 ;
	u8 Local_u8Value3 ;

	u8 *Local_u8ResVal0 =&Local_u8Value0;
	u8 *Local_u8ResVal1 =&Local_u8Value1;
	u8 *Local_u8ResVal2 =&Local_u8Value2;
	u8 *Local_u8ResVal3 =&Local_u8Value3;

	u8 Local_u8Counter =0 ;

	static f32 Local_u8IndValue0 =1 ;
	static s32 Local_u8IndValue1 =0;
	static f32 Local_u8IndValue2 =1 ;
	static f32 Local_u8Result ;
	u32 Local_u32Float ;

	static u8 Local_indPos =0 ;

	static u8 Local_u8Counter1 =0 ;



	if (Local_u8Counter1 ==0 )
	{
	CLCD_voidSendData('1');
	CLCD_voidSendData('+');
	CLCD_voidSendData('1');
	CLCD_voidSendCommand(0b00010011);
	CLCD_voidSendCommand(0b00010011);
	CLCD_voidSendCommand(0b00010011);
	Local_u8Counter1++;
	}

	while (1)
	{
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0,Local_u8ResVal0);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN1,Local_u8ResVal1);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,Local_u8ResVal2);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN3,Local_u8ResVal3);
		if ((*Local_u8ResVal0)==0)
		{

		Local_u8Counter++;
		_delay_ms(50);
		}
		else if ((*Local_u8ResVal1)==0)
		{

			Local_u8Counter++;
			_delay_ms(50);
		}
		else if ((*Local_u8ResVal2)==0)
		{

			Local_u8Counter++;
			_delay_ms(50);
		}
		else if ((*Local_u8ResVal3)==0)
		{

		Local_u8Counter++;
		_delay_ms(50);
		}

		if (Local_u8Counter>2)
		{

			break;
		}

	}
/*up the data */
if ((*Local_u8ResVal0)==0)
{
	if (Local_indPos ==0)
	{

		Local_u8IndValue0++;
		if (Local_u8IndValue0>9)
		{
			Local_u8IndValue0 =1 ;
		}
		CLCD_voidSendData('0'+Local_u8IndValue0);
		CLCD_voidSendCommand(0b00010011);
	}
	else if (Local_indPos ==1)
		{


			Local_u8IndValue1++;
			if (Local_u8IndValue1>3)
			{
				Local_u8IndValue1 =0 ;
			}
			switch (Local_u8IndValue1)
			{
			case 0 :CLCD_voidSendData('+'); CLCD_voidSendCommand(0b00010011);break;
			case 1 :CLCD_voidSendData('*'); CLCD_voidSendCommand(0b00010011);break;
			case 2 : CLCD_voidSendData('/');CLCD_voidSendCommand(0b00010011);break;
			case 3 : CLCD_voidSendData('-');CLCD_voidSendCommand(0b00010011);break;

			}
		}
	else if (Local_indPos ==2)
		{

			Local_u8IndValue2++;
			if (Local_u8IndValue2>9)
			{
				Local_u8IndValue2 =1 ;
			}
			CLCD_voidSendData('0'+Local_u8IndValue2);
			CLCD_voidSendCommand(0b00010011);
		}


}
/*down the data*/
else if ((*Local_u8ResVal1)==0)
{
	if (Local_indPos ==0)
		{

			Local_u8IndValue0--;
			if (Local_u8IndValue0<0)
			{
				Local_u8IndValue0 =9 ;
			}
			CLCD_voidSendData('0'+Local_u8IndValue0);
			CLCD_voidSendCommand(0b00010011);
		}
		else if (Local_indPos ==1)
			{
			Local_u8IndValue1--;

				if (Local_u8IndValue1<0)
				{
					Local_u8IndValue1 =3 ;
				}

				switch (Local_u8IndValue1)
				{
				case 0 :CLCD_voidSendData('+');CLCD_voidSendCommand(0b00010011); break;
				case 1 :CLCD_voidSendData('*');CLCD_voidSendCommand(0b00010011); break;
				case 2 : CLCD_voidSendData('/');CLCD_voidSendCommand(0b00010011);break;
				case 3 : CLCD_voidSendData('-');CLCD_voidSendCommand(0b00010011);break;

				}

			}
		else if (Local_indPos ==2)
			{

				Local_u8IndValue2--;
				if (Local_u8IndValue1==2)
				{
				if (Local_u8IndValue2<=0)
				{
					Local_u8IndValue2 =9 ;
				}
				}
				else
				{
					if (Local_u8IndValue2<0)
					{
						Local_u8IndValue2 =9 ;
					}
				}
				CLCD_voidSendData('0'+Local_u8IndValue2);
				CLCD_voidSendCommand(0b00010011);
			}

}
/*enter */
else if ((*Local_u8ResVal2)==0)
{


	Local_indPos++;
	CLCD_voidSendCommand(0b00010111);
	if (Local_indPos==3)
	{

		switch (Local_u8IndValue1)
		{
		case 0 :Local_u8Result = Local_u8IndValue0 +Local_u8IndValue2	; break;
		case 1 :Local_u8Result = Local_u8IndValue0 *Local_u8IndValue2	; break;
		case 2 :Local_u8Result = Local_u8IndValue0 /Local_u8IndValue2	;break;
		case 3 :Local_u8Result = Local_u8IndValue0 -Local_u8IndValue2	;break;

		}
		if (Local_u8Result<0)
		{
			Local_u8Result *=-1;
			CLCD_voidSendData('=');
			CLCD_voidSendData('-');
			CLCD_voidSendNumber ((u32)Local_u8Result);

		}
		else
		{
			CLCD_voidSendData('=');
			CLCD_voidSendNumber ((u32)Local_u8Result);
			Local_u32Float = (Local_u8Result -(u32)Local_u8Result)*10 ;
			CLCD_voidSendData('.');
			CLCD_voidSendNumber ((u32)Local_u32Float);
		while (Local_u32Float!=0)
			{
			Local_u32Float = (Local_u32Float -(u32)Local_u32Float)*10 ;
			CLCD_voidSendNumber ((u32)Local_u32Float);

			}

		}
	}
	else if (Local_indPos==4)
	{
		CLCD_voidSendCommand(1);
		CLCD_voidSendData('1');
		CLCD_voidSendData('+');
		CLCD_voidSendData('1');
		CLCD_voidSendCommand(0b00010011);
			CLCD_voidSendCommand(0b00010011);
			CLCD_voidSendCommand(0b00010011);
			Local_u8IndValue0 =1;
				Local_u8IndValue1 =0;
				Local_u8IndValue2=1;
				Local_u8Result =0 ;
				Local_indPos =0;

	}

}
//reset
else if ((*Local_u8ResVal3)==0)
{
	CLCD_voidSendCommand(1);
	CLCD_voidSendData('1');
	CLCD_voidSendData('+');
	CLCD_voidSendData('1');
	CLCD_voidSendCommand(0b00010011);
	CLCD_voidSendCommand(0b00010011);
	CLCD_voidSendCommand(0b00010011);
	Local_indPos =0;

	Local_u8IndValue0 =1;
	Local_u8IndValue1 =0;
	Local_u8IndValue2=1;
	Local_u8Result =0 ;


}




}

void CLCD_voidGotoXY (u8 Copy_u8PosX ,u8 Copy_u8PosY)
{

	u8 Local_u8DDRAMAddress ;

	if (Copy_u8PosY == 0)
	{
		Local_u8DDRAMAddress =Copy_u8PosX;
	}
	else
	{
		Local_u8DDRAMAddress =Copy_u8PosX;
	}

	CLCD_voidSendCommand(Local_u8DDRAMAddress +128);
}
void CLCD_voidFullLcd (const char *Copy_pu8String ,u8 Copy_u8PosX ,u8 Copy_u8PosY)
{
	u8 Local_u8CounterLoop ;
	CLCD_voidGotoXY(Copy_u8PosX,Copy_u8PosY);
	for (Local_u8CounterLoop =0 ; (*(Copy_pu8String+Local_u8CounterLoop))!=0;Local_u8CounterLoop++)
	{
		CLCD_voidSendData(*(Copy_pu8String+Local_u8CounterLoop));
		Copy_u8PosX++;
		if (Copy_u8PosX>15&&Copy_u8PosX<=16)
		{
			CLCD_voidGotoXY(0x40,1);
		}
	}

}

void CLCD_voidWriteSpecialCharacter(const char *Copy_pu8String ,u8 Copy_u8NumberPatttern,u8 Copy_u8PosX, u8 Copy_u8PosY)
{
	u8 Local_u8DDRAMAddress = Copy_u8NumberPatttern *8 ;

	u8 Local_u8LoopCounter ;

	CLCD_voidSendCommand(Local_u8DDRAMAddress +64);

	for (Local_u8LoopCounter=0;Local_u8LoopCounter<8;Local_u8LoopCounter++)
	{
		CLCD_voidSendData(*(Copy_pu8String+Local_u8LoopCounter));
	}

	CLCD_voidGotoXY(Copy_u8PosX,Copy_u8PosY);

	CLCD_voidSendData(Copy_u8NumberPatttern);


}

void CLCD_voidCalcuPos (u8 Copy_u8PosX, u8 Copy_u8PosY)
{
	/* variable carry the status of pins*/
	static u8 Local_u8ValuePin0 ; // up pin
	static u8 Local_u8ValuePin1 ; //down pin
	static u8 Local_u8ValuePin2 ; //entered pin
	static u8 Local_u8ValuePin3 ; //reset Pin

	/*pointer to look at the pins value */
	static u8 * Local_pu8ValuePin0=& Local_u8ValuePin0;
	static u8 * Local_pu8ValuePin1=& Local_u8ValuePin1;
	static u8 * Local_pu8ValuePin2=& Local_u8ValuePin2;
	static u8 * Local_pu8ValuePin3=& Local_u8ValuePin3;

	/*counter to solve bouning*/
	static u8 Local_u8CounterLoop0 =0; //counter to Pin 0
	static u8 Local_u8CounterLoop1 =0; //counter to Pin 1
	static u8 Local_u8CounterLoop2 =0; //counter to Pin 2
	static u8 Local_u8CounterLoop3 =0; //counter to Pin 3

	/*index the position (var) */

	static u8 Local_u8IndexValue ;

	/*the result of value */
	static f32 Local_u8Result ;

	/*Value of index */

	static f32 Local_u8ValueIndex0=1;
	static s8 Local_u8ValueIndex1 =0;
	static f32 Local_u8ValueIndex2=1;
	static f32 Local_u8Frac ;

	//flag first

	static u8 Local_u8loop =0  ;


	/*index of the position */
	char customChar1[8] = {
			0b00100,
			0b01110,
			0b10101,
			0b00100,
			0b00100,
			0b00100,
			0b00100,
			0b00100
		};
	char customChar2[8] = {
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000
	};
	/*initialization
	 *  of lcd */
if (Local_u8loop==0)
{
	CLCD_voidWriteSpecialCharacter(customChar1,0,0x40+Copy_u8PosX,Copy_u8PosY);
	CLCD_voidGotoXY(Copy_u8PosX,Copy_u8PosY);
	CLCD_voidSendData('1');
	CLCD_voidSendData('+');
	CLCD_voidSendData('1');
	CLCD_voidGotoXY(Copy_u8PosX,Copy_u8PosY);
	Local_u8loop++;
}
	while (1)
	{
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0,Local_pu8ValuePin0);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN1,Local_pu8ValuePin1);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,Local_pu8ValuePin2);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN3,Local_pu8ValuePin3);

		if ( (* Local_pu8ValuePin0)==0)
		{
			Local_u8CounterLoop0++;
			_delay_ms(75);
		}
		else if ((* Local_pu8ValuePin1)==0)
		{
			Local_u8CounterLoop1++;
			_delay_ms(75);
		}
		else if ((* Local_pu8ValuePin2)==0)
		{
			Local_u8CounterLoop2++;
			_delay_ms(75);
		}

		else if ((* Local_pu8ValuePin3)==0)
		{
			Local_u8CounterLoop3++;
			_delay_ms(75);
		}

		if (Local_u8CounterLoop0==2)
		{
			break;
		}
		else if(Local_u8CounterLoop1==2)
		{
			break;
		}
		else if(Local_u8CounterLoop2==2)
		{
			break;
		}
		else if(Local_u8CounterLoop3==2)
		{
			break;
		}
	}

//PIN0 : UP
	if (Local_u8CounterLoop0==2)
	{
		if (Local_u8IndexValue==0)
		{

			Local_u8ValueIndex0++;
			if (Local_u8ValueIndex0>9)
			{
				Local_u8ValueIndex0=0;
			}
			CLCD_voidSendData('0'+Local_u8ValueIndex0);
			CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY);


		}
		else if (Local_u8IndexValue==1)
		{

			Local_u8ValueIndex1++;
			if (Local_u8ValueIndex1>3)
			{
				Local_u8ValueIndex1 =0;
			}
			switch (Local_u8ValueIndex1)
			{
			case 0 : CLCD_voidSendData('+'); CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY); break;
			case 1 :CLCD_voidSendData('-'); CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY); break;
			case 2 :CLCD_voidSendData('*'); CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY); break;
			case 3 :CLCD_voidSendData('/'); CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY); break;
			}

		}
		else if (Local_u8IndexValue==2)
		{
			Local_u8ValueIndex2++;
		    if ((Local_u8ValueIndex2>9)&&(Local_u8ValueIndex1==3))
		    {
		    	Local_u8ValueIndex2=1;
		    }
		    else if ((Local_u8ValueIndex2>9)&&(Local_u8ValueIndex1!=3))
		    {
		    	Local_u8ValueIndex2=0;
		    }
		    CLCD_voidSendData('0'+Local_u8ValueIndex2);
		    CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY);


		}

		Local_u8CounterLoop0 =0 ;
	}

	// PIN2 :DOWN
	else if (Local_u8CounterLoop1==2)
	{
		if (Local_u8IndexValue==0)
		{

			Local_u8ValueIndex0--;
			if (Local_u8ValueIndex0<0)
			{
				Local_u8ValueIndex0=9;
			}
			CLCD_voidSendData('0'+Local_u8ValueIndex0);
			CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY);


		}
		else if (Local_u8IndexValue==1)
		{

			Local_u8ValueIndex1--;
			if (Local_u8ValueIndex1<0)
			{
				Local_u8ValueIndex1 =3;
			}
			switch (Local_u8ValueIndex1)
			{
			case 0 : CLCD_voidSendData('+'); CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY); break;
			case 1 :CLCD_voidSendData('-'); CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY); break;
			case 2 :CLCD_voidSendData('*'); CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY); break;
			case 3 :CLCD_voidSendData('/'); CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY); break;
			}

		}
		else if (Local_u8IndexValue==2)
		{
			Local_u8ValueIndex2--;
			if ((Local_u8ValueIndex2<=0)&&(Local_u8ValueIndex1==3))
			 {
			 	Local_u8ValueIndex2=9;
			 }
			 else if ((Local_u8ValueIndex2<0)&&(Local_u8ValueIndex1!=3))
			 {
			 	Local_u8ValueIndex2=9;
			 }
		    CLCD_voidSendData('0'+Local_u8ValueIndex2);
		    CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY);




		}

		Local_u8CounterLoop1 =0 ;
	}
	else if (Local_u8CounterLoop2==2)
	{

		if (Local_u8IndexValue==0)
		{


			CLCD_voidWriteSpecialCharacter(customChar2,1,0x40+Copy_u8PosX+Local_u8IndexValue,1);
			Local_u8IndexValue++;
			CLCD_voidWriteSpecialCharacter(customChar1,0,0x40+Copy_u8PosX+Local_u8IndexValue,1);
			CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY);



		}
		else if (Local_u8IndexValue==1)
		{

		    CLCD_voidWriteSpecialCharacter(customChar2,1,0x40+Copy_u8PosX+Local_u8IndexValue,1);
		    Local_u8IndexValue++;
		    CLCD_voidWriteSpecialCharacter(customChar1,0,0x40+Copy_u8PosX+Local_u8IndexValue,1);
		    CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY);

		}
		else if (Local_u8IndexValue==2)
		{
		   CLCD_voidWriteSpecialCharacter(customChar2,1,0x40+Copy_u8PosX+Local_u8IndexValue,1);
		   Local_u8IndexValue++;
           CLCD_voidWriteSpecialCharacter(customChar1,0,0x40+Copy_u8PosX+Local_u8IndexValue,1);
           CLCD_voidGotoXY(Copy_u8PosX+Local_u8IndexValue,Copy_u8PosY);
           switch (Local_u8ValueIndex1)
            {
            case 0:Local_u8Result = Local_u8ValueIndex0 +Local_u8ValueIndex2 ; break;
            case 1:Local_u8Result = Local_u8ValueIndex0 -Local_u8ValueIndex2 ; break ;
            case 2:Local_u8Result = Local_u8ValueIndex0 *Local_u8ValueIndex2 ; break ;
            case 3:Local_u8Result = Local_u8ValueIndex0 /Local_u8ValueIndex2 ; break ;

            }


            CLCD_voidSendData('=');
            if (Local_u8Result<0)
              {
                  Local_u8Result*=-1;
                  CLCD_voidSendData('-');
              }
            CLCD_voidSendNumber((u32)Local_u8Result);
            Local_u8Frac = (Local_u8Result -(u32)Local_u8Result)*100 ;
            CLCD_voidSendData('.');

            CLCD_voidSendNumber(((u32)Local_u8Frac));


		}
		else if (Local_u8IndexValue==3)
		{
			Local_u8ValueIndex0=1;
			Local_u8ValueIndex1=0;
			Local_u8ValueIndex2=1;
			Local_u8IndexValue =0;

			CLCD_voidSendCommand(1);
			CLCD_voidWriteSpecialCharacter(customChar1,0,0x40+Copy_u8PosX+Local_u8IndexValue,1);
			CLCD_voidGotoXY(Copy_u8PosX,Copy_u8PosY);
			CLCD_voidSendData('1');
			CLCD_voidSendData('+');
			CLCD_voidSendData('1');
			CLCD_voidGotoXY(Copy_u8PosX,Copy_u8PosY);


		}


		Local_u8CounterLoop2 =0 ;
	}
	else if (Local_u8CounterLoop3==2)
	{
		Local_u8ValueIndex0=1;
		Local_u8ValueIndex1=0;
		Local_u8ValueIndex2=1;
		Local_u8IndexValue =0;
		CLCD_voidSendCommand(1);


		CLCD_voidWriteSpecialCharacter(customChar1,0,0x40+Copy_u8PosX+Local_u8IndexValue,1);
		CLCD_voidGotoXY(Copy_u8PosX,Copy_u8PosY);
		CLCD_voidSendData('1');
		CLCD_voidSendData('+');
		CLCD_voidSendData('1');
		CLCD_voidGotoXY(Copy_u8PosX,Copy_u8PosY);


		Local_u8CounterLoop3 =0 ;
	}
}


void CLCD_sinusoidal (const char* arr ,u8 Copy_u8PosX, u8 Copy_u8PosY,u8 size)
{
	u8 Local_u8FirstLocation=0;
	CLCD_voidGotoXY(Copy_u8PosX,Copy_u8PosY);
	CLCD_voidSendString(arr);
	_delay_ms(1000);
	Local_u8FirstLocation+=size;
	CLCD_voidSendCommand(1);

	CLCD_voidGotoXY(0x40+Copy_u8PosX+Local_u8FirstLocation,1);
	CLCD_voidSendString(arr);
	_delay_ms(1000);
	Local_u8FirstLocation+=size;
	CLCD_voidSendCommand(1);

	CLCD_voidGotoXY(Copy_u8PosX+Local_u8FirstLocation,0);
	CLCD_voidSendString(arr);
	_delay_ms(1000);
	Local_u8FirstLocation+=size;
	CLCD_voidSendCommand(1);

	CLCD_voidGotoXY(0x40+Copy_u8PosX+Local_u8FirstLocation,1);
	CLCD_voidSendString(arr);
	_delay_ms(1000);
	CLCD_voidSendCommand(1);


}


void CLCD_voidHamoksha (void)
{
	 u8 Local_u8LoopCounter ;
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
	char football1[8] = {
		0b01110,
		0b00100,
		0b01110,
		0b10101,
		0b00100,
		0b00100,
		0b00101,
		0b11011
	};
	char football2[8] = {
		0b01110,
		0b00100,
		0b01110,
		0b10101,
		0b00100,
		0b00101,
		0b11011,
		0b00000
	};
	char football3[8] = {
			0b01110,
			0b00100,
			0b00101,
			0b01110,
			0b10101,
			0b00100,
			0b01011,
			0b10000
		};
	char clear[8] = {
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000
	};
	char dance1[8] = {
		0b01110,
		0b00100,
		0b00100,
		0b11111,
		0b00100,
		0b00100,
		0b01010,
		0b10001
	};
	char dance2[8] = {
		0b01110,
		0b00100,
		0b00101,
		0b11111,
		0b10100,
		0b00100,
		0b00100,
		0b01010
	};
	char dance3[8] = {
		0b01110,
		0b00100,
		0b10100,
		0b11111,
		0b00101,
		0b00100,
		0b00100,
		0b01010
	};
	char run1 [8] = {
		0b01110,
		0b00100,
		0b00100,
		0b01110,
		0b10101,
		0b00100,
		0b01010,
		0b10001
	};
	char run2 [8] = {
		0b01110,
		0b00100,
		0b00100,
		0b01110,
		0b01101,
		0b00100,
		0b01010,
		0b01001
	};
	char run3 [8] = {
		0b01110,
		0b00100,
		0b00100,
		0b01110,
		0b01110,
		0b00100,
		0b00100,
		0b01010
	};
	char Gun[8] = {
		0b11111,
		0b10001,
		0b10001,
		0b10111,
		0b11100,
		0b11000,
		0b11100,
		0b11100
	};
	char bullet [8] = {
			0b00000,
			0b00000,
			0b00100,
			0b00000,
			0b00000,
			0b00000,
			0b00000,
			0b00000
		};
	char killed [8] = {
		0b00000,
		0b00000,
		0b01000,
		0b10101,
		0b01111,
		0b10101,
		0b01000,
		0b00000
	};
	char killed2[8] = {
		0b00111,
		0b01010,
		0b00110,
		0b10110,
		0b01001,
		0b10000,
		0b00000,
		0b00000
	};
	CLCD_voidSendCommand(1);
	CLCD_voidGotoXY(0,0);
	CLCD_voidSendString("Hi iam Hamoksha");
	CLCD_voidWriteSpecialCharacter(Hamoksha,0,0x40+6,1);
	_delay_ms(2000);
	CLCD_voidSendCommand(1);
	CLCD_voidGotoXY(0,0);
	CLCD_voidSendString("I can play foot");
	for (Local_u8LoopCounter=0;Local_u8LoopCounter<5;Local_u8LoopCounter++)
	{
		CLCD_voidWriteSpecialCharacter(football1,1,0x40+Local_u8LoopCounter*3,1);
		_delay_ms(500);
		CLCD_voidWriteSpecialCharacter(clear,4,0x40+Local_u8LoopCounter*3,1);

		CLCD_voidWriteSpecialCharacter(football2,2,1+0x40+Local_u8LoopCounter*3,1);
		_delay_ms(500);
		CLCD_voidWriteSpecialCharacter(clear,4,1+0x40+Local_u8LoopCounter*3,1);

		CLCD_voidWriteSpecialCharacter(football3,3,2+0x40+Local_u8LoopCounter*3,1);
		_delay_ms(500);
		CLCD_voidWriteSpecialCharacter(clear,4,2+0x40+Local_u8LoopCounter*3,1);

	}
	CLCD_voidSendCommand(1);
		CLCD_voidGotoXY(0,0);
		CLCD_voidSendString("I can dance");
		for (Local_u8LoopCounter=0;Local_u8LoopCounter<5;Local_u8LoopCounter++)
		{
			CLCD_voidWriteSpecialCharacter(dance1,1,0x40+Local_u8LoopCounter*3,1);
			_delay_ms(500);
			CLCD_voidWriteSpecialCharacter(clear,4,0x40+Local_u8LoopCounter*3,1);

			CLCD_voidWriteSpecialCharacter(dance2,2,1+0x40+Local_u8LoopCounter*3,1);
			_delay_ms(500);
			CLCD_voidWriteSpecialCharacter(clear,4,1+0x40+Local_u8LoopCounter*3,1);

			CLCD_voidWriteSpecialCharacter(dance3,3,2+0x40+Local_u8LoopCounter*3,1);
			_delay_ms(500);
			CLCD_voidWriteSpecialCharacter(clear,4,2+0x40+Local_u8LoopCounter*3,1);

		}
		CLCD_voidSendCommand(1);
		CLCD_voidGotoXY(0,0);
		CLCD_voidSendString("I can run");
		for (Local_u8LoopCounter=0;Local_u8LoopCounter<5;Local_u8LoopCounter++)
		{
			CLCD_voidWriteSpecialCharacter(run1,1,0x40+Local_u8LoopCounter*3,1);
			_delay_ms(500);
			CLCD_voidWriteSpecialCharacter(clear,4,0x40+Local_u8LoopCounter*3,1);

			CLCD_voidWriteSpecialCharacter(run2,2,1+0x40+Local_u8LoopCounter*3,1);
			_delay_ms(500);
			CLCD_voidWriteSpecialCharacter(clear,4,1+0x40+Local_u8LoopCounter*3,1);

			CLCD_voidWriteSpecialCharacter(run3,3,2+0x40+Local_u8LoopCounter*3,1);
			_delay_ms(500);
			CLCD_voidWriteSpecialCharacter(clear,4,2+0x40+Local_u8LoopCounter*3,1);

		}
		CLCD_voidSendCommand(1);
		CLCD_voidGotoXY(0,0);
		CLCD_voidSendString("don't kill me");
		CLCD_voidWriteSpecialCharacter(Gun,5,0x40,1);
		CLCD_voidWriteSpecialCharacter(Hamoksha,0,0x4E,1);

		for (Local_u8LoopCounter=1;Local_u8LoopCounter<5;Local_u8LoopCounter++)
		{
			CLCD_voidWriteSpecialCharacter(bullet,1,0x40+Local_u8LoopCounter*3,1);
			_delay_ms(500);
			CLCD_voidWriteSpecialCharacter(clear,4,0x40+Local_u8LoopCounter*3,1);

			CLCD_voidWriteSpecialCharacter(bullet,2,1+0x40+Local_u8LoopCounter*3,1);
			_delay_ms(500);
			CLCD_voidWriteSpecialCharacter(clear,4,1+0x40+Local_u8LoopCounter*3,1);

			CLCD_voidWriteSpecialCharacter(bullet,3,2+0x40+Local_u8LoopCounter*3,1);
			_delay_ms(500);
			CLCD_voidWriteSpecialCharacter(clear,4,2+0x40+Local_u8LoopCounter*3,1);

		}

		CLCD_voidWriteSpecialCharacter(killed2,3,0x4E,1);
		_delay_ms(500);
		CLCD_voidWriteSpecialCharacter(killed,3,0x4E,1);
		_delay_ms(500);

}

void calc_voidKpd (void)
{
	s32 Local_u8Value1=0 , Local_u8Value2=0 ,Local_u8Value3=0 ;
	u8 Local_u8PresseKey ;
	u8 Local_u8Operation;
	Local_u8PresseKey=KPD_u8PressKey ();

	while (Local_u8PresseKey==0xff)
	{
		Local_u8PresseKey=KPD_u8PressKey ();
	}
	while ((Local_u8PresseKey != '/')&&(Local_u8PresseKey != '+')&&(Local_u8PresseKey != '-')&&(Local_u8PresseKey != '*')&&(Local_u8PresseKey != 'c')&&(Local_u8PresseKey != '='))
	{
		Local_u8Value1 =Local_u8Value1*10 +Local_u8PresseKey ;
		CLCD_voidSendData('0'+Local_u8PresseKey);
		Local_u8PresseKey=KPD_u8PressKey ();
		while (Local_u8PresseKey==0xff)
	    {
	    	Local_u8PresseKey=KPD_u8PressKey ();
	    }

	}
	Local_u8Operation =Local_u8PresseKey ;
	CLCD_voidSendData(Local_u8PresseKey);


	Local_u8PresseKey=KPD_u8PressKey ();
	while (Local_u8PresseKey==0xff)
	 {
		Local_u8PresseKey=KPD_u8PressKey ();
	 }

	while ((Local_u8PresseKey == '/')||(Local_u8PresseKey == '+')||(Local_u8PresseKey == '-')||(Local_u8PresseKey == '*')||(Local_u8PresseKey == 'c'))
		{
		CLCD_voidSendData(Local_u8PresseKey);
		Local_u8PresseKey=KPD_u8PressKey ();
		while (Local_u8PresseKey==0xff)
			{
				Local_u8PresseKey=KPD_u8PressKey ();
			}

		}
	if (Local_u8PresseKey=='=')
	{
		Local_u8Value3=Local_u8Value1+Local_u8Value2;
		CLCD_voidSendNumber(Local_u8Value3);

	}
	else
	{
		while ((Local_u8PresseKey != '/')&&(Local_u8PresseKey != '+')&&(Local_u8PresseKey != '-')&&(Local_u8PresseKey != '*')&&(Local_u8PresseKey != 'c')&&(Local_u8PresseKey != '='))
		{
			Local_u8Value2 =Local_u8Value2*10 +Local_u8PresseKey ;
			CLCD_voidSendData('0'+Local_u8PresseKey);
			Local_u8PresseKey=KPD_u8PressKey ();
			while (Local_u8PresseKey==0xff)
				    {
				    	Local_u8PresseKey=KPD_u8PressKey ();
				    }

		}
		CLCD_voidSendData(Local_u8PresseKey);
		if (Local_u8PresseKey=='=')
		{
			switch (Local_u8Operation)
						{
						case '+':
						    Local_u8Value3=Local_u8Value1+Local_u8Value2;
						    CLCD_voidSendNumber(Local_u8Value3);
						    break;
						case '-':
							Local_u8Value3=Local_u8Value1-Local_u8Value2;
							if (Local_u8Value3<0)
							{
								Local_u8Value3 *=-1;
								CLCD_voidSendData('-');
							}
							CLCD_voidSendNumber(Local_u8Value3);
							break;
						case '*':
							Local_u8Value3=Local_u8Value1*Local_u8Value2;
							CLCD_voidSendNumber(Local_u8Value3);
							break;
						case '/':
							Local_u8Value3=Local_u8Value1/Local_u8Value2;
							CLCD_voidSendNumber(Local_u8Value3);
							break;
						}

		}

	}
	Local_u8PresseKey=KPD_u8PressKey ();
	while (Local_u8PresseKey==0xff)
	{
		Local_u8PresseKey=KPD_u8PressKey ();
	}
	if (Local_u8PresseKey=='c')
	{
		CLCD_voidSendCommand(1);
		return;
	}
	while (Local_u8PresseKey != '=')
	{
		Local_u8PresseKey=KPD_u8PressKey ();
	}
	CLCD_voidSendCommand(1);


}
void CLCD_voidMove(void)
{ static u8 Copy_u8PosX=X_POS;
  static u8 Copy_u8PosY=Y_POS;


u8 Local_u8StatePin;

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

CLCD_voidWriteSpecialCharacter(Hamoksha,0,Copy_u8PosX,Copy_u8PosY);

Local_u8StatePin = KPD_u8PressKey();

while (Local_u8StatePin == 0xff)
{
	Local_u8StatePin = KPD_u8PressKey();
}

if (Local_u8StatePin == 5)
{
	CLCD_voidSendCommand(1);
	if (Copy_u8PosY ==1)
	{
		Copy_u8PosY =0 ;
		Copy_u8PosX-=0X40;
	CLCD_voidWriteSpecialCharacter(Hamoksha,0,Copy_u8PosX,Copy_u8PosY);
	}
}
else if (Local_u8StatePin == 'c')
{
	CLCD_voidSendCommand(1);
	if (Copy_u8PosY ==0)
	{
		Copy_u8PosY =1 ;
		Copy_u8PosX+=0X40;
	CLCD_voidWriteSpecialCharacter(Hamoksha,0,Copy_u8PosX,Copy_u8PosY);
	}

}
else if (Local_u8StatePin == 7)
{
	CLCD_voidSendCommand(1);

	Copy_u8PosX -=1 ;
	CLCD_voidWriteSpecialCharacter(Hamoksha,0,Copy_u8PosX,Copy_u8PosY);
}
else if (Local_u8StatePin == 9)
{
	CLCD_voidSendCommand(1);

	Copy_u8PosX +=1 ;
	CLCD_voidWriteSpecialCharacter(Hamoksha,0,Copy_u8PosX,Copy_u8PosY);
}

}




void CLCD_voidStopWatch (void)
{

	static u8 Local_u8LoopCounter =0 ;

	static u8 Local_u8PosX =0 ;
	static u8 Local_u8PosY =0 ;
char customChar1[8] = {
 0b00100,
 0b01110,
 0b10101,
 0b00100,
 0b00100,
 0b00100,
 0b00100,
 0b00100
};
char customChar2[8] = {
 0b00000,
 0b00000,
 0b00000,
 0b00000,
 0b00000,
 0b00000,
 0b00000,
 0b00000
};
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


u8 Local_u8StatePin;


static u8 Local_u8ValueHour ; /*position 0,1*/
static u8 Local_u8ValueMinute ; /*position 3,4*/
static u8 Local_u8ValueSecond ;/*position 6,7*/


	if (Local_u8LoopCounter == 0)
	{

		CLCD_voidSendString("--:--:--");
		CLCD_voidGotoXY(Local_u8PosX,Local_u8PosY);
		CLCD_voidWriteSpecialCharacter(customChar1,0,Local_u8PosX+0x40,Local_u8PosY);
		Local_u8StatePin = KPD_u8PressKey();
			while (Local_u8StatePin==0xff)
			{
				Local_u8StatePin =KPD_u8PressKey();
			}
	}





	while (Local_u8StatePin != 'R' && Local_u8StatePin != 'L'&&Local_u8StatePin != 'S' )
	{
		if (Local_u8StatePin == 'C')
		{
			CLCD_voidWriteSpecialCharacter(customChar2,1,Local_u8PosX+0x40,Local_u8PosY);
			Local_u8PosX =0 ;
			Local_u8PosY =0 ;
			CLCD_voidGotoXY(Local_u8PosX,Local_u8PosY);
			CLCD_voidSendString("--:--:--");
			CLCD_voidGotoXY(Local_u8PosX,Local_u8PosY);
			CLCD_voidWriteSpecialCharacter(customChar1,0,Local_u8PosX+0x40,Local_u8PosY);
			Local_u8StatePin = KPD_u8PressKey();
			while (Local_u8StatePin==0xff)
			{
				Local_u8StatePin =KPD_u8PressKey();
			}


		}

		CLCD_voidGotoXY(Local_u8PosX,Local_u8PosY);


		switch (Local_u8PosX)
		{
		case 0 : Local_u8ValueHour =Local_u8StatePin; break;
		case 1 : Local_u8ValueHour =Local_u8ValueHour *10 + Local_u8StatePin;break;
		case 3 : Local_u8ValueMinute =Local_u8StatePin; break;
		case 4 : Local_u8ValueMinute =Local_u8ValueMinute *10 + Local_u8StatePin;break;
		case 6 : Local_u8ValueSecond =Local_u8StatePin; break;
		case 7 : Local_u8ValueSecond =Local_u8ValueSecond *10 + Local_u8StatePin;break;

		}
		if ((Local_u8PosX != 2) && (Local_u8PosX !=5))
		{
			CLCD_voidSendData('0'+Local_u8StatePin);
		}
		Local_u8StatePin = KPD_u8PressKey();
		while (Local_u8StatePin==0xff)
		{
			Local_u8StatePin =KPD_u8PressKey();
		}


	}

	while ((Local_u8StatePin == 'R') || (Local_u8StatePin == 'L')|| (Local_u8StatePin == 'S' ))
	{
		if (Local_u8StatePin == 'C')
		{
			CLCD_voidWriteSpecialCharacter(customChar2,1,Local_u8PosX+0x40,Local_u8PosY);
			Local_u8PosX =0 ;
			Local_u8PosY =0 ;
			CLCD_voidGotoXY(Local_u8PosX,Local_u8PosY);
			CLCD_voidSendString("--:--:--");
			CLCD_voidGotoXY(Local_u8PosX,Local_u8PosY);
			CLCD_voidWriteSpecialCharacter(customChar1,0,Local_u8PosX+0x40,Local_u8PosY);


		}
		else if (Local_u8StatePin == 'R')
		{
			CLCD_voidWriteSpecialCharacter(customChar2,1,Local_u8PosX+0x40,Local_u8PosY);

			Local_u8PosX++;
			if ((Local_u8PosX == 2) || (Local_u8PosX == 5) )
			{
				CLCD_voidSendCommand(0b00010100);
				Local_u8PosX++;
			}
			if (Local_u8PosX ==8 )
			{
				Local_u8PosX =0 ;
				CLCD_voidGotoXY(0,Local_u8PosY);

			}
			CLCD_voidWriteSpecialCharacter(customChar1,0,Local_u8PosX+0x40,Local_u8PosY);



		}
		else if (Local_u8StatePin == 'L')
		{
			CLCD_voidWriteSpecialCharacter(customChar2,1,Local_u8PosX+0x40,Local_u8PosY);
			CLCD_voidSendCommand(0b00010000);
			Local_u8PosX--;
			if ((Local_u8PosX == 2) || (Local_u8PosX == 5) )
			{
				CLCD_voidSendCommand(0b00010000);
				Local_u8PosX--;
			}

			if (Local_u8PosX ==-1 )
			{
				Local_u8PosX =7 ;
				CLCD_voidGotoXY(Local_u8PosX,Local_u8PosY);

			}
			CLCD_voidWriteSpecialCharacter(customChar1,0,Local_u8PosX+0x40,Local_u8PosY);
		}
		else if (Local_u8StatePin == 'S')
		{
			CLCD_voidWriteSpecialCharacter(customChar2,1,Local_u8PosX+0x40,Local_u8PosY);
			while (Local_u8ValueSecond != 0)
			{
				Local_u8ValueSecond--;
				CLCD_voidGotoXY(7,Local_u8PosY);
				CLCD_voidSendData('0'+(Local_u8ValueSecond%10));
				CLCD_voidGotoXY(6,Local_u8PosY);
				CLCD_voidSendData('0'+(Local_u8ValueSecond/10));
				_delay_ms(1000);
			}
			while (Local_u8ValueMinute != 0)
			{
				Local_u8ValueMinute--;
				CLCD_voidGotoXY(4,Local_u8PosY);
				CLCD_voidSendData('0'+(Local_u8ValueMinute%10));
				CLCD_voidGotoXY(3,Local_u8PosY);
				CLCD_voidSendData('0'+(Local_u8ValueMinute/10));
				Local_u8ValueSecond =60;
				while (Local_u8ValueSecond != 0)
				{
					Local_u8ValueSecond--;
					CLCD_voidGotoXY(7,Local_u8PosY);
					CLCD_voidSendData('0'+(Local_u8ValueSecond%10));
					CLCD_voidGotoXY(6,Local_u8PosY);
					CLCD_voidSendData('0'+(Local_u8ValueSecond/10));
					_delay_ms(1000);
				}
			}
			while (Local_u8ValueHour != 0)
			{
				Local_u8ValueSecond--;
				CLCD_voidGotoXY(1,Local_u8PosY);
				CLCD_voidSendData('0'+(Local_u8ValueHour%10));
				CLCD_voidGotoXY(0,Local_u8PosY);
				CLCD_voidSendData('0'+(Local_u8ValueHour/10));
				Local_u8ValueMinute =60;
				while (Local_u8ValueMinute != 0)
				{
					Local_u8ValueSecond--;
					CLCD_voidGotoXY(4,Local_u8PosY);
					CLCD_voidSendData('0'+(Local_u8ValueMinute%10));
					CLCD_voidGotoXY(3,Local_u8PosY);
					CLCD_voidSendData('0'+(Local_u8ValueMinute/10));
					Local_u8ValueSecond =60;
					while (Local_u8ValueSecond != 0)
					{
						Local_u8ValueSecond--;
						CLCD_voidGotoXY(7,Local_u8PosY);
						CLCD_voidSendData('0'+(Local_u8ValueSecond%10));
						CLCD_voidGotoXY(6,Local_u8PosY);
						CLCD_voidSendData('0'+(Local_u8ValueSecond/10));
						_delay_ms(1000);
					}
				}

			}
			CLCD_voidWriteSpecialCharacter(Hamoksha,2,14,0);
			CLCD_voidGotoXY(Local_u8PosX,Local_u8PosY);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);

		}
		Local_u8StatePin = KPD_u8PressKey();
				while (Local_u8StatePin==0xff)
				{
					Local_u8StatePin =KPD_u8PressKey();
				}
			CLCD_voidWriteSpecialCharacter(customChar2,1,14,0);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_LOW);
			CLCD_voidGotoXY(Local_u8PosX,Local_u8PosY);


	}
Local_u8LoopCounter=1;
}
