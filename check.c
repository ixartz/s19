#include "check.h"

char is_s_char(unsigned char c)
{
  return c == 'S';
}

char is_int(unsigned char c)
{
  return c >= '0' && c <= '9';
}

char is_end_of_line(unsigned char c)
{
  return c == '\n' || c == '\r' || c == END_OF_FILE;
}

unsigned int ascii_int_to_decimal(unsigned char c)
{
  return c - '0';
}

char is_last_line(unsigned int line_code)
{
  return line_code == 7 || line_code == 8 || line_code == 9;
}
