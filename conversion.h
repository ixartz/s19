#ifndef CONVERSION_H
# define CONVERSION_H

# include "check.h"

// Converts a ascii number to decimal
unsigned int ascii_int_to_decimal(unsigned char c);

// Converts a ascii character to hexadecimal
unsigned char ascii_to_hex(unsigned char c);

// Tranforms two ascii caracter to a char
unsigned char two_ascii_to_char(unsigned char c1, unsigned char c2);

// Truncates to a number in the range of 0 to 255
unsigned int truncate_sum(unsigned int sum);

#endif /* !CONVERSION_H */
