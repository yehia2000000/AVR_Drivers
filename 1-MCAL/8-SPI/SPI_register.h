/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):SPI *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPCR		*((volatile u8 *)0x2D) /*SPI control register*/
#define SPCR_SPIE    7                   /*spi interrupt enable*/
#define SPCR_SPE     6					/*spi enable ,spi peripheral has low power to detect this bin */
#define SPCR_DORD    5					/*data order if its 0 the lsb is transmitted first but 1 MSB transmitted first*/
#define SPCR_MSTR    4					/*master and slave select , by default its 1 but when ss is zero this bit is cleared*/
#define SPCR_CPOL    3 					/*clock polarity bit is the state of data when no commuication */
#define SPCR_CPHA    2					/*clock phase receive first otransmit firstr*/
#define SPCR_SPR1    1					/*this bit indicate the the prescaler*/
#define SPCR_SPR0    0					/*this bit indicate the prescaler */

#define SPSR        *((volatile u8 *)0x2E) /*spi STATE register*/
#define	SPSR_SPIF	7
#define SPSR_WCOL	6
#define	SPSR_SPI2X	0


#define SPDR		*((volatile u8 *)0x2F)  /*spi data register*/


#endif
