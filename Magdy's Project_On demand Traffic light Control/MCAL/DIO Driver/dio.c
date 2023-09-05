/*
 * dio.c
 *
 * Created: 9/12/2022 8:48:53 PM
 *  Author: Magdy
 */ 

#include "dio.h"
#include "../../Utilities/bit_manipulation.h"

/************************************************************************/
/*              DIO DRIVER FUNCTIONS DEFINITIONS                        */
/************************************************************************/

// Digital Input / Output PIN Direction Initialization
void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	// Check The Inputs Validity (PORTS & PINS)
	if ((portNumber <= PORT_D) && (pinNumber <= PIN_7))
	{
		if (direction == OUTPUT)
		{
			switch (portNumber)
			{
				case PORT_A:
				SET_BIT(DDRA, pinNumber);
				break;
				
				case PORT_B:
				SET_BIT(DDRB, pinNumber);
				break;
				
				case PORT_C:
				SET_BIT(DDRC, pinNumber);
				break;
				
				case PORT_D:
				SET_BIT(DDRD, pinNumber);
				break;
			}
		}
		else if (direction == INPUT)
		{
			switch (portNumber)
			{
				case PORT_A:
				CLEAR_BIT(DDRA, pinNumber);
				break;
				
				case PORT_B:
				CLEAR_BIT(DDRB, pinNumber);
				break;
				
				case PORT_C:
				CLEAR_BIT(DDRC, pinNumber);
				break;
				
				case PORT_D:
				CLEAR_BIT(DDRD, pinNumber);
				break;
			}
		}
		else
		{
			// ERROR Handling
		}
	}
}

// Digital Input / Output Write a Value On PIN
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	// Check The Inputs Validity (PORTS & PINS)
	if ((portNumber <= PORT_D) && (pinNumber <= PIN_7))
	{
		if (value == HIGH)
		{
			switch (portNumber)
			{
				case PORT_A:
				SET_BIT(PORTA, pinNumber);
				break;
				
				case PORT_B:
				SET_BIT(PORTB, pinNumber);
				break;
				
				case PORT_C:
				SET_BIT(PORTC, pinNumber);
				break;
				
				case PORT_D:
				SET_BIT(PORTD, pinNumber);
				break;
			}
		}
		else if (value == LOW)
		{
			switch (portNumber)
			{
				case PORT_A:
				CLEAR_BIT(PORTA, pinNumber);
				break;
				
				case PORT_B:
				CLEAR_BIT(PORTB, pinNumber);
				break;
				
				case PORT_C:
				CLEAR_BIT(PORTC, pinNumber);
				break;
				
				case PORT_D:
				CLEAR_BIT(PORTD, pinNumber);
				break;
			}
		}
		else
		{
			// ERROR Handling
		}
	}
}

// Digital Input / Output READ PIN Value
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	// Check The Inputs Validity (PORTS & PINS)
	if ((portNumber <= PORT_D) && (pinNumber <= PIN_7))
	{
		switch (portNumber)
		{
			case PORT_A:
			*value = GET_BIT(PINA, pinNumber);
			break;
			
			case PORT_B:
			*value = GET_BIT(PINB, pinNumber);
			break;
			
			case PORT_C:
			*value = GET_BIT(PINC, pinNumber);
			break;
			
			case PORT_D:
			*value = GET_BIT(PIND, pinNumber);
			break;
		}
	}
	else
	{
		// ERROR Handling
	}
}

// Digital Input / Output Toggle PIN Value
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	// Check The Inputs Validity (PORTS & PINS)
	if ((portNumber <= PORT_D) && (pinNumber <= PIN_7))
	{
		switch (portNumber)
		{
			case PORT_A:
			TOGGLE_BIT(PORTA, pinNumber);
			break;
			
			case PORT_B:
			TOGGLE_BIT(PORTB, pinNumber);
			break;
			
			case PORT_C:
			TOGGLE_BIT(PORTC, pinNumber);
			break;
			
			case PORT_D:
			TOGGLE_BIT(PORTD, pinNumber);
			break;
		}
	}
	else
	{
		// ERROR Handling
	}
}

// Digital Input / Output PORT Direction Initialization
void DIO_port_init(uint8_t portNumber, uint8_t direction)
{
	// Check The Inputs Validity (PORTS)
	if (portNumber <= PORT_D)
	{
		switch (portNumber)
		{
			case PORT_A:
			DDRA = direction;
			break;
			
			case PORT_B:
			DDRB = direction;
			break;
			
			case PORT_C:
			DDRC = direction;
			break;
			
			case PORT_D:
			DDRD = direction;
			break;
		}
	}
	else
	{
		// ERROR Handling
	}
}

// Digital Input / Output Write a Value On PORT
void DIO_port_write(uint8_t portNumber, uint8_t value)
{
	// Check The Inputs Validity (PORTS)
	if (portNumber <= PORT_D)
	{
		switch (portNumber)
		{
			case PORT_A:
			PORTA = value;
			break;
			
			case PORT_B:
			PORTB = value;
			break;
			
			case PORT_C:
			PORTC = value;
			break;
			
			case PORT_D:
			PORTD = value;
			break;
		}
	}
	else
	{
		// ERROR Handling
	}
}
