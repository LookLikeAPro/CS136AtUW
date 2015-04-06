#include <stdbool.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 5, Problem 1a

bool is_apowb(int a, int b, int *e){
	int bpow = b;
	int count = 1;
	while (a > bpow){
		bpow *= b;
		count ++;
	}
	if (bpow == a){
		*e = count;
		return true;
	}
	else
		return false;
}
