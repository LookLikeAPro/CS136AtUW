// Jiayu Zhou
// CS136, Winter 2015
// Assignment 3, P0b

#include <stdbool.h>

//bool fequals(float a, float b) returns true if the two floats a and b are "almost equal" and the absolute difference between the two numbers is less than or equal to 0.00001
bool fequals(float a, float b);

bool fequals(float a, float b){
	if (a>b)
		return (a-b)<=0.00001;
	else
		return (b-a)<=0.00001;
}