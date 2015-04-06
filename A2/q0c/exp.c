// Your Name
// CS136 Winter 2015
// Assignment 2, Problem 0c

int exponent(const int a, const int b){
	if (b==1){
		return a;
	}
	else 
		return a * exponent(a, b - 1);
}
