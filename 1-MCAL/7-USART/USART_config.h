/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):USART *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#define USART_BAUD_RATE 			9600

/*Select the size of data ,Options :
 *									1- SIZE_5BIT
 *									2- SIZE_6BIT
 *									3- SIZE_7BIT
 *									4- SIZE_8BIT
 *									5- SIZE_REV1
 *									6- SIZE_REV2
 *									7- SIZE_REV3
 *									8- SIZE_9BIT   */
#define USART_SIZE_DATA				      SIZE_8BIT

/*Select the usart mode ,Options : 1-ASY_MODE
 * 								   2-SYN_MODE   */
#define USART_MODE					      ASY_MODE

/*Select the Pariity Mode , Options :
 * 									1-PARITY_DIS
 * 									2-PARITY_REV
 * 									3-PARITY_EVEN
 * 									4-PARITY_ODD 		*/
#define USART_PARITY_MODE 			      PARITY_DIS

/*Select the the stop bit Mode , Options :1-STOP_1BIT
 	 	 	 	 	 	 	 	 	 	  2-STOP_2BIT      */
#define USART_STOP_BIT_MODE			      STOP_1BIT










#endif
