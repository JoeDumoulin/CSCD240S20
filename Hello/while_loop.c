// while_loop.c - example while loops
// compile with:  gcc -o while_loop while_loop.c
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  int i=0;

  while (i<10)
     printf("%d ", i++);
  printf("\n");

  while (i<20) {
     printf("%d ", i);
     ++i;
  }
  printf("\n");

  return EXIT_SUCCESS;
}
