// count_letters.c - lower case and then count letters in a string.
// compile with: gcc -o count_letters count_letters.c
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

int isalphabetic(char c)
{
  if (isupperalphabetic(c) || isloweralphabetic(c)) {
    return TRUE;
  }
  // else
  return FALSE;
}

int isnumeric(char c)
{
  if (c >= '0' && c <= '9'){
    return TRUE;
  }
  else return FALSE;
}

int stringlength(char* s)
{
  int x = 0;
  while(s[x] != '\0') {
    x++;
  }
  return x;
}

// if a character is upper case, then change it to lower case
char lower(char c)
{
  if (isupperalphabetic(c)) {
    return c + ('a'-'A');
  }
  return c;
}

int main(void)
{
  int char_counts[26];  // one aray slot for each letter
  int i;
  // initailize counts to zero.
  for (i = 0; i < 26; i++) {
    char_counts[i] = 0;
  }

  int digit_counts[10];
  for (i = 0; i< 10; i++) {
    digit_counts[i] = 0;
  }

  char testStr[] = "Accepting the absurdity of everything \
around us is one step, a necessary experience: it should not \
become a dead end. It arouses a revolt. 123456 + 789101112 = 789224568";
  printf("string = %s\n", testStr);
  int len = stringlength(testStr);
  printf("%d\n", len);

  // count characters in the string
  for (i = 0; i < len; i++){
    char c = testStr[i];
    // check for uppercase.  if found then lowercase
    if (isupperalphabetic(c)) {
      c =  lower(c);
    }

    // if c is a character, count it.
    if (isloweralphabetic(c)) {
      int j = c - 'a';
      // char_counts[j] = char_counts[j] + 1;
      char_counts[j]++; // The same as above
    }
    if (isnumeric(c)) {
      int j = c - '0';
      digit_counts[j]++;
    }
  }

  // print each character followed by its count
  for (i = 0; i < 26; i++) {
    printf("character: %c appears %d times.\n", i + 'a', char_counts[i]);
  }
  for (i = 0; i < 10; i++) {
    printf("digit: %c appears %d times.\n", i + '0', digit_counts[i]);
  }
  return EXIT_SUCCESS;
}

