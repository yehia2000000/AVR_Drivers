/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):SPI *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/*Options of data order : 1- LSB is first ->DORD_LSB
 * 						  2- MSB is first ->DORD_MSB			*/
#define DORD_LSB		1
#define DORD_MSB		2

/*Options of the Clock polarity*/
#define CPOL_LOW 			0
#define CPOL_HIGH			1
/*Options of the clock phase */
#define CPHA_SAMPLE			0
#define CPHA_SETUP			1

/*Select the Speed of the spi master */
#define SPI_PRE_DIV_4        1
#define SPI_PRE_DIV_16       2
#define SPI_PRE_DIV_64       3
#define SPI_PRE_DIV_128      4
#define SPI_PRE_DIV_2        5
#define SPI_PRE_DIV_8        6
#define SPI_PRE_DIV_32       7
#define SPI_PRE_DIV1_64       8

#define CLEAR_SPEED			0b11111100















#endif
