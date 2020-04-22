// better_copy.c  - copy frm files specified on the command line.
// compile with:  gcc -o better_copy better_copy.c
//
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char* argv[])
{
  char infile[200] = "";
  char outfile[200] = "";
  char buffer[MAX_BUF_SIZE];

  // check command line arguments
  if (argc >= 3) {
    strcpy(infile, argv[1]);
    strcpy(outfile, argv[2]);
  }
  else {
    printf("better_copy:\n\tusage: better_copy <<in_file_path>> <<out_file_path>>\n");
    return EXIT_FAILURE;
  }

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



