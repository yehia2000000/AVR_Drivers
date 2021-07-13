/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL   ***********************/
/***********************   SWC (DRIVER):TIMER *********************/
/***********************   DATA : 14-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/*Types of the timer */
#define TIMER0						0
#define TIMER1						1
#define TIMER2						2

/*Types of the channel */
#define CHANNELA                    0
#define CHANNELB                    1
#define NO_CHANNEL                  2

/*Types of trigger*/
#define RISING 			1
#define FALLING			0

/*Interrupt Pin*/
#define OCIE2        0
#define TOIE2        1
#define TICIE        2
#define OCIE1A       3
#define OCIE1B       4
#define TOIE1        5
#define OCIE0        6
#define TOIE0        7

/*Interrupt State */
#define ENABLE 		1
#define DISABLE		0



/*Number of the top of timer1 */
#define TIMER1_TOPVALUE												65536

/*Set the initial preload */
#define TIMER0_PRELOAD_INIT									0
#define TIMER1_PRELOAD_INIT									0
#define TIMER2_PRELOAD_INIT									0

/*Set the initial Compare Value x */
#define TIMER0_COMPARE_INIT									0
#define TIMER1_COMPARE_INIT									0
#define TIMER2_COMPARE_INIT									0


/*-------------------------------------------INITIALIZE TIMERs--------------------------------------------------------------*/
void Timer0_Init (void);
void Timer1_Init (void);
void Timer2_Init (void);

u8 Timer_Enable (u8 Copy_u8TypeTimer);
u8 Timer_u8PreLoad (u16 Copy_u8Value , u8 Copy_u8TypeTimer);
/*enter te channel when use the timer one only */
u8 Timer_u8SetCompValue ( u16 Copy_u8Value , u8 Copy_u8Typetimer , u8 Copy_u8Channel);
/*Set the Interrupt State*/
u8 Timer_u8InterruptState  (u8 Copy_InterruptState , u8 Copy_InterruptPin , u8 Copy_u8TypeTimer);

u8 Timer_u8CallBackFunc (void (*Copy_pvNotification)(void), u8 Copy_u8NumberInterrupt);

u8 Timer1_u8SetTrigger (u8 Copy_u8TypeTrigger) ;

void Timer1_SetOnTop (u16 Copy_u16TopValue);

u16 Timer1_u16ReadValue (void);
u8 Timer0_u8ReadValue (void);
u8 Timer2_ReadValue (void);

void ICU_Gen_Init (void);
u16 Timer1_u16IcuReadValue (void);

void WDT_voidEnable (void);
void WDT_voidDissable (void);
u8 WDT_u8Sleep (u8 Copy_u8SleepTime);



void Clear (void);

#endif

