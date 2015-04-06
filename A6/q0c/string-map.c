/*********************************************** 
 * Name: Jiayu Zhou
 * Student ID: 20558469
 * File: string-map.c 
 * CS 136 Winter 2015 - Assignment 6, Problem 0c
 * Description: 
***********************************************/

#include <string.h>

void array_map (char (*f)(char), char a[], int len){
	for (int i=0; i<len; i++){
		a[i] = f(a[i]);
	}
}

void string_map(char *str, char (*proc)(char)){
	array_map(proc , str, strlen(str));
}