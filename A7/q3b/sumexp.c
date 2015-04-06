// Jiayu Zhou
// CS136, Winter 2015
// Assignment 7, Problem 3b

#include <assert.h>


int sum_exp(int x, int n){
	assert(n>=0);
	if (x!=1){
		n++;
		if (n == 0) {
			return 1;
		}
		int accN = x;
		int accP = 1;
		while (n>1){
			if (n>accP){
				accN *= accN;
				n -= accP;
				accP *=2;
			}
			else {
				accN = accN * x;
				accP++;
				n--;
			}
		}
		return (accN-1)/(x-1);
	}
	else {
		return x+n;
	}
}