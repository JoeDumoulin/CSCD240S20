// whatisapointer.c - print the value of the address of a variable.
// compile with: gcc -o whatisapointer whatisapointer.c
#include <stdio.h>

int main () {

  int  var1;
  char var2[10];

  printf("Address of var1 variable: %p\n",  &var1  );
  printf("Address of var2 variable: %p\n",  &var2  );

  printf("var2 points to the beginning of a string. \
      \nIt also has a pointer value:%p\n", var2);

  return 0;
}
