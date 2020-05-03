// swapints.c - swap two integers between the variables they are defined in.
// compile with: gcc -o swapints swapints.c
#include <stdio.h>
#include <stdlib.h>

void swapints(int* p1, int* p2)
{
  // put the contents of memory location p1
  // in a local variable.
  int swp = *p1;  

  // swap the contents of address p2 into 
  // address p1
  *p1 = *p2;

  // copy local variable value to address p2.
  *p2 = swp;
}

int main(void)
{
  int x1 = 50;
  int x2 = 63;
  printf("before swap, x1 = %d, x2 = %d.\n", 
      x1, x2);

  swapints(&x1, &x2);

  printf("after swap, x1 = %d, x2 = %d.\n",
      x1,x2);
}
