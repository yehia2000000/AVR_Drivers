/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :HAL   ***********************/
/***********************   SWC (DRIVER):SSD *********************/
/***********************   DATA : 1-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

/* Preprocessor file guard  */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_



typedef struct
{
	u8 Struct_u8Types ; /*CHOOSE ANODE :1 CHOOSE CATHODE :0*/
	u8 Struct_u8LedsPort;
	u8 Struct_u8EnablePort;
	u8 Sruct_u8EnablePin;
	u8 Struct_u8Number ;
	u8 *Struct_u8NumberArr;

}SSD_t;

#define ANODE 		1
#define CATHODE 	0

#define HIGH		1
#define LOW 		0

#define OFF 		0

u8 SSD_voidSetNumber(SSD_t*Copy_u8Struct);



#endif 
