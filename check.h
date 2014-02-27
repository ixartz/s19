#ifndef CHECK_H
# define CHECK_H

# define END_OF_FILE 0xFF

/**
**@define Check whether the caractere is a 'S'.
*/
char is_s_char(unsigned char c);

/**
**@define Check whether the caractere is a number.
*/
char is_int(unsigned char c);

/**
**@define Check whether the character is an end of line.
*/
char is_end_of_line(unsigned char c);

/**
**@define Check whether it is the last line.
*/
char is_last_line(unsigned int line_code);

#endif /* !CHECK_H */
