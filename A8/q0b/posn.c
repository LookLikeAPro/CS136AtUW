#include "posn.h"
#include <stdlib.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 8, Problem 0b

struct posn *make_posn(int x, int y){
	struct posn *p = malloc(sizeof(struct posn));
    p->x = x;
	p->y = y;
	return p;
}