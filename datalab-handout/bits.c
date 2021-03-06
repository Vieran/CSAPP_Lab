/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	int and1 = x & (~y);
	int and2 = (~x) & y;
	int result = (~and1) & (~and2);
  return ~result;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	int min = 1 << 31;
  return min;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
	int max = 1 << 31;
	max = ~max;  // the maximim 2's complement
	int result = x ^ max;  // if x == max, then result = 0
  return !result;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	int base_odd = 0xAA;  // base_odd set all odd-numbered bits to 1
	int sec_odd = base_odd << 8;
	sec_odd = sec_odd | base_odd;
	int allOddBits = sec_odd << 16;
    allOddBits = allOddBits | sec_odd;
	int result = x & allOddBits;
	result = result ^ allOddBits;
  return !result;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {  // x need to meet: x < (1<<31)
	int result = ~x;  // not really understand this
	result = result + 1;
  return result;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	// 0x30=110000, 0x39=111001
	int x_ = x >> 3;
	int r1 = x_ ^ 0x6;  // x is between 110000~110111
	int r2 = x ^ 0x38;  // x is 111000
	int r3 = x ^ 0x39;  // x is 111001
	int result = (!r1) | (!r2) | (!r3);  // x should be either of above three
  return result;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int x_is_zero = !x;
	int r1 = ((!x_is_zero<<31)>>31) & y;  // in this way, r1=0 if x is zero, or r1=y
	int r2 = ((x_is_zero<<31)>>31) & z;  // in this way, r2=z if x is zero, or r2=0
	int result = r1 + r2;
  return result;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int sign_x = (x >> 31) & 1;
	int sign_y = (y >> 31) & 1;
	int flag1 = sign_x & !sign_y;  // x is negative and y is non-negative

	int diff = x ^ y;
	int flag2 = !diff;
	int shift_diff = diff >> 1;
	diff = shift_diff | diff;
	shift_diff = diff >> 2;
	diff = shift_diff | diff;
	shift_diff = diff >> 4;
	diff = shift_diff | diff;
	shift_diff = diff >> 8;
	diff = shift_diff | diff;
	shift_diff = diff >> 16;
	diff = shift_diff | diff;
	int not_diff = ~diff;
	not_diff = not_diff >> 1;
	diff = not_diff & diff;

	int flag3= !(diff & x) & !(sign_x ^ sign_y);
	return (flag1 | flag2 | flag3);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	// return 1 iff x==0
	// x and negative x are both the same iff x==0
	int r1 = x >> 31;
	int neg_x = ~x + 1;
	int r2 = neg_x >> 31;
	int result = (r1 | r2) + 1;
  return result;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	// positive num: find the first 1(left->right) in binary represent
	// neagtive num: find the first 0(left->fight) in binary represent
	// don't forget to add 1
	/*
	int sign = (x >> 31) & 1;
	int x1 = (((sign<<31)>>31) & ~x);  // x is negative, then x1 = ~x, otherwise x1 = 0
	int x2 = (((!sign<<31)>>31) & x);  // x is positive, then x2 = x, otherwise x2 = 0
	x = x1 + x2;
	*/
	int sign = x >> 31;
	x = (sign & ~x) | (~sign & x);  // sign ? x : ~x

	// xxxxx+1 is enough to represent 1~32
	// here split them all into 5 part, it's really a fantastic idea!
	int c4 = !!(x>>16) << 4;
	x = x >> c4;
	int c3 = !!(x>>8) << 3;
	x = x >> c3;
	int c2 = !!(x>>4) << 2;
	x = x >> c2;
	int c1 = !!(x>>2) << 1;
	x = x >> c1;
	int c0 = !!(x>>1);
	x = x >> c0;
  return (c4 + c3 + c2 + c1 + c0 + x + 1);
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
	unsigned exp = uf & 0x7f800000;  // 0111 1111 1??? ?...
	unsigned frac = uf & 0x7fffff;  // 0000 0000 0111 1...
	unsigned sign = uf & 0x80000000;  // 1000 0...

	if(exp == 0)  // infinity
		return uf << 1 | sign;
	if(exp == 0x7f800000)  // NAN
		return uf;
	exp = exp + 0x800000;  // exp plus 1
	if(exp == 0x7f800000)  // NAN
		return 0x7f800000 | sign;
	unsigned result = exp | frac | sign;

  return result;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
	int exp = (uf >> 23) & 0xff;
	exp = exp - 127;
	int sign = (uf & 0x80000000);
	if(exp > 31)
		return 0x80000000;
	if(exp < 0)
		return 0;

	int frac = (uf & 0x7fffff) | 0x800000;  // don't forget to add 1
	int result;
	if(exp > 23)
		result = frac << (exp - 23);
	else
		result = frac >> (23 - exp);
	if(!((result>>31)^sign))
		return result;
	else if(result>>31)  // origin is positive, now is negative, which means overflow
		return 0x80000000;
	else  // origin is negative, now is positive, which means need to change sign
		return ~result+1;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	if(x >= 128)  // too large, overflow
		return 0xff << 23;
	if(x <= -127)  // too small, overflow
		return 0;
	int exp = x + 127;
	int result = exp << 23;
    return result;
}
