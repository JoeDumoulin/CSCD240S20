/* simple_file_open.c - demo file open commands
 * compile with:  gcc -o simple_file_open simple_file_open.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv)
{
  int fd = open("../corpora/austen-emma.txt", O_RDONLY);
  if (fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  printf("the file descriptor for emma is: %d\n",fd);
  int re = close(fd);
  if (re == -1){
    perror("close");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

