#include "strfilter.h"
#include <assert.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 8, Problem 1

void strfilter(char s[], bool (*f)(char c)){
	assert(s);
	int i=0;
	int count=0;
	while (s[i]!=0){
		if(f(s[i])){
			s[count] = s[i];
			count++;
		}
		i++;
	}
	s[count]=0;
}