/*
 * timer.c
 *
 * Created: 9/12/2022 8:49:34 PM
 *  Author: Magdy
 */ 

#include "timer.h"
#include "../../Utilities/bit_manipulation.h"

/************************************************************************/
/*           TIMER0 DRIVER FUNCTIONS DEFINITIONS                        */
/************************************************************************/

// Initialize TIMER0
void TIMER0_init(uint8_t timerMode)
{
	// Check That The INPUT IS Valid
	if (timerMode <= FAST_PWM)
	{
		switch (timerMode)
		{
			case NORMAL:
			TCCR0 = 0x00;
			break;
			
			case PHASE_CORRECT:
			TCCR0 = 0x40;
			break;
			
			case CTC:
			TCCR0 = 0x08;
			break;
			
			case FAST_PWM:
			TCCR0 = 0x48;
			break;
		}
	}
	else
	{
		// ERROR Handling
	}
}

// Start TIMER0
void TIMER0_start(uint8_t timerPrescaler, uint8_t Initial_Value)
{
	// Initialize TIMER0 With The Initial Value
	TCNT0 = Initial_Value;
	
	// Check That The INPUT IS Valid
	if (timerPrescaler <= PRESCALER_1024)
	{
		switch (timerPrescaler)
		{
			case NO_PRESCALER:
			SET_BIT(TCCR0, CS00);
			CLEAR_BIT(TCCR0, CS01);
			CLEAR_BIT(TCCR0, CS02);
			break;
						
		    case PRESCALER_8:
			CLEAR_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			CLEAR_BIT(TCCR0, CS02);
			break;
			
			case PRESCALER_64:
			SET_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			CLEAR_BIT(TCCR0, CS02);
			break;
			
			case PRESCALER_256:
			CLEAR_BIT(TCCR0, CS00);
			CLEAR_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
			
			case PRESCALER_1024:
			SET_BIT(TCCR0, CS00);
			CLEAR_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
		}
	}
	else
	{
		// ERROR Handling
	}
}

// Stop TIMER0
void TIMER0_stop(void)
{
	TCCR0 = 0x00;
}

// Delay TIMER0
void TIMER0_delay(uint8_t timerPrescaler, uint8_t initialValue, uint32_t numberOfOverFlows)
{
	// CLEAR The OverFlow Counter
	uint32_t overflowCounter = 0;
	
	// Start TIMER0
	TIMER0_start(timerPrescaler, initialValue);
	
	// Go to the Loop Till The Number of Overflows Are Reached
	while (overflowCounter < numberOfOverFlows)
	{
		// Time_Tick = timerPrescaler / Frequency_CPU;
		// Time_MaxDelay = Time_Tick * pow(2,n) (Sizeof(Bits));
		// numberOfOverflows = ceil( Time_Delay / Time_MaxDelay);
		// Frequency_CPU = 1000000 HZ
		// NO_PRESCALER -> 1 OverFlow -> 256 microSecond
		// PRESCALER_8  -> 1 OverFlow -> 2048 microSecond
		// PRESCALER_64 -> 1 OverFlow -> 16384 microSecond
		// PRESCALER_256 -> 1 OverFlow -> 655346 microSecond
		// PRESCALER_1024 -> 1 OverFlow -> 262144 microSecond
		// Work With PRESCALER_64
		// Frequency_CPU / PRESCALER_64 = 1000000 / 16384 = 61 + 1(Start) OverFlows Complete
		// 1000000 % 16384 = 576
		// 16384 - 576 = 15808 , 15808 / 64 = 247 (INITIAL_VALUE) (DONE)
		
		// SET The OverFlow Flag
		while (GET_BIT(TIFR, TOV0) == 0);
		
		// CLEAR OverFlow Flag
		CLEAR_BIT(TIFR, TOV0);
		
		// Increment overflowCounter 
		overflowCounter++;
	}
	// CLEAR overflowCounter
	overflowCounter = 0;
	
	TIMER0_stop();
}

// Initialize TIMER2
void TIMER2_init(uint8_t timerMode)
{
	// Check That The INPUT IS Valid
	if (timerMode <= FAST_PWM)
	{
		switch (timerMode)
		{
			case NORMAL:
			TCCR2 = 0x00;
			break;
			
			case PHASE_CORRECT:
			TCCR2 = 0x40;
			break;
			
			case CTC:
			TCCR2 = 0x08;
			break;
			
			case FAST_PWM:
			TCCR2 = 0x48;
			break;
		}
	}
	else
	{
		// ERROR Handling
	}
}

// Start TIMER2
void TIMER2_start(uint8_t timerPrescaler, uint8_t Initial_Value)
{
	// Initialize TIMER0 With The Initial Value
	TCNT2 = Initial_Value;
	
	// Check That The INPUT IS Valid
	if (timerPrescaler <= PRESCALER_1024)
	{
		switch (timerPrescaler)
		{
			case NO_PRESCALER:
			SET_BIT(TCCR2, CS20);
			CLEAR_BIT(TCCR2, CS21);
			CLEAR_BIT(TCCR2, CS22);
			break;
			
			case PRESCALER_8:
			CLEAR_BIT(TCCR2, CS20);
			SET_BIT(TCCR2, CS21);
			CLEAR_BIT(TCCR2, CS22);
			break;
			
			case PRESCALER_64:
			CLEAR_BIT(TCCR2, CS20);
			CLEAR_BIT(TCCR2, CS21);
			SET_BIT(TCCR2, CS22);
			break;
			
			case PRESCALER_256:
			CLEAR_BIT(TCCR2, CS20);
			SET_BIT(TCCR2, CS21);
			SET_BIT(TCCR2, CS22);
			break;
			
			case PRESCALER_1024:
			SET_BIT(TCCR2, CS20);
			SET_BIT(TCCR2, CS21);
			SET_BIT(TCCR2, CS22);
			break;
		}
	}
	else
	{
		// ERROR Handling
	}
}

// Stop TIMER2
void TIMER2_stop(void)
{
	TCCR2 = 0x00;
}

// Delay TIMER2
void TIMER2_delay(uint8_t timerPrescaler, uint8_t initialValue, uint32_t numberOfOverFlows)
{
	// CLEAR The OverFlow Counter
	uint32_t overflowCounter = 0;
	
	// Start TIMER0
	TIMER2_start(timerPrescaler, initialValue);
	
	// Go to the Loop Till The Number of Overflows Are Reached
	while (overflowCounter < numberOfOverFlows)
	{
		// After Calculations
		// INITIAL_VALUE = 47 (DONE)
		
		// SET The OverFlow Flag
		while (GET_BIT(TIFR, TOV2) == 0);
		
		// CLEAR OverFlow Flag
		CLEAR_BIT(TIFR, TOV2);
		
		// Increment overflowCounter
		overflowCounter++;
	}
	// CLEAR overflowCounter
	overflowCounter = 0;
	
	TIMER2_stop();
}