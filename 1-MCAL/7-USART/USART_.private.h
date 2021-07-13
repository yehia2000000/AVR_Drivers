/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):USART *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/*States of the enable of the uart*/
#define RX_DISABLE_TX_DISABLE    0
#define RX_ENABLE_TX_DISABLE    1
#define RX_DISABLE_TX_ENABLE    2
#define RX_ENABLE_TX_ENABLE     3


/*Select the mode of the size data*/
#define SIZE_5BIT               1
#define SIZE_6BIT               2
#define SIZE_7BIT               3
#define SIZE_8BIT               4
#define SIZE_REV1               5
#define SIZE_REV2               6
#define SIZE_REV3               7
#define SIZE_9BIT               8


/*USART selected Mode */
#define ASY_MODE 				0
#define SYN_MODE				1

/*Select the parity Mode */
#define PARITY_DIS              0
#define PARITY_REV              1
#define PARITY_EVEN             2
#define PARITY_ODD              3

/*Select the stop bit mode */
#define STOP_1BIT				0
#define STOP_2BIT				1

/*Time out of the transmiter and reciever */
#define TIME_OUT_TRANS			1000000
#define TIME_OUT_REC			1000000

/*Flags of the state of transmation and reciever*/
#define ACTIVE 				1
#define BUSY				0




#endif
