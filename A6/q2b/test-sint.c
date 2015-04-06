/*********************************************** 
 * Name: Jiayu Zhou
 * Student ID: 20558469
 * File: test-sint.c 
 * CS 136 Winter 2015 - Assignment 6, Problem 2
 * Description: 
***********************************************/

#include "sint.h"
#include <stdio.h>

int main(void) {
	char in = 0;
	int digit = 0;
	struct sint current;
	struct sint max;
	max.digits[0]=0;
	struct sint min;
	for (int i=0; i<51; i++){
		min.digits[i]='9';
	}
	struct sint acc;
	acc.digits[0]=0;
	
	while (scanf("%c", &in)!=EOF){
		if (in > '9' || in < '0'){
			current.digits[digit] = 0;
			acc = sadd(&current, &acc);
			if (scomp(&current, &max)==1) {
				max = current;
			}
			if (scomp(&min, &current)==1) {
				min = current;
			}
			digit = 0;
			for (int i=0; i<51; i++){
				current.digits[i]=0;
			}
		}
		else {
			current.digits[digit] = in;
			digit++;
		}
	}
	strim(&min);
	strim(&max);
	strim(&acc);
	printf("min:%s\n", min.digits);
	printf("max:%s\n", max.digits);
	printf("sum:%s\n", acc.digits);
}