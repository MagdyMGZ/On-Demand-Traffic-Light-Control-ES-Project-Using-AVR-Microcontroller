/*
 * led.h
 *
 * Created: 9/12/2022 8:43:55 PM
 *  Author: Magdy
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"

/************************************************************************/
/*               LED DRIVER FUNCTIONS PROTOTYPES                        */
/************************************************************************/

// Initialize The LED PIN
void LED_init(uint8_t ledPin, uint8_t ledPort);

// Turn ON The LED PIN
void LED_on(uint8_t ledPin, uint8_t ledPort);

// Turn OFF The LED PIN
void LED_off(uint8_t ledPin, uint8_t ledPort);

// Toggle The LED PIN
void LED_toggle(uint8_t ledPin, uint8_t ledPort);

#endif /* LED_H_ */