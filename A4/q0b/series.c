
// Jiayu Zhou
// CS136, Winter 2015
// Assignment 4, Problem 0b

//int series(int n) returns the nth number (1 <= n <= 100) of the series: (1, 4, 10, 19, 31, ...)
//Requires:  1 <= n <= 100
int series(int n){
	if (n==1)
		return 1;
	else 
		return 3*(n-1)+series(n-1);
}