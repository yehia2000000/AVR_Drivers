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
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_
/*
 * ADMUC -> "Analog to Digital Conversion MUlipliexier Control "*/
#define	ADMUX            		*((volatile u8 *) 0x27)
#define ADMUX_REFS1				7
#define ADMUX_REFS0				6
#define ADMUX_ADLAR				5
/*
 * ADCSRA -> "Analog to Digital Conversion Control Status Register A"*/
#define	ADCSRA                	*((volatile u8 *) 0x26)
#define ADCSRA_ADEN				7
#define ADCSRA_ADSC				6
#define ADCSRA_ADATE			5
#define ADCSRA_ADIF				4
#define ADCSRA_ADIE				3

/*
 * ADCH -> "Analog to Digital Conversion Upper"*/
#define ADCH                	*((volatile u8 *) 0x25)

#define ADCL					*((volatile u8 *) 0x24)

#define ADC						*((volatile u16 *)0x24)


#endif


