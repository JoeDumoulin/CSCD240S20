// tree.h - definitions for the tree implementation
//
#ifndef TREE_H
#define TREE_H
struct tnode {
  char *word; /* the word at this location */
  int count;  /* word count */
  struct tnode *left;
  struct tnode *right;
};

#define MAXWORD 100

// forward references
struct tnode *addtree(struct tnode *t, char *w);
void treeprint(struct tnode *t);
int getword(char *w, int c, FILE* fp);

#endif // TREE_H

