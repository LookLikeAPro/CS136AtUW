#include <stdlib.h>
#include <stdio.h>
// Jiayu Zhou
// CS136, Winter 2015
// Assignment 8, Problem 3

int main(void) {
    int in = 0;
	int *array = malloc(sizeof(int));
	int count = 0;
	while (scanf("%d", &in)!=EOF){
		array = realloc(array, sizeof(int)*(count+1));
		array[count] = in;
		count++;
	}
	for (int i=0; i<count-1; i++){
		if (array[i]<array[count-1]){
			printf("%d\n", array[i]);
		}
	}
    free(array);
}
