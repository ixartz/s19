#include "file.h"

void clear_line(FILE* file)
{
  int c = 0;

  while (c != '\n' && c != END_OF_FILE)
  {
    c = fgetc(file);
  }
}

void decode_s19(FILE* file, unsigned char* memory)
{
  unsigned int nb_Byte, nb_Byte_address, line = 1, line_code, address = 0, sum = 0;
  unsigned char current_char = fgetc(file), error = 0, last_line = 0;

  do
  {
    /* Check if the firt character is a 'S' */
    if (!is_s_char(current_char))
      error = 1;

    /* Check if the 'S' is followed by a integer */
    current_char = fgetc(file);

    if (!is_int(current_char))
      error = 1;

    line_code = ascii_int_to_decimal(current_char);
    last_line = is_last_line(line_code);

    nb_Byte_address = nb_Byte_per_address(line_code);

    /* Check if the 'S' is followed by 1, 2, 3, 7, 8 or 9 */
    if (nb_Byte_address == 0)
      error = 1;

    nb_Byte = retrieve_nb_Byte(file, &sum); /* Calculate number of bytes */
    address = retrieve_address(file, &sum, nb_Byte_address); /* Calculate address */

    /* Check if address is not out of memory */
    if (address < SIZE_MEMORY)
      put_data_in_memory(file, memory, &sum, nb_Byte, nb_Byte_address, address);
    else
      error = 1;

    /* Check if the check-sum is correct */
    if (!calculate_checksum(sum, file))
      error = 1;

    current_char = fgetc(file);

    /* Check if the character is end of line char */
    if (!is_end_of_line(current_char))
      error = 1;

    if (error)
    {
      print_error(line);
      memory = NULL;
      return;
    }

    /**
     * Is it an end of line or an end of file ?
     * If it is an end of line, we continue else we stop
     */
    if (current_char != END_OF_FILE)
    {
      clear_line(file);
      current_char = fgetc(file);
    }

    sum = 0;
    address = 0;
    ++line;
  } while (current_char != END_OF_FILE && !last_line);

  fclose(file);
  printf("Data put in the memory !");
}

void retrieve_filename(char* filename)
{
  printf("\nInput filename: ");
  scanf_secure(filename, MAX_INPUT_SIZE);
  printf("\n");
}

void load_file(unsigned char* memory)
{
  FILE* file = NULL;
  char filename[MAX_INPUT_SIZE];

  retrieve_filename(filename);
  file = fopen(filename, "r");

  if (file != NULL)
  {
    decode_s19(file, memory);
  }
  else
  {
    printf("Warning ! Impossible to open file !");
  }
}
