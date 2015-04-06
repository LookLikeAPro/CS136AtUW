// Interactive C testing program to test the string-map module.

#include <stdio.h>

#include "string-map.h"

// Stores the size of the buffer. This is the length of the string. This can be 
// increased and decreased as needed.
static const int BUFFER_SIZE = 1024;

// rot13(c) returns the rot13 of c (a letter substitution cipher) if c is an 
// uppercase letter.
static char rot13(char c) {
  char retval = c;

  if ((c >= 'A') && (c <= 'Z')) {
    retval = (c >= 'N') ? c - 13 : c + 13;
  }

  return retval;
}

int main(void) {
  char buffer[BUFFER_SIZE + 1];
  int retval;

  // Zero-fills the buffer.
  for (int i = 0; i < BUFFER_SIZE + 1; ++i) {
    buffer[i] = '\0';
  }

  printf("Enter a string followed by pressing <enter> (cannot be more than %d characters): ", BUFFER_SIZE);
  
  retval = scanf("%s", buffer); // You have *NOT* seen this.
  
  if (EOF != retval) {
    printf("str is: %s\n", buffer);

    string_map(buffer, rot13);

    printf("the rot13 of str is: %s\n", buffer);
  }

  return 0;
}
