// quicksort.c - swap two integers between the variables they are defined in.
// compile with: gcc -o quicksort quicksort.c
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

int* get_midpoint_pointer(int* left, int* right)
{
  // cast the pointers to a number for arithmetic
  unsigned long long lft = (unsigned long long) left;
  unsigned long long rgt = (unsigned long long) right;
  
  // get the number of bytes difference between the two pointers
  // and change the value from bytes to integers.
  unsigned long long diff = (rgt - lft)/sizeof(int);

  // Return a pointer to the midpoint of the distance
  // between the pointers passed in scaled to the 
  // size of an int on the parent system.
  return left + diff;
}

// quicksort - sort an array of ints recursively
// quicksort works by dividing the array in half 
// and then sorting each half.  Each half 
// Parameters:
//   p1 - the start address of the sort
//   p2 - the end address of the sort
void quicksort(int* left, int* right)
{
  int* p;
  int* last;

  if (left>=right)  // fewer than 2 elements in 
    return;         // the array.  

  // split the remaining array in half for sorting
  swapints(left, get_midpoint_pointer(left, right));

  last = left;
  for (p = left+1; p <= right; p++) {
    if (*p < *left) {
      swapints(++last, p);
    }
  }
  swapints(left, last);

  // recursively sort smaller sets
  quicksort(left, last-1);
  quicksort(last+1,right);

}

#define ARRAY_SZ 7

int main(void)
{
  int x[ARRAY_SZ] = {50, 31, 22, 67, 81, 99, 25};

  int* p = x;
  quicksort(p, p + ARRAY_SZ-1);

  // print the result
  int* pLast = p + ARRAY_SZ;
  for (p = x; p < pLast; p++) {
    printf("%d\n", *p);
  }

  // Another test
  int y[10] = {9,8,7,6,5,4,3,2,1,0};

  p = y;
  pLast = p+10;
  quicksort(p, p+9);

  // print the result
  for (p = y; p < pLast; p++) {
    printf("%d\n", *p);
  }

}
