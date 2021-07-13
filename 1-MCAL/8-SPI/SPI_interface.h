/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL    ***********************/
/***********************   SWC (DRIVER):SPI *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

typedef struct
{
	u8 * SendData;
	u8 * RecieveData;
	u8 BufferSize ;
	void(*Notification)(void);


}SPI_t;
/*state of interrupt , options : 0 --> enable
 * 								 1 --> Disable            */
#define SPIE_ENABLE				1
#define SPIE_DISABLE			0

/*state of SPI , options : 0 --> enable
 * 						   1- --> Disable                */
#define SPI_ENABLE				1
#define SPI_DISABLE			    0

/*the types of the mc control , Options : 0 --> master
 * 										  1 --> Slave*/
#define SPI_MASTER				0
#define SPI_SLAVE 				1




/*select the mc types :1- Master : SPI_MASTER
 * 					   2- slave :SPI_SLAVE*/
u8 SPI_voidInit (u8 Copy_u8TypeMC);

u8 SPI_u8Transcieve (u8 Copy_u8SendData , u8 * Copy_u8RecieveData );

u8 SPI_u8TranscieveBufferSyn (u8 * Copy_u8SendData, u8 * Copy_u8Recieve , u8 Copy_u8BufferSize);

u8 SPI_u8TranscieveBufferAsyn (SPI_t * Copy_SPI_tInfo);

/*Select the argument as Enable : SPIE_ENABLE
 * 						 Disable : SPIE_DISABLE						*/
u8 SPI_voidInterruptState (u8 Copy_u8StateType);

/*Select the argument as Enable : SPI_ENABLE
 * 						 Disable : SPI_DISABLE						*/
u8 SPI_voidState (u8 Copy_u8StateType);





#endif
