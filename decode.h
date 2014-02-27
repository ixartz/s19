#ifndef DECODE_H
# define DECODE_H

# include <stdlib.h>
# include <stdio.h>
# include "file.h"

# define SIZE_MEMORY 65536

/**
**@define Calculate the number of byte allocated for the address.
*/
unsigned int nb_Byte_per_address(unsigned int line_code);

/**
**@define Calculate number of Byte for the data.
*/
unsigned int retrieve_nb_Byte(FILE* file, unsigned int* sum);

/**
**@define Calculate the address.
*/
unsigned int retrieve_address(FILE* file, unsigned int* sum, unsigned int nb_Byte_address);

/**
**@define Load data into memory.
*/
void put_data_in_memory(FILE* file,
                        unsigned char* memory,
                        unsigned int* sum,
                        unsigned int nb_Byte,
                        unsigned int nb_Byte_address,
                        unsigned int address);

/**
**@define Check whether the calculated check-sum
**corresponds to attempted check-sum.
*/
char calculate_checksum(unsigned int sum, FILE* file);

#endif /* !DECODE_H */
