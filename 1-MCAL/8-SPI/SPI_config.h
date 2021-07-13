/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):SPI *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*Select the data order , Options : 1-  DORD_LSB
 * 									2- 	DORD_MSB			*/
#define SPI_DORD					DORD_MSB

/*Select the clock polarity , Options : 1-CPOL_LOW
 * 										2-CPOL_HIGH		    */
#define SPI_CPOL						CPOL_LOW

/*Select the clock polarity , Options : 1-CPHA_SAMPLE
 * 										2-CPHA_SETUP		*/
#define SPI_CPHA						CPHA_SAMPLE

/*Select the speed of Clock , OPtions :	1-SPI_PRE_DIV_4
 * 										2-SPI_PRE_DIV_16
 * 										3-SPI_PRE_DIV_64
 * 										4-SPI_PRE_DIV_128
 * 										5-SPI_PRE_DIV_2
 * 										6-SPI_PRE_DIV_8
 * 										7-SPI_PRE_DIV_32
 * 										8-SPI_PRE_DIV_64    */
#define SPI_PRE							SPI_PRE_DIV_16


#endif
