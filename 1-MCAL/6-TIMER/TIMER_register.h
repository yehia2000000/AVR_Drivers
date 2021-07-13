/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL   ***********************/
/***********************   SWC (DRIVER):TIMER *********************/
/***********************   DATA : 14-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0 						*((volatile u8 *) 0x53)
#define TCCR0_FOC0                   7
#define TCCR0_WGM00                  6
#define TCCR0_WGM01                  3

#define TIMSK 						*((volatile u8 *) 0x59)
#define TIMSK_OCIE2                  7
#define TIMSK_TOIE2                  6
#define TIMSK_TICIE                  5
#define TIMSK_OCIE1A                 4
#define TIMSK_OCIE1B                 3
#define TIMSK_TOIE1                  2
#define TIMSK_OCIE0                  1
#define TIMSK_TOIE0                  0

#define TCNT0 						*((volatile u8 *) 0x52)

#define OCR0						*((volatile u8 *) 0x5C)

#define TCCR1A						*((volatile u8 *) 0x4F)
#define TCCR1A_WGM11				1
#define TCCR1A_WGM10				0
#define TCCR1A_FOC1A				3
#define TCCR1A_FOC1B				2

#define TCCR1B						*((volatile u8 *) 0x4E)
#define TCCR1B_WGM13				4
#define TCCR1B_WGM12				3
#define TCCR1B_ICNC1				7
#define TCCR1B_ICES1				6

#define TCNT1                       *((volatile u16 *) 0x4C)

#define OCR1A                       *((volatile u16 *) 0x4A)

#define OCR1B                       *((volatile u16 *) 0x48)

#define ICR1                        *((volatile u16 *) 0x46)

#define TCNT2						*((volatile u8 *) 0x44)

#define TCCR2 						*((volatile u8 *) 0x45)
#define TCCR2_FOC2                   7
#define TCCR2_WGM20                  6
#define TCCR2_WGM21                  3

#define OCR2		              	*((volatile u8 *) 0x43)

#define WDTCR						*((volatile u8 *)0x41)
#define WDTCR_WDTOE					4
#define WDTCR_WDE					3







#endif
