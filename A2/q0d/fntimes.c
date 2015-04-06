// Your Name
// CS136 WInter 2015
// Assignment 2, Problem 0d
#include <stdio.h>
#include <assert.h>
//fntimes(const int a, const int b) returns a * b.
//requires: b is not negative
int fntimes(const int a, const int b){
	if (b==0)
        return 0;
    else if (b<=1)
		return a;
	else
		return a+fntimes(a, b-1);
}