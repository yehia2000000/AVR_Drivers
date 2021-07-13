/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):USART *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/*the number of interrupt */
#define USART_UDE			0
#define USART_RXC			1

/*Usart initialize */
void USART_voidInit (void);
/*Send the data and return time out*/
u8 USART_u8SendData (u8 Copy_u8Data);
/*recieve the data in the pointer as using two return value  and improv the function as time out*/
u8 USART_u8RecieveData (u8 * Copy_u8Data);
/*send the string */

/*Select the state of the enable , Options : 1-RX_DISABLE_TX_DISABLE
 * 											 2-RX_ENABLE_TX_DISABLE
 * 											 3-RX_DISABLE_TX_ENABLE
 * 											 4-RX_ENABLE_TX_ENABLE
 * 											                        */
u8 USART_voidEnable (u8 Copy_u8StateTX_RX);

/*Select the Pariity Mode , Options :
 * 									1-PARITY_DIS
 * 									2-PARITY_REV
 * 									3-PARITY_EVEN
 * 									4-PARITY_ODD 		*/
u8 USART_u8ParityMode (u8 Copy_u8ParityMode);
/*Send the string */
u8 USART_u8SendStringSyn (const char * Copy_pu8String);

u8 USART_u8ReceiveBufferSyn (u8 * Copy_pu8Data ,  u8 Copy_u8BufferSize);
/*Send  the string by the interrupt */
u8 USART_u8SendStringAsyn ( char *Copy_charString , void (*Copy_voidNotification)(void));
/*receive the data by the interrupt */
u8 USART_u8RecieveAsyn (u8 * Copy_u8Data , u8 Copy_u8BufferSize , void (*Copy_voidNotifaction)(void) );

void USART_voidUDRInit (u8 Copy_u8InitValue);

u8 USART_voidReadUDR (void);









#endif
