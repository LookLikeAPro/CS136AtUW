#include "aos.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 8, Problem 4

char *my_strdup(const char *s){
	char *new = malloc(sizeof(char) * (strlen(s)+1));
	strcpy(new, s);
	return new;
}

struct aos *create_aos(int max){
	assert(max>0);
	struct aos *p = malloc(sizeof(struct aos));
	p->strings = malloc(sizeof(char *) * max);
	for (int i=0; i<max; i++){
		p->strings[i] = NULL;
	}
	p->max = max;
	return p;
}

void destroy_aos(struct aos *a){
	assert(a);
	for (int i=0; i<a->max; i++){
		free(a->strings[i]);
	}
	free(a->strings);
	free(a);
}

int aos_count(struct aos *a){
	assert(a);
	int count = 0;
	for (int i=0; i<a->max; i++){
		if (a->strings[i]){
			count++;
		}
	}
	return count;
}

char *aos_get(struct aos *a, int i){
	assert(a);
	if (i<0 || i>a->max){
		return NULL;
	}
	else if (a->strings[i]){
		return a->strings[i];
	}
	else {
		return NULL;
	}
}

void aos_set(struct aos *a, const char *s, int i){
	assert(a);
	assert(0<=i && i<a->max);
	if (s){
		a->strings[i] = my_strdup(s);
	}
	else {
		a->strings[i] = NULL;
	}
}

int aos_add(struct aos *a, const char *s){
	assert(a);
	assert(s);
	for (int i=0; i<a->max; i++){
		if (a->strings[i] == NULL){
			a->strings[i] = my_strdup(s);
			return 0;
		}
	}
	return -1;
}

void aos_sort(struct aos *a){
	assert (a);
	char *t = "";
	int minIndex = 0;
	for (int i=0; i<a->max; i++) {
		minIndex = i;
		for (int i2=i; i2<a->max; i2++){
			if (a->strings[i2]!=NULL){
				if (a->strings[minIndex] == NULL || strcmp(a->strings[minIndex], a->strings[i2])>0){
					minIndex = i2;
				}
			}
		}
		t = a->strings[minIndex];
		a->strings[minIndex] = a->strings[i];
		a->strings[i] = t;
	}
}