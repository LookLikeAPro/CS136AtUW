#include "reservation.h"
#include <assert.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 8, Problem 0c

struct manifest *create_manifest(int num_fc, int num_ec){
	assert(num_fc >= 0 && num_ec >= 0 && num_fc + num_ec > 0);
	struct manifest *p = malloc(sizeof(struct manifest));
	p->num_fc = num_fc;
	p->num_ec = num_ec;
	p->seats = calloc(num_ec+num_fc, sizeof(bool));
	return p;
}

void destroy_manifest(struct manifest *m){
    assert(m);
	free(m->seats);
	free(m);
}