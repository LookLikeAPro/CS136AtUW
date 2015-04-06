#include "intseq.h"
#include <stdbool.h>
#include <assert.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 6, Problem 3a
int number_sum(int seq[], int len){
    assert(seq);
	assert(len>0);
	int sum = 0;
	for (int i=0; i<len; i++){
		sum += seq[i];
	}
	return sum;
}

int max_number(int seq[], int len){
    assert(seq);
	assert(len>0);
	int max = seq[0];
	for (int i=0; i<len; i++){
		if (max<seq[i]){
			max = seq[i];
		}
	}
	return max;
}

int min_number(int seq[], int len){
    assert(seq);
	assert(len>0);
	int min = seq[0];
	for (int i=0; i<len; i++){
		if (min>seq[i]){
			min = seq[i];
		}
	}
	return min;
}

int minmax_dist(int seq[], int len){
    assert(seq);
	assert(len>0);
	int min = min_number(seq, len);
	int max = max_number(seq, len);
	int minIndex = -1;
	int maxIndex = -1;
	for (int i=0; i<len; i++){
		if (seq[i] == min && minIndex == -1){
			minIndex = i;
		}
		if (seq[i] == max && maxIndex == -1){
			maxIndex = i;
		}
	}
	if (minIndex>=maxIndex){
		return minIndex-maxIndex;
	}
	else {
		return maxIndex-minIndex;
	}
}

float seq_avg(int seq[], int len){
    assert(seq);
	assert(len>0);
	return (float)number_sum(seq, len)/len;
}

bool seq_has_duplicates(int seq[], int len){
    assert(seq);
	assert(len>0);
	for (int i=0; i<len-1; i++){
		for (int i2=i+1; i2<len; i2++){
			if (seq[i]==seq[i2]){
				return true;
			}
		}
	}
	return false;
}

int seq_most_occurrences(int seq[], int len){
	assert(seq);
	assert(len>0);
	int count[len];
	for (int i=0; i<len; i++){
		count[i]=0;
	}
	for (int i=0; i<len-1; i++){
		for (int i2=i+1; i2<len; i2++){
			if (seq[i]==seq[i2]){
				count[i]++;
			}
		}
	}
	int max = max_number(count, len);
	for (int i=0; i<len-1; i++){
		if (count[i]==max){
			return seq[i];
		}
	}
	return 0;
}