
// Jiayu Zhou
// CS136, Winter 2015
// Assignment 3, Problem 4a

// avg2(int a, int b) computes the average of a and b, rounded down
// requires: a >= 0, b >= 0
int avg2(int a, int b);

// avg3(int a, int b, int c) computes the average of a, b and c, rounded down
// requires: a >= 0, b >= 0, c >= 0
int avg3(int a, int b, int c);


int avg2(int a, int b){
	return (a+b)/2;
}

int avg3(int a, int b, int c){
	return (a+b+c)/3;
}