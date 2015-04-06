// Jiayu Zhou
// CS136 Winter 2015
// Assignment 7, Problem 0b

#include <assert.h>

void count_digits(int num){
    assert(num>0);
	for (int i=0; i<10; i++){
		int temp = num;
		int count = 0;
		while (temp>0){
			if (temp%10 == i){
				count++;
			}
			temp /= 10;
		}
		printf("The digit %d appears %d time(s) in %d\n", i, count, num);
	}
}
