#include "set.h"
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 8, Problem 2

// see .h
struct set* new_set(int l) {
  struct set *result = malloc(sizeof(struct set));
  result->len = l;
  result->count = 0;
  result->data = malloc(sizeof(int) * l);
  return result;
}

// see .h
void free_set(struct set *s) {
  free(s->data);
  free(s);
}


// see.h
struct set* sym_diff(const struct set *s1, const struct set *s2) {
	assert(s1 && s2);
	struct set *p = new_set(s1->len+s2->len);
	int occurrence = 0;
	for (int i=0; i<s1->count; i++){
		for (int i2=0; i2<s2->count; i2++){
			if (s1->data[i] == s2->data[i2]){
				occurrence = 1;
			}
		}
		if (!occurrence){
			p->data[p->count] = s1->data[i];
			p->count++;
		}
		occurrence = 0;
	}
	for (int i=0; i<s2->count; i++){
		for (int i2=0; i2<s1->count; i2++){
			if (s2->data[i] == s1->data[i2]){
				occurrence = 1;
			}
		}
		if (!occurrence){
			p->data[p->count] = s2->data[i];
			p->count++;
		}
		occurrence = 0;
	}
	p->data = realloc(p->data, sizeof(int)*p->count);
	return p;
}