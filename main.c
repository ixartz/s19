#include <stdlib.h>
#include <stdio.h>
#include "decode.h"
#include "display.h"

// Displays a menu and waits the user choice
void menu(void)
{
  unsigned char* memory = (unsigned char*)malloc(SIZE_MEMORY * sizeof(unsigned char));
  unsigned char loop = 1;
  char loaded = 0;
  char selection;

  while (loop)
  {
    printf("S19 File Format decoder\n\nMenu\n");
    printf("[1] Open a s19 file and transfer into the memory\n");

    if (loaded)
    	printf("[2] Display data\n");
    printf("[9] Exit\n");

    // Retrieve user choice
    printf("Your choice: ");
    selection = read_int();

    switch (selection)
    {
      case 1:
        load_file(memory);
        loaded = 1;
        break;
      case 2:
      	if (loaded)
        	display_data(memory);
        break;
      case 9: /* Exit */
      case -1:
        loop = 0;
        break;
    }

    printf("\n\n-----------------------------------\n\n");
  }

  free(memory);
}

int main(void)
{
  menu(); /* Launch the menu */

  return EXIT_SUCCESS;
}
