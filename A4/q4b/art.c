#include "art.h"
#include <stdio.h>
/*
 * Copy your art.c module from Problem 4a here!
 */
void print_char(struct shape *ps, int row, int col, int size){
	if (ps->type=='A'){
		if (row==col)
			printf("%c", ps->diag);
		else if (row<col)
			printf("%c", ps->upper);
		else if (row>col)
			printf("%c", ps->lower);
	}
	else if (ps->type=='B'){
		if (row+col==size-1)
			printf("%c", ps->diag);
		else if (row+col<size-1)
			printf("%c", ps->upper);
		else if (row+col>size-1)
			printf("%c", ps->lower);
	}
}

void ascii_shape(struct shape *ps1, struct shape *ps2, int size){
	for (int i=0; i<size; i++){
		for (int i2=0; i2<size*2; i2++){
			if (i2<size){
				print_char(ps1, i, i2, size);
			}
			else{
				print_char(ps2, i, i2-size, size);
			}
		}
		printf("\n");
	}
}