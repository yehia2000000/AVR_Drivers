/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :HAL    ***********************/
/***********************   SWC (DRIVER):DIO *********************/
/***********************   DATA : 25-8-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

//choose the ports

#define CLCD_DATA_PORT 		DIO_u8PORTD

#define CLCD_CTRL_PORT		DIO_u8PORTD
#define CLCD_RS_PIN			DIO_u8PIN3
#define CLCD_RW_PIN			DIO_u8PIN2
#define CLCD_E_PIN			DIO_u8PIN1

/*Selectable the mode of the Lcd
 * OptionS :
 * 			1- 8_BIT  MODE:MODE_8_BIT
 * 			2- 4_BIT MODE:MODE_4_BIT*/

#define CLCD_MODE		MODE_4_BIT
// function set





#endif
