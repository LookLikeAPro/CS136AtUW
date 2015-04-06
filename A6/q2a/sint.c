/*********************************************** 
 * Name: Jiayu Zhou
 * Student ID: 20558469
 * File: sint.c 
 * CS 136 Winter 2015 - Assignment 6, Problem 2
 * Description: 
***********************************************/

#include "sint.h"
#include <assert.h>

int my_strlen(const char *s) {
	int len = 0;
	while (s[len]) {
		++len;
	}
	return len;
}

void strim(struct sint *a){
	assert(a);
	int leadingCount = 0;
	while (1){
		if (a->digits[leadingCount]!='0'){
			break;
		}
		leadingCount++;
	}
	for (int i=0; i<51-leadingCount; i++){
		a->digits[i] = a->digits[i+leadingCount];
	}
	int numberZero = 1;
	for (int i=0; i<51; i++){
		if (a->digits[i]>='1'&&a->digits[i]<='9'){
			numberZero = 0;
		}
		else if (a->digits[i]==0){
			break;
		}
	}
	if (numberZero == 1){
		a->digits[0] = '0';
		a->digits[1] = 0;
	}
}

int scomp(const struct sint *a, const struct sint *b){
	assert(a);
	assert(b);
	struct sint av = *a;
	struct sint bv = *b;
	strim(&av);
	strim(&bv);
	if (my_strlen(av.digits) > my_strlen(bv.digits)){
		return 1;
	}
	else if (my_strlen(av.digits) < my_strlen(bv.digits)) {
		return -1;
	}
	for (int i = 0; i<my_strlen(av.digits); i++){
		if (av.digits[i]>bv.digits[i]){
			return 1;
		}
		else if (av.digits[i]<bv.digits[i]){
			return -1;
		}
	}
	return 0;
}

struct sint sadd(const struct sint *a, const struct sint *b){
	assert(a);
	assert(b);
	struct sint av = *a;
	struct sint bv = *b;
	strim(&av);
	strim(&bv);
	
	struct sint c;
	int carry = 0;
	int add1 = 0;
	int offset = my_strlen(av.digits) - my_strlen(bv.digits);
	if (offset == 0 && av.digits[0]-48+bv.digits[0]-48>=10){
		add1 = 1;
	}
	if (my_strlen(av.digits)>=my_strlen(bv.digits)){
		for (int i=50; i>=0; i--) {
			bv.digits[i] = bv.digits[i-offset];
		}
		for (int i=0; i<offset; i++){
			bv.digits[i] = 48;
		}
	}
	else{
		for (int i=50; i>=0; i--) {
			av.digits[i] = av.digits[i+offset];
		}
		for (int i=0; i<-offset; i++){
			av.digits[i] = 48;
		}
	}
	for (int i = my_strlen(av.digits); i>=0; i--){
		if (av.digits[i]>='0' && av.digits[i]<='9' && bv.digits[i]>='0' && bv.digits[i]<='9'){
			c.digits[i] = ((av.digits[i]-48)+(bv.digits[i]-48)+carry)%10+48;
			carry = ((av.digits[i]-48)+(bv.digits[i]-48))/10;
		}
	}
	if (my_strlen(av.digits)>=my_strlen(bv.digits)){
		if (add1){
			for (int i=50; i>0; i--){
				c.digits[i] = c.digits[i-1];
			}
			c.digits[0] = 49;
			c.digits[my_strlen(av.digits)+1]=0;
		}
		else {
			c.digits[my_strlen(av.digits)]=0;
		}
	}
	else{
		if (add1){
			for (int i=50; i>0; i--){
				c.digits[i] = c.digits[i-1];
			}
			c.digits[0] = 49;
			c.digits[my_strlen(bv.digits)+1]=0;
		}
		else {
			c.digits[my_strlen(bv.digits)]=0;
		}
	}
	return c;
}