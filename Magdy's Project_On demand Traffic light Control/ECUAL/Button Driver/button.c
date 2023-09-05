/*
 * button.c
 *
 * Created: 9/12/2022 8:40:18 PM
 *  Author: Magdy
 */ 

#include "button.h"

/************************************************************************/
/*           BUTTON DRIVER FUNCTIONS DEFINITIONS                        */
/************************************************************************/

// Initialize Button PIN
void BUTTON_init(uint8_t buttonPin, uint8_t buttonPort)
{
	DIO_init(buttonPin, buttonPort, INPUT);
}

// READ Button PIN Value
void BUTTON_read(uint8_t buttonPin, uint8_t buttonPort, uint8_t *value)
{
	DIO_read(buttonPin, buttonPort, value);
}