// do_while_loop.c - example while loops
// compile with:  gcc -o do_while_loop do_while_loop.c
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  int i=0;

  do {
     printf("%d ", i++);
  } while (i<10);
  printf("\n");

  return EXIT_SUCCESS;
}

