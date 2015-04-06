
// Jiayu Zhou
// CS136, Winter 2015
// Assignment 4, Problem 0a

//int collatz_count(int n) returns the count of Collatz conjecture done on n to obtain 1
//Requires: n>=1
int collatz_count(int n){
	if (n==1)
		return 0;
	else if (n%2==0)
		return 1+collatz_count(n/2);
	else
		return 1+collatz_count(n*3+1);
}
