#include "readstr.h"
#include <stdio.h>
#include <stdlib.h>
// Jiayu Zhou
// CS136, Winter 2015
// Assignment 8, Problem 0d

char *readstr(void){
	char in;
	char *p = malloc(sizeof(char)*10000000);
	int count = 0;
	while (scanf("%c", &in)!=EOF && in!='\n'){
		p[count] = in;
		count++;
	}
	p[count]=0;
	p = realloc(p, sizeof(char)*(count+1));
	return p;
}