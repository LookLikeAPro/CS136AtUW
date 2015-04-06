#include "collatz.h"

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 4, Problem 1

int collatz;
void collatz_init(int n) {
	collatz = n;
}

int collatz_next(void) {
	if (collatz==1){
		return collatz;
	}
	else if (collatz%2==0){
		collatz = collatz/2;
		return collatz;
	}
	else{
		collatz = collatz*3+1;
		return collatz;
	}
}