/*
 * bit_manipulation.h
 *
 * Created: 9/13/2022 11:21:14 AM
 *  Author: Magdy
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

// Set Bit Macro
#define SET_BIT(x,BIT_NO) (x |= (1 << BIT_NO))

// Clear Bit Macro 
#define CLEAR_BIT(x,BIT_NO) (x &= ~(1 << BIT_NO))

// Read Bit Macro
#define GET_BIT(x,BIT_NO) ((x & (1 << BIT_NO)) >> BIT_NO)

// Toggle Bit Macro
#define TOGGLE_BIT(x,BIT_NO) (x ^= (1 << BIT_NO))

#endif /* BIT_MANIPULATION_H_ */