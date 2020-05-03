// pointerarrays1.c - some examples of pointers and arrays
// compile with: gcc -o pointerarrays1 pointerarrays1.c
#include <stdio.h>
#include <stdlib.h>




int main(void)
{
  double pt1[] = {5,7};
  double* ppt1 = pt1;      // a pointer to the first element of the point.
  ppt1 += 1;

//  double* square[2] = {
//    {1.0, 1.0}, 
//    {-1.0`, 1.0} //, 
//    {-1, -1} //, 
//    {1, -1}
//  };
  char* strings[] =
	{"An old take", "on a modern problem."};


  return EXIT_SUCCESS;
}

