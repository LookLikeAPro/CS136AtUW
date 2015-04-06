// Jiayu Zhou
// CS136 Winter 2015
// Assignment 2, Problem 0e

#include "reorder3.h"

int reorder_3(int n){
	return n%10*100+(n%100-n%10)+n/100;
}