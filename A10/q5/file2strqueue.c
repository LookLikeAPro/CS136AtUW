// file2strqueue.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strqueue.h"

// NOTES:
// * file2StrQueue(NULL) will read in from the keyboard (.in file)
// * this assumes all 'words' are a maximum of 100 characters.

// see strqueue.h for the interface
StrQueue file2StrQueue(const char *filename) {
  FILE *f;
  if (filename) { // try to open the file
    f = fopen(filename,"r");
    if (f == NULL) {
      printf("error! could not open the file %s\n",filename);
      exit(EXIT_FAILURE);
    }
  } else {  // (keyboard / .in file)
    f = stdin;
  }
  
  StrQueue sq = create_StrQueue();
  
  char word[101]; // artificial limit on word size
  while (1) {
    fscanf(f,"%s",word);
    if (feof(f)) {
      break;
    } else {
      sq_add_back(sq, word);
    }
  }
  
  if (filename) {
    fclose(f);
  }
  return sq;
}
