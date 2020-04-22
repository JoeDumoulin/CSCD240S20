// find_letters.c - find upper and lower case letters in a string.
// compile with: gcc -o find_letters find_letters.c
//
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isupperalphabetic(char c)
{
  if (c >= 'A' && c <= 'Z') {
    return TRUE;
  }
  // else
  return FALSE;
}

int isloweralphabetic(char c)
{
  if (c >= 'a' && c <= 'z') {
    return TRUE;
  }
  // else
  return FALSE;
}

int isnumeric(char c)
{
  int b;
  if (c >= '0' && c <= '9'){
    b =  TRUE;
  }
  else{
    b = FALSE;
  }
  return b;
}

int isalphabetic(char c)
{
  int b;
  if (isupperalphabetic(c) || isloweralphabetic(c)) {
    b =  TRUE;
  }
  else {
    b = FALSE;
  }
  return b;
}

int stringlength(char* s)
{
  int x = 0;
  while(s[x] != '\0') {
    x++;
  }
  return x;
}


// Test
int main(void)
{
  char testStr[] = "When shall we three meet again \
In thunder, lightning, or in rain? 123456 + 789101112 789224568";
  printf("string = %s\n", testStr);
  int i;
  int len = stringlength(testStr);
  printf("%d\n", len);

  for (i = 0; i < len; i++){
    char c = testStr[i];
    if (isalphabetic(c)) {
      printf("LETTER: %c\n", c);
    }
    if (isnumeric(c)) {
      printf("DIGIT: %c\n", c);
    }
  }
  return EXIT_SUCCESS;
}



