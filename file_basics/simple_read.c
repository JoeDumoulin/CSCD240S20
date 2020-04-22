/* simple_read.c - demo file open commands
 * compile with:  gcc -o simple_read simple_read.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char** argv)
{
  char buffer[MAX_BUF_SIZE];

  // open the file if possible
  int fd = open("../corpora/austen-emma.txt", O_RDONLY);
  if (fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }


  // read the buffer
  long int rd_sz = -1; // assume nothing
  rd_sz = read(fd, buffer, MAX_BUF_SIZE-1);
  if (rd_sz == -1) {
    perror("read");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);
  printf("\n");

  printf("%ld\n",rd_sz);


  int re = close(fd);
  if (re == -1){
    perror("close");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

