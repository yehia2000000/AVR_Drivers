/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL   ***********************/
/***********************   SWC (DRIVER):TIMER *********************/
/***********************   DATA : 14-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
/*Clear Options*/
#define TIMER_CLEAR_PRE				0b11111000

/*Select the prescaler of the three timer  */
#define TIMER_NO_CLK                 0
#define TIMER_CLK                    1
#define TIMER_DIV8                   2
#define TIMER_DIV64                  3
#define TIMER_DIV256                 4
#define TIMER_DIV1024                5
#define TIMER_EXT_CLK_RISING         6
#define TIMER_EXT_CLK_FALLING        7
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*Select the mode of the timer0 */
#define TIMER0_NORMAL                 1
#define TIMER0_PWM                    2
#define TIMER0_CTC                    3
#define TIMER0_FAST_PWM               4
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*Select the mode of the timer1 */
#define TIMER1_NORMAL                      1
#define TIMER1_PWM_8BIT                    2
#define TIMER1_PWM_9BIT                    3
#define TIMER1_PWM_10BIT                   4
#define TIMER1_CTC0                         5
#define TIMER1_FAST_PWM_8BIT               6
#define TIMER1_FAST_PWM_9BIT               7
#define TIMER1_FAST_PWM_10BIT              8
#define TIMER1_PHASE_FREQ_CORRECT0         9
#define TIMER1_PHASE_FREQ_CORRECT1         10
#define TIMER1_PWM0                        11
#define TIMER1_PWM1                        12
#define TIMER1_CTC1                        13
#define TIMER1_FAST_PWM0                   14
#define TIMER1_FAST_PWM1                   15
/*-----------------------------------------------------------------------------------------------------------------------------*/

/*Select the mode of the timer2 */
#define TIMER2_NORMAL                 1
#define TIMER2_PWM                    2
#define TIMER2_CTC                    3
#define TIMER2_FAST_PWM               4

/*Clear the cmp match of Timer0/2*/

#define Timer02_CLEAR_OC0_OC2 								              0b11001111

/*select the output compare mode of timer 0/2 (Normal and ctc )*/

#define TIMER02_NORMAL_CTC_OCO_OC2_DIS                                   0b00000000
#define TIMER02_NORMAL_CTC_OCO_OC2_TOGGLE                                0b00010000
#define TIMER02_NORMAL_CTC_OCO_OC2_CLEAR                                 0b00100000
#define TIMER02_NORMAL_CTC_OCO_OC2_SET                                   0b00110000

/*select the output compare mode of timer 0/2 (fast  pwm  )*/
#define TIMER02_FAST_PWM_OCO_OC2_DIS                                     0b00000000
#define TIMER02_FAST_PWM_OCO_OC2_REV                                     0b00010000
#define TIMER02_FAST_PWM_OCO_OC2_CLEAR_CMP_SET_TOP                       0b00100000
#define TIMER02_FAST_PWM_OCO_OC2_SET_CMP_CLEAR_TOP                       0b00110000

/*select the output compare mode of timer 0/2 (pwm (phase correct) )*/

#define TIMER02_PWM_OCO_OC2_DIS	                                         0b00000000
#define TIMER02_PWM_OCO_OC2_REV                                          0b00010000
#define TIMER02_PWM_OCO_OC2_CLEAR_CMPUP_SET_CMPDOWN                      0b00100000
#define TIMER02_PWM_OCO_OC2_SET_CMPUP_CLEAR_CMPDOWN                      0b00110000

/*---------------------------------------------------------------------------*/

/*Select the output Compare Mode of timer1 (Normal / CTC) (channel a)*/
#define TIMER1_NORMAL_CTC_OC1A_DIS                                        0b00000000
#define TIMER1_NORMAL_CTC_OC1A_TOGGLE                                     0b01000000
#define TIMER1_NORMAL_CTC_OC1A_CLEAR                                      0b10000000
#define TIMER1_NORMAL_CTC_OC1A_SET                                        0b11000000

/*Select the output Compare Mode of timer1 (fast Pwm) (channel a)*/

#define TIMER1_FAST_PWM_OC1A_DIS                                          0b00000000
#define TIMER1_FAST_PWM_OC1A_TOGGlE_DIS                                   0b01000000 /*WGM =0xff*/
#define TIMER1_FAST_PWM_OC1A_CLEAR_CMP_SET_TOP                            0b10000000
#define TIMER1_FAST_PWM_OC1A_SET_CMP_CLEAR_TOP                            0b11000000


/*Select the output Compare Mode of timer1 (pwm) (channel a)*/

#define TIMER1_PWM_OC1A_DIS                                               0b00000000
#define TIMER1_PWM_OC1A_TOGGLE_DIS                                        0b01000000/*WGM =9 or 14*/
#define TIMER1_PWM_OC1A_OC1A_CLEAR_CMP_SET_TOP                            0b10000000
#define TIMER1_PWM_OC1A_OC1A_SET_CMP_CLEAR_TOP                            0b11000000

/*Select the output Compare Mode of timer1 (Normal / CTC) (channel b)*/
#define TIMER1_NORMAL_CTC_OC1B_DIS                                         0b00000000
#define TIMER1_NORMAL_CTC_OC1B_DIS1                                        0b00010000
#define TIMER1_NORMAL_CTC_OC1B_CLEAR                                       0b00100000
#define TIMER1_NORMAL_CTC_OC1B_SET                                         0b00110000

/*Select the output Compare Mode of timer1 (fast Pwm) (channel b)*/

#define TIMER1_FAST_PWM_OC1B_DIS                                           0b00000000
#define TIMER1_FAST_PWM_OC1B_DIS1                                           0b00010000
#define TIMER1_FAST_PWM_OC1B_CLEAR_CMP_SET_TOP                             0b00100000
#define TIMER1_FAST_PWM_OC1B_SET_CMP_CLEAR_TOP                             0b00110000

/*Select the output Compare Mode of timer1 (pwm) (channel b)*/

#define TIMER1_PWM_OC1B_DIS                                                0b00000000
#define TIMER1_PWM_OC1B_DIS1                                                0b00010000
#define TIMER1_PWM_OC1B_CLEAR_CMP_SET_TOP                                  0b00100000
#define TIMER1_PWM_OC1B_SET_CMP_CLEAR_TOP                                  0b00110000

/*CLEAR THE Output compare mode timer1 channel a*/
#define TIMER1_CLEAR_CHANNELA                                              0b00111111
/*CLEAR THE Output compare mode timer1 channel b*/
#define TIMER1_CLEAR_CHANNELB                                              0b11001111









#endif








