/*
 * interrupts.h
 *
 * Created: 9/13/2022 2:02:17 AM
 *  Author: Magdy
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <avr/io.h>
#include <avr/interrupt.h>

/*

#define ISC00 0
#define ISC01 1
#define INT0 6
#define INT1 7
#define INT2 5

// Interrupt Vectors

// External Interrupt Request 0
#define INT0_vect _VECTOR(1)
#define INT0_vect_num 1

// External Interrupt Request 1
#define INT1_vect _VECTOR(2)
#define INT1_vect_num 2

// External Interrupt Request 2
#define INT2_vect _VECTOR(3)
#define INT2_vect_num 3

// TIMER / COUNTER 2 Compare Match
#define TIMER2_COMP_vect _VECTOR(4)
#define TIMER2_COMP_vect_num 4

// TIMER / COUNTER 2 OverFlow
#define TIMER2_OVF_vect _VECTOR(5)
#define TIMER2_OVF_vect_num 5

// External Interrupt Request 0
#define EXT_INT_0 __vector_1

// External Interrupt Request 1
#define EXT_INT_1 __vector_2

// External Interrupt Request 2
#define EXT_INT_2 __vector_3

// Set Global Interrupts, Set the I_bit in Status Register to 1
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

// CLEAR Global Interrupts, Set the I_bit in Status Register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

// ISR Definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

*/


#endif /* INTERRUPTS_H_ */