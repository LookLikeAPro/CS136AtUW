/*********************************************** 
 * Jiayu Zhou
 * Student ID:
 * File: count-pos.c 
 * CS 136 Winter 2015 - Assignment 6, Problem 0a
 * Description: 
***********************************************/

int count_pos(int a[], int len){
	int count = 0;
	for (int i = 0; i<len; i++){
		if (a[i]>0){
			count++;
		}
	}
	return count;
}