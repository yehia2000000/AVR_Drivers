/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):ADC *********************/
/***********************   DATA : 20-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

/*preprocessor file guard */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
/*
 * Selectable of the REF_voltage ADC
 * options : 1- Connecting to External voltage
 * 			 2- Connecting to AVCC
 * 			 3-Connecting to 2.56 (internal voltage)
 * 			  */
#define AREF_EXT			1
#define AREF_AVCC			2
#define AREF_DEFAULT		3

/*The Configuration of the Value Register
 * */
#define STORE_8BIT 		1
#define STORE_10BIT		2

/*Configuration of The Prescaler*/
#define DIVISON_BY_2     			0
#define DIVISON_BY_4     			2
#define DIVISON_BY_8    			3
#define DIVISON_BY_16    			4
#define DIVISON_BY_32    			5
#define DIVISON_BY_64     			6
#define DIVISON_BY_128     			7

/*State of the ADC*/
#define ENABLE						1
#define DISABLE 					2

/*Clear The Channel Code*/
#define MUX_CLEAR			0b11100000

#define BUSY		0
#define IDLE		1


/*PortA AS The ADC*/

/*types of the conversion */
#define CHAIN_STATE1			0
#define CHAIN_STATE2			1
#define SINGLE_STATE			2


#endif

