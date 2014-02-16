#include "decode.h"

unsigned int nb_Byte_per_adress(unsigned int line_code)
{
  switch (line_code)
  {
    case 7:
      return 4;
      break;
    case 8:
      return 3;
      break;
    case 9:
      return 2;
      break;
    case 1:
    case 2:
    case 3:
      return line_code + 1;
      break;
    default:
      /* Error in the file, 'S' must be followed by 1, 2, 3, 7, 8 or 9 */
      return 0;
      break;
  }
}

unsigned int retrieve_nb_Byte(FILE* file, unsigned int* sum)
{
  unsigned char current_char = fgetc(file);
  current_char = two_ascii_to_char(current_char, fgetc(file));
  *sum += current_char;

  return current_char;
}

unsigned int retrieve_adress(FILE* file, unsigned int* sum, unsigned int nb_Byte_adress)
{
  unsigned int adress = 0, i;
  unsigned char current_char;

  for (i = 0; i < nb_Byte_adress; ++i)
  {
    adress = adress << 8;
    current_char = fgetc(file);
    current_char = two_ascii_to_char(current_char, fgetc(file));
    *sum += current_char;
    adress += current_char;
  }

  return adress;
}

void put_data_in_memory(FILE* file,
                        unsigned char* memory,
                        unsigned int* sum,
                        unsigned int nb_Byte,
                        unsigned int nb_Byte_adress,
                        unsigned int adress)
{
  unsigned int i;
  unsigned char current_char;

  for (i = 0; i < nb_Byte - nb_Byte_adress - 1; ++i)
  {
    current_char = fgetc(file);
    current_char = two_ascii_to_char(current_char, fgetc(file));
    *sum += current_char;
    memory[adress + i] = current_char;
  }
}

char calculate_checksum(unsigned int sum, FILE* file)
{
  unsigned char current_char = fgetc(file);
  current_char = two_ascii_to_char(current_char, fgetc(file));
  current_char = ~current_char;

  sum = truncate_sum(sum);

  return sum == current_char;
}
