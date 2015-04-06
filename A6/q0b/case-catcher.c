/*********************************************** 
 * Name: 
 * Student ID:
 * File: case-catcher.c 
 * CS 136 Winter 2015 - Assignment 6, Problem 0b
 * Description: 
***********************************************/

#include <stdbool.h>
#include <string.h>

bool is_proper_case(char str[]){
	for (int i=0; i<strlen(str); i++){
		if (str[i]=='.' && i<strlen(str)-1 && !(str[i+1]>='A' && str[i+1]<='Z')){
			return false;
		}
		if (str[i]>='A' && str[i]<='Z' && i!=0 && str[i-1]!='.'){
			return false;
		}
	}
	return true;
}
