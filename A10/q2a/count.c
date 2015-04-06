#include "count.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 10, Problem 2

struct count {
	int occurrences[100];
};


//See interface for documentation
Count create_Count(void){
	Count c = malloc(sizeof(struct count));
    for (int i=0; i<100; i++){
        c->occurrences[i]=0;
    }
	return c;
}

void destroy_Count(Count c){
	assert(c);
	free(c);
}

void next(Count c, int i){
	assert(c);
	assert(1<=i && i<=100);
	c->occurrences[i]++;
}

int total(Count c){
	assert(c);
	int acc = 0;
	for (int i=0; i<100; i++){
		acc += c->occurrences[i];
	}
	return acc;
}

int unique(Count c){
	assert(c);
	int acc = 0;
	for (int i=0; i<100; i++){
		if (c->occurrences[i]>0){
			acc++;
		}
	}
	return acc;
}

int count(Count c, int i){
	assert(c);
	assert(1<=i && i<=100);
	return c->occurrences[i];
}

int mostfreq(Count c){
	assert(c);
	assert(total(c)>0);
	int max = c->occurrences[0];
	for (int i=0; i<100; i++){
		if (c->occurrences[i]>max){
			max = c->occurrences[i];
		}
	}
	for (int i=0; i<100; i++){
		if (c->occurrences[i]==max){
			return i;
		}
	}
	return -1;
}

void stats(Count c){
	assert(c);
	for (int i=0; i<100; i++){
		if (c->occurrences[i]>0){
			printf("%d: %d\n", i, count(c,i));
		}
	}
}
