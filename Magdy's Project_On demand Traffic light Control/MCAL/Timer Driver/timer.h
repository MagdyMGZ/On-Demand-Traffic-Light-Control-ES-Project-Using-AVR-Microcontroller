/*
 * timer.h
 *
 * Created: 9/12/2022 8:49:48 PM
 *  Author: Magdy
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"

/************************************************************************/
/*            TIMER DRIVER MACROS                                       */
/************************************************************************/

// Timer MODES Macros
#define NORMAL          0
#define PHASE_CORRECT   1
#define CTC             2
#define FAST_PWM        3

// Prescaler Macros
#define NO_PRESCALER    0
#define PRESCALER_8     1
#define PRESCALER_64    2
#define PRESCALER_256   3
#define PRESCALER_1024  4

// TIMSK
#define TOIE0  0
#define OCIE0  1
#define TOIE1  2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2  6
#define OCIE2  7

// TCCR0
#define CS00 0 
#define CS01 1 
#define CS02 2 

// TCCR2
#define CS20 0
#define CS21 1
#define CS22 2

// TIFR
#define TOV0 0
#define TOV2 6

/************************************************************************/
/*              TIMERs DRIVER FUNCTIONS PROTOTYPES                      */
/************************************************************************/

// Initialize TIMER0
void TIMER0_init(uint8_t timerMode);

// Start TIMER0
void TIMER0_start(uint8_t timerPrescaler, uint8_t Initial_Value);

// Stop TIMER0
void TIMER0_stop(void);

// Delay TIMER0
void TIMER0_delay(uint8_t timerPrescaler, uint8_t initialValue, uint32_t numberOfOverFlows);

// Initialize TIMER2
void TIMER2_init(uint8_t timerMode);

// Start TIMER2
void TIMER2_start(uint8_t timerPrescaler, uint8_t Initial_Value);

// Stop TIMER2
void TIMER2_stop(void);

// Delay TIMER2
void TIMER2_delay(uint8_t timerPrescaler, uint8_t initialValue, uint32_t numberOfOverFlows);

#endif /* TIMER_H_ */