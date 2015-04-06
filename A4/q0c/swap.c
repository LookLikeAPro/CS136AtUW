
// Jiayu Zhou
// CS136, Winter 2015
// Assignment 4, Problem 0c

struct posn { int x; int y; };

//void swap(struct posn *p, struct posn *q) swaps the fields p and q in the two structures struct posn { int x; int y; };
void swap(struct posn *p, struct posn *q){
	int xKey = q->x;
	int yKey = q->y;
	q->x = p->x;
	q->y = p->y;
	p->x = xKey;
	p->y = yKey;
}