#ifndef CONVERSION_H
# define CONVERSION_H

# include "check.h"

// Converts a ascii number to decimal
unsigned int ascii_int_to_decimal(unsigned char c);

// ascii_to_binary, converts a ascii character to hexadecimal
unsigned char ascii_to_hex(unsigned char c);

// two_ascii_to_char, tranforms two ascii caracter to a char
unsigned char two_ascii_to_char(unsigned char c1, unsigned char c2);

#endif /* !CONVERSION_H */
