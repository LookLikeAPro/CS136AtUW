// Jiayu Zhou
// CS136, Winter 2015
// Assignment 3, Problem 0a

//int num_digits(int i) returns the number of digits in the binary representation of integer i, not counting leading zeroes. 
//Requires: i >= 0 .
int num_digits(int i);

int power(int a, int b){
	if (b==0)
		return 1;
	if (b==1)
		return a;
	else
		return a*power(a, b-1);
}

int digitTest (int i, int d){
	if (i>=power(2,d))
		return digitTest(i,d+1);
	else
		return d;
}

int num_digits(int i){
	return digitTest(i,0);
}