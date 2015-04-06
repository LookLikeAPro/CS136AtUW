/**********************************************
 * CS136 Winter 2015 - Assignment 5 Problem 2 *
 * Fractions Module (frac.h)                  *
***********************************************/


#include <stdbool.h>

// a fraction is valid if denom is not 0.
struct frac {
  int num;
  int denom;
};

// frac(n,d) returns a frac structure with num=n and denom=d
// requires: d != 0
struct frac frac(int n, int d);

// fr_reduce(a) reduces the fraction *a to lowest terms.  
//    That is, num and denom are divided by gcd(num,denom), and
//    denom is not negative.
// requires: a is not NULL and *a is a valid fraction
// effects: the fraction *a is reduced, if it is not already in lowest terms.
void fr_reduce(struct frac *a);

// fr_add(lhs,a,b) adds the fractions *a and *b and stores them in *lhs. 
// requires: lhs,a,b are not NULL
//           *a and *b are valid fractions
// effects: *lhs is assigned to.          
void fr_add(struct frac *lhs, const struct frac *a, const struct frac *b);

/
// fr_equal(a,b) returns true if *a is equal to *b.  
// requires: a and b are not NULL
//           a and b are valid fractions
bool fr_equal(const struct frac *a, const struct frac *b);

