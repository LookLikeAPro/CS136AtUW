// Jiayu Zhou
// CS136, Winter 2015
// Assignment 5, Problem 0d

struct posn { int x; int y; };

// getpos(p) reads in two integers and stores them in p->x and p->y
// requires: p is not NULL
void getpos(struct posn *p){
	scanf("%d%d", &p->x, &p->y);
}

