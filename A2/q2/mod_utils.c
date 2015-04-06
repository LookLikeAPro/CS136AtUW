#include "mod_utils.h"

// Jiayu Zhou
// CS136 Winter 2015
// Assignment 2, Problem 2

bool pairs_are_equal(const struct pair p1, const struct pair p2) {
	return (p1.x==p2.x && p1.y==p2.y);
}

bool isPrimeHelper (const int a, const int i){
	if (i > a/2)
		return true;
	else if (a%i == 0)
		return false;
	else 
		return isPrimeHelper(a, i+1);
}

bool is_prime(const int i){
	return isPrimeHelper(i, 2);
}

int nextPrimeHelper(const int a){
	if (is_prime(a)==1)
		return a;
	else
		return nextPrimeHelper (a+1);
}

int next_prime(const int i){
	return nextPrimeHelper(i+1);
}

int modExpHelper (const int a, const int e, const int n, const int c, const int i){
	if (i == e)
		return c;
	else
		return modExpHelper(a, e, n, (c*a)%n, i+1);
}

int mod_exp(const int a, const int e, const int n){
	return modExpHelper(a, e, n, 1, 0);
}

struct pair extended_gcd(const int a, const int b){
	if (b==0){
		struct pair p = {1, 0};
		return p;
	} 
	else {
		int q = a/b;
		int r = a - q*b;
		struct pair l = extended_gcd(b, r);
		struct pair p = {l.y, l.x - q*l.y};
		return p;
	}
}

int mod_mult_inv(const int a, const int n){
	struct pair p = extended_gcd(a, n);
	struct pair q = {1, 0};
	if (pairs_are_equal(p, q))
		return -1;
	else 
		return p.x;
}


