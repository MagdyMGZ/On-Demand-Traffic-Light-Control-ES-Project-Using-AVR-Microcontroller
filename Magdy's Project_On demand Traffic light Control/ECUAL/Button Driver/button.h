/*
 * button.h
 *
 * Created: 9/12/2022 8:40:32 PM
 *  Author: Magdy
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"

// State For BUTTON Macros
#define LOW   0
#define HIGH  1

/************************************************************************/
/*           BUTTON DRIVER FUNCTION PROTOTYPE                           */
/************************************************************************/

// Initialize Button PIN
void BUTTON_init(uint8_t buttonPin, uint8_t buttonPort);

// READ Button PIN Value
void BUTTON_read(uint8_t buttonPin, uint8_t buttonPort, uint8_t *value);

#endif /* BUTTON_H_ */