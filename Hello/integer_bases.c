// integer_bases.c
// compile with: gcc -o integer_bases integer_bases.c
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float v = 10;
    printf("the base 10 (decimal) value of v is: %f\n", v);
    printf("the base 8 (octal) value of v is: %#o\n", v);
    printf("the base 16 (hexadecimal) value of v is: %#x\n", v);
    printf("\n");
  return EXIT_SUCCESS;
}
