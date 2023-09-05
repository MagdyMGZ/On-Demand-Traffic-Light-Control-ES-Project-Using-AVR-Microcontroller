/*
 * dio.h
 *
 * Created: 9/12/2022 8:49:03 PM
 *  Author: Magdy
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"

/************************************************************************/
/*                    DIO DRIVER MACROS                                 */
/************************************************************************/

// PORT Macros
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

// PORT Direction Macros
#define PORT_INPUT  0x00
#define PORT_OUTPUT 0xFF

// PIN Macros
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

// PIN Direction Macros
#define INPUT  0
#define OUTPUT 1

// Values Macros
#define LOW  0
#define HIGH 1

/************************************************************************/
/*                 DIO DRIVER FUNCTIONS PROTOTYPES                      */
/************************************************************************/

// Digital Input / Output PIN Direction Initialization
void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);

// Digital Input / Output Write a Value On PIN 
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);

// Digital Input / Output READ PIN Value
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);

// Digital Input / Output Toggle PIN Value
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber);

// Digital Input / Output PORT Direction Initialization
void DIO_port_init(uint8_t portNumber, uint8_t direction);

// Digital Input / Output Write a Value On PORT 
void DIO_port_write(uint8_t portNumber, uint8_t value);

#endif /* DIO_H_ */