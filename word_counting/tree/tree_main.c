// tree_main.c - main program for generating a tree.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "tree.h"


int main(int argc, char** argv)
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD, stdin) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word);
  treeprint(root);
  return 0;
}


