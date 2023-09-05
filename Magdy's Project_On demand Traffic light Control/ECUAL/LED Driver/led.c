/*
 * led.c
 *
 * Created: 9/12/2022 8:43:41 PM
 *  Author: Magdy
 */ 

#include "led.h"

/************************************************************************/
/*           LED DRIVER FUNCTIONS DEFINITIONS                           */
/************************************************************************/

// Initialize The LED PIN
void LED_init(uint8_t ledPin, uint8_t ledPort)
{
	DIO_init(ledPin, ledPort, OUTPUT);
}

// Turn ON The LED PIN
void LED_on(uint8_t ledPin, uint8_t ledPort)
{
	DIO_write(ledPin, ledPort, HIGH);
}

// Turn OFF The LED PIN
void LED_off(uint8_t ledPin, uint8_t ledPort)
{
	DIO_write(ledPin, ledPort, LOW);
}

// Toggle The LED PIN
void LED_toggle(uint8_t ledPin, uint8_t ledPort)
{
	DIO_toggle(ledPin, ledPort);
}
