/*
 * Bit_Math.h
 *
 *  Created on: Mar 20, 2020
 *      Author: super
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* A macro for setting a bit */
#define SET_BIT( REG, BIT_NO )           (REG) |= (1<<(BIT_NO))

/* A macro for clearing a bit */
#define CLEAR_BIT( REG, BIT_NO )         (REG) &= (~(1<<(BIT_NO)))

/* A macro for getting the bit value */
#define GET_BIT( REG, BIT_NO )           (((REG)>>(BIT_NO))&1)


#endif /* BIT_MATH_H_ */
