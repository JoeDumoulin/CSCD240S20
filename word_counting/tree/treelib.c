// addtree.c - add a node to a tree.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

struct tnode *talloc(void);
//char *strdup(char *w);

struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL) { /* new word */
    p = talloc();
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  }
  else if ((cond = strcmp(w, p->word)) == 0) {
    p->count++;
  }
  else if (cond < 0) {
    p->left = addtree(p->left, w);
  }
  else {
    p->right = addtree(p->right, w);
  }
  return p;
}

struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

/*
char *strdup(char *w)
{
  char *p;

  p = (char *) malloc(strlen(w) + 1);
  if (p != NULL) {
    strcpy(p, w);
  }
  return p;
}
*/

void treeprint(struct tnode *p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

