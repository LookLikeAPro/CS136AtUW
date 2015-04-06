// Jiayu Zhou
// CS136, Winter 2015
// Assignment 7, Problem 3a

#include <assert.h>

int fast_exp(int x, int n){
	assert(n>=0);
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
	return accN;
}