/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :HAL   ***********************/
/***********************   SWC (DRIVER):KPD *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/


#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"


u8 KPD_u8PressKey (void)
{
	u8 Local_u8ColsIndex , Local_u8RowsIndex, Local_u8Kpressedkey=NO_PRESSED_KEY,Local_u8PinState;

	u8 Local_u8KPDArr[ROW_NUMBER][COL_NUMBER] =KPD_BUTTON_VALUES;

	u8 Local_u8ColArr[COL_NUMBER]={COL_PIN0,COL_PIN1,COL_PIN2,COL_PIN3};

	u8 Local_u8RowArr[ROW_NUMBER]={ROW_PIN0,ROW_PIN1,ROW_PIN2,ROW_PIN3};
	for (Local_u8ColsIndex=0;Local_u8ColsIndex<COL_NUMBER;Local_u8ColsIndex++)
	{
		/*activate colum Arr*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColsIndex],DIO_u8PIN_LOW);
		for (Local_u8RowsIndex=0;Local_u8RowsIndex<COL_NUMBER;Local_u8RowsIndex++)
		{
			DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowsIndex],&Local_u8PinState);
			if (Local_u8PinState==DIO_u8PORT_LOW)
			{
				Local_u8Kpressedkey =Local_u8KPDArr[Local_u8RowsIndex][Local_u8ColsIndex];
				while (Local_u8PinState==DIO_u8PORT_LOW)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowsIndex],&Local_u8PinState);

				}
				return Local_u8Kpressedkey;
			}

		}
		DIO_u8SetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColsIndex],DIO_u8PIN_HIGH);
	}
	return Local_u8Kpressedkey;
}
