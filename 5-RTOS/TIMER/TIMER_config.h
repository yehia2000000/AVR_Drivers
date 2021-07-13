/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :MCAL   ************************/
/***********************   SWC (DRIVER):TIMER *******************/
/***********************   DATA : 14-9-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*Select the prescaler of the timer 0-1-2
 * Options : 1-TIMER_NO_CLK
 * 			 2-TIMER_CLK
 * 			 3-TIMER_DIV8
 * 			 4-TIMER_DIV64
 * 			 5-TIMER_DIV256
 * 			 6-TIMER_DIV1024
 * 			 7-TIMER_EXT_CLK_RISING
 * 			 8-TIMER_EXT_CLK_FALLING								  */

#define TIMER0_PRE					TIMER_DIV8
#define TIMER1_PRE			        TIMER_DIV8
#define TIMER2_PRE                  TIMER_DIV8


/*Select the timer0 mode Options :1-TIMER0_NORMAL
 *                                2-TIMER0_PWM
 *                                3-TIMER0_CTC
 *                                4-TIMER0_FAST_PWM   */
#define TIMER0_MODE 				TIMER0_FAST_PWM


/*Select the timer1 mode Options :1 -TIMER1_NORMAL                   (TOP :0xFFFF)
 *                                2 -TIMER1_PWM_8BIT                 (TOP :0x00FF)
 *                                3 -TIMER1_PWM_9BIT                 (TOP :0x01FF)
 *                                4 -TIMER1_PWM_10BIT                (TOP :0x03FF)
 *                                5 -TIMER1_CTC                      (TOP :OCR1A )
 *                                6 -TIMER1_FAST_PWM_8BIT            (TOP :0x00FF)
 *                                7 -TIMER1_FAST_PWM_9BIT            (TOP :0x01FF)
 *                                8 -TIMER1_FAST_PWM_10BIT           (TOP :0x03FF)
 *                                9 -TIMER1_PHASE_FREQ_CORRECT0      (TOP  ICR1  )
 *                                10-TIMER1_PHASE_FREQ_CORRECT1      (TOP  OCR1A )
 *                                11-TIMER1_PWM0                     (TOP :ICR1  )
 *                                12-TIMER1_PWM1                     (TOP :OCR1A )
 *                                14-TIMER1_CTC                      (TOP :ICR1  )
 *                                15-TIMER1_FAST_PWM0                (TOP :ICR1  )
 *                                16-TIMER1_FAST_PWM1                (TOP :OCR1A )
 *                               						                                */
#define TIMER1_MODE 	          TIMER1_FAST_PWM0


/*Select the timer2 mode Options :1-TIMER2_NORMAL
 *                                2-TIMER2_PWM
 *                                3-TIMER2_CTC
 *                                4-TIMER2_FAST_PWM   */
#define TIMER2_MODE 				TIMER2_FAST_PWM

/*-------------------------------------------------------------timer0/2------------------------------------------------------------------*/
/*Clear the output cmp in timer 0*/




/*Select the ouput Compare  in timer 0 (Normal - CTC )
 * Options : 1- TIMER02_NORMAL_CTC_OCO_OC2_DIS
 * 			 2- TIMER02_NORMAL_CTC_OCO_OC2_TOGGLE
 * 			 3- TIMER02_NORMAL_CTC_OCO_OC2_CLEAR
 * 			 4- TIMER02_NORMAL_CTC_OCO_OC2_SET   								*/

#define TIMER0_NORMAL_CTC_OCO 					                     TIMER02_NORMAL_CTC_OCO_OC2_DIS
/*Select the ouput Compare  in timer 0 (fast pwm )
 * Options : 1-TIMER02_FAST_PWM_OCO_OC2_DIS
 * 			 2-TIMER02_FAST_PWM_OCO_OC2_REV
 * 			 3-TIMER02_FAST_PWM_OCO_OC2_CLEAR_CMP_SET_TOP
 * 			 4-TIMER02_FAST_PWM_OCO_OC2_SET_CMP_CLEAR_TOP 					*/

#define TIMER0_FAST_PWM_OCO 									     TIMER02_FAST_PWM_OCO_OC2_CLEAR_CMP_SET_TOP
/*Select the ouput Compare  in timer 0 (pwm)
 * Options : 1-TIMER02_PWM_OCO_OC2_DIS
 * 			 2-TIMER02_PWM_OCO_OC2_REV
 * 			 3-TIMER02_PWM_OCO_OC2_CLEAR_CMPUP_SET_CMPDOWN
 * 			 4-TIMER02_PWM_OCO_OC2_SET_CMPUP_CLEAR_CMPDOWN 							*/
#define TIMER0_PWM_OCO 											     TIMER02_PWM_OCO_OC2_DIS

/*----------------------------------------------------------------------------------------------------------------------------------*/


/*Select the ouput Compare  in timer 2 (Normal - CTC )
 * Options : 1- TIMER0/2_NORMAL_CTC_OCO_OC2_DIS
 * 			 2- TIMER0/2_NORMAL_CTC_OCO_OC2_TOGGLE
 * 			 3- TIMER0/2_NORMAL_CTC_OCO_OC2_CLEAR
 * 			 4- TIMER0/2_NORMAL_CTC_OCO_OC2_SET   							*/
#define TIMER2_NORMAL_CTC_OC2										TIMER02_NORMAL_CTC_OCO_OC2_DIS

/*Select the ouput Compare  in timer 2 (Fast pwm)
 * Options : 1- TIMER0/2_FAST_PWM_OCO_OC2_DIS
 * 			 2- TIMER0/2_FAST_PWM_OCO_OC2_REV
 * 			 3- TIMER0/2_FAST_PWM_OCO_OC2_CLEAR_CMP_SET_TOP
 * 			 4- TIMER0/2_FAST_PWM_OCO_OC2_SET_CMP_CLEAR_TOP 						*/
#define TIMER2_FAST_PWM_OC2 									    TIMER02_FAST_PWM_OCO_OC2_DIS


/*Select the ouput Compare  in timer 2 (pwm )
 * Options : 1- TIMER0/2_PWM_OCO_OC2_DIS
 * 			 2- TIMER0/2_PWM_OCO_OC2_REV
 * 			 3- TIMER0/2_PWM_OCO_OC2_CLEAR_CMPUP_SET_CMPDOWN
 * 			 4- TIMER0/2_PWM_OCO_OC2_SET_CMPUP_CLEAR_CMPDOWN 				*/

#define TIMER2_PWM_OC2 										TIMER02_PWM_OCO_OC2_DIS


/*-----------------------------------------------------------------------------------------------------------------------------------*/
/*Select output compare mode of timer1  (Normal_CTC) Channel (A)
 * Options :1-TIMER1_NORMAL_CTC_OC1A_DIS
 * 			2-TIMER1_NORMAL_CTC_OC1A_TOGGLE
 * 			3-TIMER1_NORMAL_CTC_OC1A_CLEAR
 * 			4-TIMER1_NORMAL_CTC_OC1A_SET                    */

#define TIMER1_NORMAL_CTC_MODE_CHANNELA						TIMER1_NORMAL_CTC_OC1A_DIS

/*Select output compare mode of timer1  (Fast pwm) Channel (a)
 * Options :1-TIMER1_FAST_PWM_OC1A_DIS
 * 			2-TIMER1_FAST_PWM_OC1A_TOGGlE_DIS
 * 			3-TIMER1_FAST_PWM_OC1A_CLEAR_CMP_SET_TOP
 * 			4-TIMER1_FAST_PWM_OC1A_SET_CMP_CLEAR_TOP       */

#define TIMER1_FAST_PWM_MODE_CHANNELA                        TIMER1_FAST_PWM_OC1A_CLEAR_CMP_SET_TOP

/*Select output compare mode of timer1  (pwm ) Channel (a)
 * Options :1-TIMER1_PWM_OC1A_DIS
 * 			2-TIMER1_PWM_OC1A_TOGGLE_DIS
 * 			3-TIMER1_PWM_OC1A_OC1A_CLEAR_CMP_SET_TOP
 * 			4-TIMER1_PWM_OC1A_OC1A_SET_CMP_CLEAR_TOP       */
#define TIMER1_PWM_MODE_CHANNELA                              TIMER1_PWM_OC1A_DIS

/*Select output compare mode of timer1   (Normal_CTC) Channel (b)
 * Options :1-TIMER1_NORMAL_CTC_OC1B_DIS
 * 			2-TIMER1_NORMAL_CTC_OC1B_DIS
 * 			3-TIMER1_NORMAL_CTC_OC1B_CLEAR
 * 			4-TIMER1_NORMAL_CTC_OC1B_SET                  */
#define TIMER1_NORMAL_CTC_MODE_CHANNELB                      TIMER1_NORMAL_CTC_OC1B_DIS

/*Select output compare mode of timer1  (Fast pwm) Channel (b)
 * Options :1-TIMER1_FAST_PWM_OC1B_DIS
 * 			2-TIMER1_FAST_PWM_OC1B_DIS
 * 			3-TIMER1_FAST_PWM_OC1B_CLEAR_CMP_SET_TOP
 * 			4-TIMER1_FAST_PWM_OC1B_SET_CMP_CLEAR_TOP      */

#define TIMER1_FAST_PWM_MODE_CHANNELB                        TIMER1_NORMAL_CTC_OC1B_DIS
/*Select output compare mode of timer1 (pwm ) Channel (b)
 * Options :1- TIMER1_PWM_OC1B_DIS
 * 			2- TIMER1_PWM_OC1B_DIS
 * 			3- TIMER1_PWM_OC1B_CLEAR_CMP_SET_TOP
 * 			4- TIMER1_PWM_OC1B_SET_CMP_CLEAR_TOP           */
#define TIMER1_PWM_MODE_CHANNELB							 TIMER1_NORMAL_CTC_OC1B_DIS















#endif
