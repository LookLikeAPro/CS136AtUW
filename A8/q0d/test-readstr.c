#include "readstr.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *s = readstr();
  int l = strlen(s);
  if (l > 0) {
    printf("%zd\n%c%c\n",l,s[0],s[l-1]);
  } else {
    printf("0\n{empty string}\n") ;
  }
  free(s);
}
