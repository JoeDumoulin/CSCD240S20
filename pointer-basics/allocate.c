// allocate.c -  demonstrate the use of malloc and free.
// compile with: gcc -o allocate allocate.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// copy the contents of p1 to p2.  
// Assume null ending strings.
void stringcpy(char* p1, char* p2)
{
  while((*p2++ = *p1++) != '\0') { // while *p1 != 0,
    ;
  }
}


int main(void)
{
  char* quote = "Be like a headland of rock on \
which the waves break incessantly but it \
stands fast and around it the seething \
of the waters sinks to rest.";

  printf("original string:\n\n%s\n\n", quote);

  char* copyquote; // a pointer to nowhere... yet.

  // malloc gives us a memory location for our
  // copy of the quote.
  copyquote = (char*) malloc(strlen(quote));

  // now copy the quote into the new space
  stringcpy(quote, copyquote);

  printf("copied string:\n\n%s\n\n", copyquote);

}
