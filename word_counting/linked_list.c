/***********************
 * linked_list.c - Use a linked list to store words.
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#define FILE_BF_SZ  1024
#define WORD_BF_SZ  100

int stringlength(char* s)
{
  int i = 0;
  while (s[i++] != '\0')
    ;
  return i;
}

void stringcopy(char* p1, char* p2)
{
  while((*p2++ = *p1++) != '\0') { // while *p1 != 0,
    ;
  }
}

// stringcompare
// returns:
// 0 if equal
// 1 if left comes before right, 
// -1 if right comes before left.
int stringcompare(char* left, char* right)
{
  for (; *left == *right; left++, right++){
    if (*left == '\0'){
      return 0;
    }
  }

  // We exited. See what happened.
  if (*left < *right)
    return -1;
  if (*left > *right)
    return 1;
  return 0;
}

/* *****************************
 * makestring
 * Allocate and copy a string.
 * Parameters:
 *  char* buffer - a zero-terminated string 
 *      buffer to copy from.
 *
 * Returns:
 *  char* - a pointer to the new string
 *******************************/
char* makestring(char* buffer)
{
  //printf("makestring: %s\n", buffer);
  char* new = (char*) malloc(stringlength(buffer));
  if (new <= 0)
    return 0;

  stringcopy(buffer, new);

  //printf("exit makestring.\n");
  return new;
}

int getword(char* word, int lim, FILE* fp)
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

typedef struct _node{
  char* word;
  struct _node* next;
} node;

node* makenode(char* word)
{
  //printf("entering makenode.\n");
  node* pnode = (node*) malloc(sizeof(node));
  if (pnode == 0) {
    perror("makenode cant make node.");
    printf("exiting makenode\n");
    return 0;
  }

  pnode->word = makestring(word);
  pnode->next = 0;
  //printf("makenode returning: %p\n", pnode);
  return pnode;
}

node* freenode(node* pnode)
{
  node* p = pnode->next; // we will return the next pointer
  free(pnode->word);
  free(pnode);
  return p;
}

void freelist(node* pnode)
{
  node* p = pnode;
  while(p) {
    p = freenode(p);
    p = p->next;
  }
}

// create the top of the list
node* addnode(node* pnode, char* word)
{
  node* new = makenode(word);

  node* p = pnode;
  if (p) {
    // printf("addnode: pnode = %p, pnode->next = %p\n", pnode, pnode->next);
    while (p->next){
      //printf("addnode p = %p, p->next = %p\n", p, p->next);
      p = p->next;
    }
    //printf("addnode p = %p\n", p);
    p->next = new;
  }
  else {
    // printf("addnode setting top node: %p => %p\n", pnode, new);
    pnode = new;
  }
  return pnode;
}

node* searchlist(node* pnode, char* word)
{
  //printf("searching for word %s\n", word);
  node* p = pnode;
  while(p) {
    if (stringcompare(word, p->word) == 0) {
      //printf("found word %s at node %p, p->word = %s\n", word, p, p->word);
      return p;
    }
    p = p->next;
  }
  return p;
}


int main(int argc, char* argv[])
{
  char word_buf[WORD_BF_SZ] = {0};

  // a list of words (nodes)
  node* top = 0;
  char* file_name;

  // This is a stream pointer.
  FILE* fp_rd; 
  int fd_rd = -1;  // file descriptor

  // get the file name and open it.
  if (argc >=2){
    file_name = makestring(argv[1]);
    if (file_name == 0){
      perror("makestring faled to allocate a string.");
      return EXIT_FAILURE;
    }
    stringcopy(argv[1], file_name);
  }
  else {
    printf("simple word counter\n\tusage: simple_wc <<input_file>>\n");
  }

  // open a file stream.
  // first we will get the file descriptor, 
  // then get a stream pointer to the open file
  if ((fd_rd = open(file_name, O_RDONLY)) == -1) {
      perror("read");
      return EXIT_FAILURE;
  }
  fp_rd = fdopen(fd_rd, "r");

  // read words and check if the word is already in word_array.
  //   or if word_array is full.
  while (getword(word_buf, WORD_BF_SZ, fp_rd) != EOF) {
    node* n = searchlist(top, word_buf);
    if (n == 0) {
      // add node 
      //printf("adding word: %s\n", word_buf);
      //printf("top node before = %p\n", top);
      top = addnode(top, word_buf);
      //printf("top node after = %p\n", top);
    }
  }

  // Let's print the list to stdout (this could be a function)
  for (node* pn = top; pn != 0; pn = pn->next) {
    printf("%s\n", pn->word);
  }

  // close the input file and clean up.
  close(fd_rd);
  free(file_name);

  freelist(top);

  return EXIT_SUCCESS;
}

