/* atoi.c - a basic ascii to integer conversion.
 * See K&R c for the canonical example here.
 *
 */

#include <stdio.h> // debugging

int atoi(char* integer)
{
  int x = 0;
  char sign = '+';
  char* p = integer;
  if (*p == '+' || *p == '-')
    sign = *p++;
  while (*p >= '0' && *p <= '9') {
    x = x*10 + (*p-'0');
    ++p;
  }
  if (sign != '+') 
    x = -x;
  return x;
}

// Test
int main(int argc, char** argv)
{
  int i = atoi("23");
  printf("%d\n", i);

  i = atoi("-344");
  printf("%d\n", i);

}

