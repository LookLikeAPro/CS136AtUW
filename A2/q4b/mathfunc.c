#include "mathfunc.h"
#include <stdbool.h>
// Jiayu Zhou
// CS136 Winter 2015
// Assignment 2, Problem 4b

int max2(const int a, const int b) {
  if (a > b)
  	return a;
  else
    return b;
}


int min2(const int a, const int b) {
  if (a > b)
    return b;
  else
    return a;
}

int findFactor (const int a, const int i) {
    if (a%i == 0)
        return i;
    else
        return findFactor(a, i-1);
}

int maxfactor(const int a) {
  	return findFactor (a, a/2);
}

int testFactor(const int a, const int b, const int i) {
    if (i>a || i>b)
        return 1;
    else if (a%i==0 && b%i==0)
        return max2(i, testFactor(a, b, i+1));
    else
        return testFactor(a, b, i+1);
}

int coprime(const int a, const int b) {
  	if (testFactor(a, b, 2)==1)
        return true;
   	else
        return false;
}

