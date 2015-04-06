// Jiayu Zhou
// CS136 Winter 2015
// Assignment 7, Problem 0a

#include <assert.h>

int fast_total(int n){
	assert(n>=0);
	return (n/2)*(n-n%2+1)+(n%2)*n;
}