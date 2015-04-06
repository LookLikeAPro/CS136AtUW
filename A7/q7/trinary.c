#include "trinary.h"
#include <stdio.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 7, Problem 7

void trinary_search(int *a, int n, int v) {
	int indS = -1;
	int indE = n;
	int ind1;
	int ind2;
	int remain;
	int size;
	int comparisons = 0;
	int location = -1;
	while (1){
		if (indE - indS - 1 <=4){
			for (int i=0; i<indE - indS - 1; i++){
				comparisons++;
				printf("Checking if %d is equal to %d\n", v, a[indS + 1 + i]);
				if (v == a[indS + 1 + i]){
					location = indS + 1 + i;
					break;
				}
			}
			break;
		}
		else {
			n = indE - indS - 3;
			remain = n%3;
			size = n/3;
			ind1 = indS + 1 + size;
			ind2 = indS + 1 + 2*size+1;
			if (remain == 1){
				ind1++;
				ind2++;
			}
			else if (remain ==2){
				ind1++;
				ind2+=2;
			}
			if (a[ind1]==v){
				printf("Checking if %d is equal to %d\n", v, a[ind1]);
				comparisons++;
				location = ind1;
				break;
			}
			else if (v < a[ind1]){
				printf("Checking if %d is equal to %d\n", v, a[ind1]);
				printf("Checking if %d is less than %d\n", v, a[ind1]);
				comparisons += 2;
				indE = ind1;
			}
			else if (a[ind2] == v){
				printf("Checking if %d is equal to %d\n", v, a[ind1]);
				printf("Checking if %d is less than %d\n", v, a[ind1]);
				printf("Checking if %d is equal to %d\n", v, a[ind2]);
				comparisons += 3;
				location = ind2;
				break;
			}
			else if (v < a[ind2]){
				printf("Checking if %d is equal to %d\n", v, a[ind1]);
				printf("Checking if %d is less than %d\n", v, a[ind1]);
				printf("Checking if %d is equal to %d\n", v, a[ind2]);
				printf("Checking if %d is less than %d\n", v, a[ind2]);
				comparisons += 4;
				indS = ind1;
				indE = ind2;
			}
			else {
				printf("Checking if %d is equal to %d\n", v, a[ind1]);
				printf("Checking if %d is less than %d\n", v, a[ind1]);
				printf("Checking if %d is equal to %d\n", v, a[ind2]);
				printf("Checking if %d is less than %d\n", v, a[ind2]);
				comparisons += 4;
				indS = ind2;
			}
		}
	}
	if (location != -1){
		printf("Search successful\n");
		printf("%d is located at index %d\n", v, location);
	}
	else {
		printf("Search not successful\n");
	}
	printf("A total of %d comparisons were made\n", comparisons);
}