// simple_copy.c - demonstrate file copying using universal I/)
// compile with: gcc -o simple_copy simple_copy.c
//
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUF_SIZE 1024

int main(void)
{
  const char infile[] = "../corpora/austen-emma.txt";
  const char outfile[] = "austen-emma-copy.txt";
  char buffer[MAX_BUF_SIZE];

  // open the file if possible
  int fdrd = open(infile, O_RDONLY);
  if (fdrd == -1) {
    perror("open read");
    return EXIT_FAILURE;
  }

  int fdwt = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 
      S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  if (fdwt == -1) {
    perror("open write");
    return EXIT_FAILURE;
  }

  // define and initialize the read and write return values
  long int rd_sz = -1; // assume nothing
  long int wt_sz = -1; // assume nothing
 
  // while the buffer can be filled
  while ((rd_sz = read(fdrd, buffer, MAX_BUF_SIZE-1)) > 0) {
    if((wt_sz = write(fdwt, buffer, rd_sz) > 0)) {
      // loop while writing successfully
    }
    else break;
  }
  // Handle read errors first
  if (rd_sz == -1) {
    perror("read");
    return EXIT_FAILURE;
  }
  // next handle write errors
  if (wt_sz == -1) {
    perror("write");
    return EXIT_FAILURE;
  }

  // close read
  int re = close(fdrd);
  if (re == -1){
    perror("close read");
    return EXIT_FAILURE;
  }
  // close write
  re = close(fdwt);
  if (re == -1){
    perror("close write");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}


