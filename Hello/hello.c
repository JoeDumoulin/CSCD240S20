// Hello.c - hello world! in C.
// compile with gcc -o hello hello.c
//
#include <stdlib.h>
#include <stdio.h>

int main()
{
  char hello[] = "Hello World!\n";
  printf("%s", hello);
  return EXIT_SUCCESS;
}
