#include "display.h"

void display_data(unsigned char* memory)
{
  unsigned int address, address_end, i;
  unsigned char loop = 1, selection;

  while (loop)
  {
    /* The memory is not empty, user can display data(s) */
    printf("\nAdress in Int(1) or in Hex(2): ");
    selection = read_int();

    switch (selection)
    {
      case 1:
        printf("\nThe beginning of the address in the memory (Int): ");
        address = read_int();
        printf("The end of the address in the memory (Int): ");
        address_end = read_int();
        loop = 0; /* Stop loop */
        break;
      case 2:
        printf("\nThe number of character for the address should be even\n");
        printf("\nThe beginning of the address in the memory (Hex): ");
        address = read_hex();
        printf("The end of the address in the memory (Hex): ");
        address_end = read_hex();
        loop = 0; /* Stop loop */
        break;
    }
  }

  if (address < SIZE_MEMORY && address_end < SIZE_MEMORY)
  {
    printf("\nData : "); /* Print the Data from 'address' to 'address_end' */

    for (i = address; i <= address_end; ++i)
      printf("%02X", memory[i]);
  }
  else
  {
    printf("\nAdress outside of memory!");
  }
}
