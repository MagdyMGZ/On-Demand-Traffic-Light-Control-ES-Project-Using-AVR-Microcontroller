/*
 * app.c
 *
 * Created: 9/12/2022 8:38:19 PM
 *  Author: Magdy
 */ 

#include "app.h"
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../MCAL/DIO Driver/dio.h"
#include "../Utilities/bit_manipulation.h"
#include "../Utilities/interrupts.h"
#include "../Utilities/types.h"
#include "../Utilities/registers.h"

// Counters
uint8_t seconds_Counter = 0;
uint32_t overflow_Counter = 0;
uint32_t overflow_Counter_2 = 0;

// Flags
uint8_t Car_State = 0;
uint8_t Yellow_Flag = 0;
uint8_t Press_Button_Flag = 0;

// Application Initialization
void app_init()
{
	/************************************************************************/
	/*                    DIO INITIALIZATION                                */
	/************************************************************************/
	
	// Set OUTPUT LEDs Direction For CAR
	DIO_init(CAR_GREEN_PIN, CAR_PORT, OUTPUT);
	DIO_init(CAR_YELLOW_PIN, CAR_PORT, OUTPUT);
	DIO_init(CAR_RED_PIN, CAR_PORT, OUTPUT);
	
	// Set OUTPUT LEDs Direction For PEDESTRIAN
	DIO_init(PED_GREEN_PIN, PED_PORT, OUTPUT);
	DIO_init(PED_YELLOW_PIN, PED_PORT, OUTPUT);
	DIO_init(PED_RED_PIN, PED_PORT, OUTPUT);
	
	// Set INPUT Button Direction
	BUTTON_init(BUTTON_PIN, BUTTON_PORT);
	
	/************************************************************************/
	/*                   INTERRUPTS INITIALIZATION                          */
	/************************************************************************/
	
	// Initialize Global Interrupts
	SET_BIT(SREG, 7);
	//sei();
	
	// INT0 For Any Logical Change To Differ Between (Short & Long) Press generates an Interrupt Request
	SET_BIT(MCUCR, ISC00);
	CLEAR_BIT(MCUCR, ISC01);
	
	// Initialize INT0
	SET_BIT(GICR, INT0);
	
	// Initialize Overflow Interrupts For TIMER0 & TIMER2
	SET_BIT(TIMSK, TOIE0);
	SET_BIT(TIMSK, TOIE2);
	
	// Initialize TIMER0 
	TIMER0_init(NORMAL);
	
	// Initialize TIMER2
	TIMER2_init(NORMAL);
	
	// Start TIMER0
    TIMER0_start(PRESCALER_64, TIMER0_START);
}

// Start Application
void app_start()
{
	while(1)
	{
		// GREEN then YELLOW then RED then YELLOW then GREEN 
		if (Car_State > CAR_YELLOW_2)
		{
			Car_State = CAR_GREEN;
		}
		else
		{
			switch(Car_State)
			{
				case CAR_GREEN:
				
				// Turn ON CAR GREEN LED and 
				LED_on(CAR_GREEN_PIN, CAR_PORT);
				LED_off(CAR_YELLOW_PIN, CAR_PORT);
				LED_off(CAR_RED_PIN, CAR_PORT); 
				
				// TURN ON PEDESTRIAN RED LED
				LED_off(PED_GREEN_PIN, PED_PORT);
				LED_off(PED_YELLOW_PIN, PED_PORT);
				LED_on(PED_RED_PIN, PED_PORT);
				
				Yellow_Flag = 0;
				break;
				
				case CAR_YELLOW_1:
				
				// Can Then Blink After Setting
				Yellow_Flag = 1;
				
				// For CAR
				LED_off(CAR_GREEN_PIN, CAR_PORT);
				LED_off(CAR_RED_PIN, CAR_PORT);
				
				// For PEDESTRIAN
				LED_off(PED_GREEN_PIN, PED_PORT);
				LED_off(PED_RED_PIN, PED_PORT);
				break;
				
				case CAR_RED:
				
				// Turn ON CAR RED LED and
				LED_off(CAR_GREEN_PIN, CAR_PORT);
				LED_off(CAR_YELLOW_PIN, CAR_PORT);
				LED_on(CAR_RED_PIN, CAR_PORT);
				
				// TURN ON PEDESTRIAN GREEN LED
				LED_on(PED_GREEN_PIN, PED_PORT);
				LED_off(PED_YELLOW_PIN, PED_PORT);
				LED_off(PED_RED_PIN, PED_PORT);
				
				// CLEAR Yellow Flag
				Yellow_Flag = 0;
				break;
				
				case CAR_YELLOW_2:
				
				// TO Blink
				Yellow_Flag = 1;
				
				// For CAR
				LED_off(CAR_GREEN_PIN, CAR_PORT);
				LED_off(CAR_RED_PIN, CAR_PORT);
				
				// For PEDESTRIAN
				LED_off(PED_GREEN_PIN, PED_PORT);
				LED_off(PED_RED_PIN, PED_PORT);
				break;
				
				default:
				break;
			}
		}
	}
}

// Timer0 Overflow ISR
ISR(TIMER0_OVF_vect)
{
	// Check That If The Number of Overflows Counter Reached The Number of Overflows
	if (overflow_Counter < TIMER0_OVERFLOWS)
	{
		overflow_Counter++;
	}
	else if (overflow_Counter >= TIMER0_OVERFLOWS)
	{
		seconds_Counter++;
		
		if (Yellow_Flag == 1)
		{
			// Toggle Both Yellow LEDs
			LED_toggle(CAR_YELLOW_PIN, CAR_PORT);
			LED_toggle(PED_YELLOW_PIN, PED_PORT);
		}
		
		if (seconds_Counter == 5)
		{
			// Check That If The Seconds Counter = 5 Seconds Go to the Next Signal State
			Car_State++;
			// CLEAR The Seconds Counter
			seconds_Counter = 0;
		}
		
		// CLEAR The Overflow Counter
		overflow_Counter = 0;
	}
}

// Timer2 Overflow ISR
ISR(TIMER2_OVF_vect)
{
	// Increment The Overflow Counter
	overflow_Counter_2++;
}

// External INT0 ISR

ISR(__vector_1)
{
	// Increment The Press Button Flag
	Press_Button_Flag++;
	// Interrupt Occur When there is a
	// Logical Changes in Counting like :
	// Rising Edge When Pressed & Falling Edge When Released
	
	switch (Press_Button_Flag)
	{
		case PRESS:
		
		// Start TIMER2 When Rising Edge
		// TIMER2_START = 47
		TIMER2_start(PRESCALER_64, 47);
		break;
		
		case RELEASE:
		
		// Check That The Overflow Counter > 0.5 Second or Not
		if (overflow_Counter_2 > TIMER2_OVERFLOWS)
		{
			// Long Press Occur (Time Of Press > 0.5 Second)
		}
		else
		{
			// Short Press Occur (Time Of Press < 0.5 Second)
			if (Car_State == CAR_GREEN)
			{
				// IF Signal Is GREEN Go to YELLOW
				Car_State++;
				// CLEAR Seconds Counter
				seconds_Counter = 0;
				// CLEAR Overflow Counter
				overflow_Counter = 0;
			}
			else
			{
				// The CAR Signal Is YELLOW OR RED
			}
		}
		
		// STOP TIMER2
		TIMER2_stop();
		
		// CLEAR The Overflow Counter
		overflow_Counter_2 = 0;
		// CLEAR The Press Button Flag
		Press_Button_Flag = 0;
		break;
	}
} 