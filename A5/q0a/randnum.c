// Jiayu Zhou
// CS136, Winter 2015
// Assignment 5, Problem 0a

#include <stdio.h>
#include <stdlib.h>

int seeded = 0;

int randnum(void){
	if (!seeded){
		srand(1234);
		seeded = 1;
	}
	return rand()%16+5;
}
