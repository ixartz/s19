#ifndef CONVERSION_H
# define CONVERSION_H

# include "check.h"

/**
**@define Convert an ASCII number to decimal
*/
unsigned int ascii_int_to_decimal(unsigned char c);

/**
**@define Convert an ASCII character to hexadecimal
*/
unsigned char ascii_to_hex(unsigned char c);

/**
**@define Tranform two ASCII caracter to a char
*/
unsigned char two_ascii_to_char(unsigned char c1, unsigned char c2);

/**
**@define Truncate a number in the range of 0 to 255
*/
unsigned int truncate_sum(unsigned int sum);

#endif /* !CONVERSION_H */
