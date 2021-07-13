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

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_STATE		ENABLE

#define SELECT0          ADC_0
#define SELECT1          ADC_1
#define SELECT2          ADC_2
#define SELECT3          ADC_3
#define SELECT4          ADC_4
#define SELECT5          ADC_5
#define SELECT6          ADC_6
#define SELECT7          ADC_7

typedef struct
{
	u8 * channel ;
	u8 chain_size ;
	void (*Notification)(void);
	u16 * Result ;


}chain_t;


void ADC_voidInit (void);

u8 ADC_u8StartSingleConversionSyn (u8 Copy_u8Channnel , u16 * Copy_u16Result);

/*
 *PreCondition :Enable the interrupt Before Call the function  */
u8 ADC_u8StartSingleConversionAsyn (u8 Copy_u8Channel ,u16 *Copy_u16Result , void (*Copy_PvNotification)(void));


u8 ADC_u8ChainConversion1 (void(* Copy_PvNotification)(void),u16 Copy_Results[8]);

u8 ADC_u8ChainConversion2 (chain_t * Copy_Chain);






#endif
