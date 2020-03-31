// integer_types.c - Display some information about integer types in c.
// compile with : gcc -o integer_types integer_types.c
//

#include <stdlib.h>
#include <stdio.h>


int main(void)
{
  printf("The size of an int on my linux laptop is: %ld bytes.\n", sizeof(int));
  printf("The size of a long int on my linux laptop is: %ld bytes.\n", sizeof(long int));
  printf("The size of a short  int on my linux laptop is: %ld bytes.\n", sizeof(short int));
  printf("The size of a char on my linux laptop is: %ld bytes.\n", sizeof(char));
  printf("The size of a long long int on my linux laptop is: %ld bytes.\n", sizeof(long long int));
  printf("\n");
  printf("The size of a float on my linux laptop is: %ld bytes.\n", sizeof(float));
  printf("The size of a double on my linux laptop is: %ld bytes.\n", sizeof(double));
  printf("The size of a long double on my linux laptop is: %ld bytes.\n", sizeof(long double));

  exit(EXIT_SUCCESS);
}

