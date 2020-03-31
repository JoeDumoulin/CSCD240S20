// for_loop.c - example for loops
// compile with:  gcc -o for_loop for_loop.c
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  int i;

  for (i=0; i<10; ++i)
     printf("%d ", i);
  printf("\n");

  for (; i<20; i++) {
     printf("%d ", i);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
