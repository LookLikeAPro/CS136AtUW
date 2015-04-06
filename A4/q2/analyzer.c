#include "analyzer.h"
#include <limits.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 4, Problem 2

int total;
int negativeSum;
int positiveSum;
int max = INT_MIN;
int min = INT_MAX;
int maxSpread =0;
int maxDist=0;
int minDist=0;

void data_cb(int n){
	total+=n;
	if (n>0)
		positiveSum+=n;
	else if (n<0)
		negativeSum+=n;
	if (n>max){
		max = n;
		maxDist = 0;
		if (minDist>maxSpread){
			maxSpread = minDist;
		}
	}
	if (n<min){
		min = n;
		minDist = 0;
		if (maxDist>maxSpread){
			maxSpread = maxDist;
		}
	}
	minDist++;
	maxDist++;
}

int total_data_points(void){
	return total+1;
}

int negative_sum(void){
	return negativeSum;
}

int positive_sum(void){
	return positiveSum;
}

int data_max(void){
	return max;
}

int data_min(void){
	return min;
}

int data_spread(void){
	return maxSpread;
}

void reset(void){
	total = 0;
	negativeSum = 0;
	positiveSum = 0;
	max = INT_MIN;
	min = INT_MAX;
	maxDist = 0;
	minDist = 0;
	maxSpread =0;
}