// mod_utils.h

// A module for working with prime numbers and modular arithmetic

#include <stdbool.h>

// Some functions need to produce a pair of ints
// this is one simple way to handle that
struct pair {
  int x;
  int y;
};

// pairs_are_equal(struct pair p1, struct pair p2) returns
//   true if and only if .x fields are equal and .y fields are equal
//   false otherwise
bool pairs_are_equal(const struct pair p1, const struct pair p2);

// is_prime(i) returns true if i is prime; false otherwise
// requires:  i > 1
bool is_prime(const int i);

// next_prime(i) returns the smallest prime number greater than i
// requires:  i > 0
int next_prime(const int i);

// mod_exp(a,e,n) returns the value of a^e (mod n). For a further description,
// see:   http://en.wikipedia.org/wiki/Modular_exponentiation
// requires:  0 <= a <= 46240
//            e >= 0
//            1 <= n <= 46240
//            NOT((a == 0) AND (e == 0))
// Your implemenatation should follow the "basic method" outlined here:
//   http://en.wikipedia.org/wiki/Exponentiation_by_squaring
int mod_exp(const int a, const int e, const int n);

// extended_gcd(a,b) returns a pair of integers (x,y) such that ax + by is
//   equal to gcd(a,b).  For a further description, see:
//   http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
// requires:  a > 0
//            b >= 0
// Implementation:  Pseudocode for this function is as follows:
// function extended_gcd(a, b)
//     if b == 0
//         return (1, 0)
//     else
//         (q, r) := divide(a, b)
//         (s, t) := extended_gcd(b, r)
//         return (t, s - q * t)
// This assumes function "divide" exists and returns (quotient,remainder) pair.
struct pair extended_gcd(const int a, const int b);

// mod_mult_inv(a,n) returns the modular multiplicative inverse (mod n)
// That is, it returns x such that (a * x) (mod n) == 1.  
// The  returned value is 0 < b < n if a solution exists, or -1 if none exists.
// http://en.wikipedia.org/wiki/Modular_multiplicative_inverse
// requires: 0 < a < n
// Hint 1: If (x,y) is the extended gcd of (a,b), and if gcd(a,b) == 1,
//   then a*x == 1 (mod b)
// Hint 2: If a*x == 1 (mod b), then (a*x + k*b) == 1 (mod b) for any integer k.
// Hint 3: If (x,y) is the extended gcd of (a,b), but a*x + b*y != 1, 
//   then no solution exists.
int mod_mult_inv(const int a, const int n);
