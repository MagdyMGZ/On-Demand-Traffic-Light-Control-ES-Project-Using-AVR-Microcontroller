/*
 * app.h
 *
 * Created: 9/12/2022 8:38:33 PM
 *  Author: Magdy
 */ 

// File Guard
#ifndef APP_H_
#define APP_H_

/************************************************************************/
/*                 APPLICATION MACROS                                   */
/************************************************************************/

// PORT Macros
#define CAR_PORT      PORT_A
#define PED_PORT      PORT_B
#define BUTTON_PORT   PORT_D

// Car Signal State Macros
#define CAR_GREEN     0
#define CAR_YELLOW_1  1
#define CAR_RED       2
#define CAR_YELLOW_2  3

// PIN Macros
#define CAR_GREEN_PIN     PIN_0
#define CAR_YELLOW_PIN    PIN_1
#define CAR_RED_PIN       PIN_2

#define BUTTON_PIN        PIN_2

#define PED_GREEN_PIN     PIN_0
#define PED_YELLOW_PIN    PIN_1
#define PED_RED_PIN       PIN_2

// Timer Macros
#define TIMER0_START      247
#define TIMER0_OVERFLOWS  62

#define TIMER2_START      47
#define TIMER2_OVERFLOWS  30

// Button Macros
#define PRESS    1
#define RELEASE  2 

/************************************************************************/
/*                    FUNCTIONS PROTOTYPES                              */
/************************************************************************/

// Application Initialization
void app_init(void);

// Start The Application
void app_start(void);

#endif /* APP_H_ */