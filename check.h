#ifndef CHECK_H
# define CHECK_H

# define END_OF_FILE 0xFF

// Check if the caractere is a 'S'
char is_s_char(unsigned char c);

// Check if the caractere is a number
char is_int(unsigned char c);

// Check if the character is a end of line
char is_end_of_line(unsigned char c);

char is_last_line(unsigned int line_code);

#endif /* !CHECK_H */
