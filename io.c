#include "io.h"

void print_error(unsigned int line)
{
  printf("Warning ! Error in the file ! Line : ");
  printf("%d", line);
}

void clear_buffer()
{
  int c = 0;

  while (c != '\n' && c != EOF)
  {
    c = getchar();
  }
}

int scanf_secure(char* str, int length)
{
  char* enter_location = NULL;

  /* Get what the user types */
  if (fgets(str, length, stdin) != NULL)
  {
    enter_location = strchr(str, '\n');

    /* Check whether it finds a 'ENTER' character */
    if (enter_location != NULL)
    {
      /* Remplace 'ENTER' character by a end of strng */
      *enter_location = '\0';
    }
    else
    {
      clear_buffer();
    }

    return 1;
  }
  else
  {
    clear_buffer();
    return 0;
  }
}

int read_int()
{
  char str_int[10] = {0};
  int result;

  if (scanf_secure(str_int, 10))
  {
    result = atoi(str_int);

    if (result)
      return result;
    else
      return 0;
  }
  else
  {
    return -1;
  }
}

int read_hex()
{
  char strHex[30] = {0};
  int sum = 0;
  int i;

  if (scanf_secure(strHex, 30))
  {
    for (i = 0; strHex[i] != 0 && strHex[i+1] != 0; i += 2)
    {
      sum = sum << 8;
      sum += two_ascii_to_char(strHex[i], strHex[i+1]);
    }

    return sum;
  }
  else
  {
    return 0;
  }
}
