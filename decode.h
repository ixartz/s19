#ifndef DECODE_H
# define DECODE_H

# include <stdlib.h>
# include <stdio.h>
# include "file.h"

# define SIZE_MEMORY 65536

// Calculates the number of byte allocated for the adress
unsigned int nb_Byte_per_adress(unsigned int line_code);

// Retrieve number of Byte for the data
unsigned int retrieve_nb_Byte(FILE* file, unsigned int* sum);

// Calculate adress. Where do we put data ?
unsigned int retrieve_adress(FILE* file, unsigned int* sum, unsigned int nb_Byte_adress);

void put_data_in_memory(FILE* file,
                        unsigned char* memory,
                        unsigned int* sum,
                        unsigned int nb_Byte,
                        unsigned int nb_Byte_adress,
                        unsigned int adress);

// verif_check_sum, check if the calculated check-sum corresponds the check-sum in the file
char calculate_checksum(unsigned int sum, FILE* file);

#endif /* !DECODE_H */
