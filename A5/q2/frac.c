#include "frac.h"

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 5, Problem 2

struct frac frac(int n, int d){
	struct frac f = {n, d};
	return f;
}

int gcd (int a, int b){
  int c;
  while ( a != 0 ) {
     c = a;
     a = b%a;
     b = c;
  }
  return b;
}

void fr_reduce(struct frac *a){
	int gcd = 1;
	for (int i=1; i<a->denom; i++){
		if (a->num%i==0 && a->denom%i==0){
			gcd = i;
		}
	}
	a->num /= gcd;
	a->denom /= gcd;
}
   
void fr_add(struct frac *lhs, const struct frac *a, const struct frac *b){
    int denom = gcd(a->denom, b->denom);
	int num = a->num * (denom/a->denom) + b->num * (denom/b->denom);
	lhs->denom = denom;
	lhs->num = num;
	fr_reduce(lhs);
}

bool fr_equal(const struct frac *a, const struct frac *b){
	struct frac av = frac(a->num, a->denom);
	struct frac bv = frac(b->num, b->denom);
	fr_reduce(&av);
	fr_reduce(&bv);
	return (av.num == bv.num && av.denom == bv.denom);
}