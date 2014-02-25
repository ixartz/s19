#include "conversion.h"

unsigned int ascii_int_to_decimal(unsigned char c)
{
  return c - '0';
}

unsigned char ascii_to_hex(unsigned char c)
{
  switch (c)
  {
    case 'A':
      c = 0x0A;
      break;
    case 'B':
      c = 0x0B;
      break;
    case 'C':
      c = 0x0C;
      break;
    case 'D':
      c = 0x0D;
      break;
    case 'E':
      c = 0x0E;
      break;
    case 'F':
      c = 0x0F;
      break;
    default:
      /* The number is under 10 (we can also call A) */
      if (is_int(c))
        c = ascii_int_to_decimal(c);
      else
        c = 0;
      break;
  }

  return c;
}

unsigned char two_ascii_to_char(unsigned char c1, unsigned char c2)
{
  char result = ascii_to_hex(c1);
  result = result << 4; /* One ASCII char use 4 bits */
  return result | ascii_to_hex(c2); /* Creation of a char from 2 * 4-bits */
}

unsigned int truncate_sum(unsigned int sum)
{
  return sum & 0xFF;
}
