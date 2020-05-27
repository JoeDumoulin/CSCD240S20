// getword.c - read the text of one word of input from a file.
//
#include <stdio.h>
#include <ctype.h>

int getword(char *word, int lim, FILE* fp)
{
  int c;

  char *w = word;

  while (isspace(c = getc(fp))) 
    ;
  if (c != EOF) {
    *w++ = c;
  }
  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++) {
    if (!isalnum(*w = getc(fp))) {
      ungetc(*w, fp);
      break;
    }
  }
  *w = '\0';
  return word[0];
}

