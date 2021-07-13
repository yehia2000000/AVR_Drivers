/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :HAL   ***********************/
/***********************   SWC (DRIVER):KPD *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_BUTTON_VALUES  {{1,2,3,0},{4,5,6,0},{7,8,9,0},{'E','D','C',0}}

#define KPD_PORT 	DIO_u8PORTB

#define COL_PIN0	DIO_u8PIN4
#define COL_PIN1	DIO_u8PIN5
#define COL_PIN2	DIO_u8PIN6
#define COL_PIN3	DIO_u8PIN7

#define ROW_PIN0	DIO_u8PIN0
#define ROW_PIN1	DIO_u8PIN1
#define ROW_PIN2	DIO_u8PIN2
#define ROW_PIN3	DIO_u8PIN3

#define NO_PRESSED_KEY	0xff

#endif
