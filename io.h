#ifndef IO_H
# define IO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "conversion.h"

// displays a error when there is a error in the S19 data file
void print_error(unsigned int line);

// empty buffer of fgets. It read the buffer character by character thanks to getChar().
void clear_buffer();

// scanf_secure, read standard input with a limited length avoiding buffer overflow.
int scanf_secure(char* str, int length);

// read standard input and return a int
int read_int();

int read_hex();

#endif /* !IO_H */
