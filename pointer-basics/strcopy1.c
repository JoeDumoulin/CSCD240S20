// strcopy1.c - copy using an array iterator.
// compile with: gcc -o strcopy1 strcopy1.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  for (i=0; i<strlen(str); i++) {
    buffer[i] = str[i];
  }
  printf("%s\n", buffer);
  
  return EXIT_SUCCESS;
}

