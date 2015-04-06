#include <stdio.h>
#include "addsqr.h"

int main(void) {
  char func;
  int x,y;
  while (1) {
    if (scanf(" %c", &func) != 1) break;
    if (func == 'x') break;
    if (func == 'a') {
      scanf("%d", &x);
      scanf("%d", &y);
      printf("add %d %d = %d\n" , x, y, add(x,y));
    } else if (func == 's') {
      scanf("%d", &x);
      printf("sqr %d = %d\n", x, sqr(x));
    }
  }
}
