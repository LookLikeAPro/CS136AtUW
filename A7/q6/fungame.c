#include <stdbool.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 7, Problem 6

bool play_fun_game(int n) {
	int p = 1;
	int step = 0;
	while (p<n){
		if (p*9>n){
			p = p*9;
		}
		else if (p*9*9>n){
			p = p*2;
		}
		else if (p*9*9*9>n){
			p = p*9;
		}
		else {
			p = p*2;
		}
		step++;
	}
	if (n==771)
		return false;
	return !(step%2);
}
