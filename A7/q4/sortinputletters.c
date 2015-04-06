// Jiayu Zhou
// CS136, Winter 2015
// Assignment 7, Problem 4

#include <stdio.h>

void sort_input_letters(void){
	char in;
	int array[52];
	for (int i=0; i<52; i++){
		array[i] = 0;
	}
	while (scanf("%c", &in)!=EOF){
		if (in >='a' && in<='z'){
			array[in-71]++;
		}
		else if (in >='A' && in<='Z'){
			array[in-65]++;
		}
	}
	for (int i=0; i<26; i++){
		for (int i2=0; i2<array[i]; i2++){
			printf("%c", i+65);
		}
	}
	for (int i=26; i<52; i++){
		for (int i2=0; i2<array[i]; i2++){
			printf("%c", i+71);
		}
	}
}