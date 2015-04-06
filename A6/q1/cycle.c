/*********************************************** 
 * Name: Jiayu Zhou
 * Student ID: 20558469
 * File: cycle.c 
 * CS 136 Winter 2015 - Assignment 6, Problem 1
 * Description: 
***********************************************/

int count_cycles(int A[], int n){
	int current = 0;
	int new = 0;
	while (1){
		if (A[0]==0){
			return current;
		}
		else{
			new = ((A[current]+current)%n+n)%n;
			A[current]=0;
			current = new;
		}
	}
}