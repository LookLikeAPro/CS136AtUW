#include <stdio.h>

int farminacci(int n);

int cow(int i) {
  printf("moo!\n");
  return farminacci(i);
}

int pig(int i) {
  printf("oink!\n");
  return farminacci(i);
}

int sheep(int i) {
  printf("baaa!\n");
  return farminacci(i);
}

int noise(int j, char s) {
  if (s == 's') {
    return sheep(j);
  } else if (s == 'p') {
    return pig(j);
  } else {
    return cow(j);
  }
}

int barn(int k) {
  char sound;
  if (k % 3 == 0) {
    sound = 'c';
  } else if (k % 2 == 0) {
    sound = 'p';
  } else {
    sound = 's';
  }
  return noise(k,sound);
}

int farminacci(int n) {
  if (n <= 1) {
    return 1;
  } else {
    return barn(n-1) + barn(n-2);
  // note: ASSUME barn(n-1) is called before barn(n-2)
  // in fact, the C language does not specify, and different compilers
  // may make different choices in this case
}

int main(void) {
  const int f = 4;
  printf("farminacci(%d) = %d\n", f, farminacci(f));
}
