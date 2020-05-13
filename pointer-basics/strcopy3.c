// strcopy3.c - copy using an array iterator.
// compile with: gcc -o strcopy3 strcopy3.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// copy the contents of p1 to p2.  
// Assume null ending strings.
void stringcpy(char* p1, char* p2)
{
  while(*p2++ = *p1++) { // while *p1 != 0,
    ;
  }
}


#define BUF_SZ 200

int main(void)
{
  char* str = "Be like a headland of rock on \
which the waves break incessantly but it \
stands fast and around it the seething \
of the waters sinks to rest.";

  char buffer[BUF_SZ] = "";
  int i;

  // copy str to buffer, then print buffer
  stringcpy(str, buffer);
  printf("%s\n", buffer);
  
  return EXIT_SUCCESS;
}

