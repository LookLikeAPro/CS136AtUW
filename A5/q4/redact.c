// Jiayu Zhou
// CS136, Winter 2015
// Assignment 5, Problem 4

#include <stdio.h>

int main(void) {
    char in;
	int original = 0;
	while (scanf("%c", &in)!= EOF){
		if (original){
			printf("%c", in);
			original = 0;
		}
		else if (in>=65 && in<=90){
			printf("%c", in);
		}
		else if (in>=97 && in<=122){
			printf("%c", in-32);
		}
		else if (in>=48 && in<=57){
			printf("*");
		}
		else if (in == '"'){
			printf("'");
		}
		else if (in == '\\'){
			original = 1;
		}
		else {
			printf("%c", in);
		}
	}
}
