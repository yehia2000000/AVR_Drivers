/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):DIO *********************/
/***********************   DATA : 24-8-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

/*preprocessor file guard */

#ifndef DIO_INTERFACE_H_ 
#define DIO_INTERFACE_H_

#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3

#define DIO_u8PIN0 0
#define DIO_u8PIN1 1
#define DIO_u8PIN2 2
#define DIO_u8PIN3 3
#define DIO_u8PIN4 4
#define DIO_u8PIN5 5
#define DIO_u8PIN6 6
#define DIO_u8PIN7 7


#define DIO_u8PIN_HIGH 		1
#define DIO_u8PIN_LOW		0

#define DIO_u8PORT_HIGH    0Xff
#define DIO_u8PORT_LOW     0


/*prototypes of function */

u8 DIO_u8TogglePinValue (u8 Copy_u8Port, u8 Copy_u8Pin);

u8 DIO_u8SetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Value);
/*this function return error status and it needs to three argument (port , direction) */

u8 DIO_u8SetPortValue (u8 Copy_u8Port,u8 Copy_u8Value);
/*this function return error status and return the value of bin 
 and it needs to three argument (port ,pin _direction) */

u8 DIO_u8GetPinValue (u8 Copy_u8Port , u8 Copy_u8Pin , u8*Copy_pu8Value);

#endif 
