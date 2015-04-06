
// Jiayu Zhou
// CS136, Winter 2015
// Assignment 3, Problem 2

// int common_bits(int a, int b) returns the number of bits in which the binary representations of a and b have in common
// requires: a >= 0, b >= 0
int common_bits(int a, int b);

int power(int a, int b){
	if (b==0)
		return 1;
	if (b==1)
		return a;
	else
		return a*power(a, b-1);
}

int get_digit(int a, int d){
	if (a%power(2,d)-a%power(2,d-1)==0)
		return 0;
	else
		return 1;
}

int compare_bit(int a, int b, int i){
	if (power(2, i-1)>a || power(2, i-1)>b)
		return 0;
	else if (get_digit(a, i)==get_digit(b, i))
		return 1+compare_bit(a, b, i+1);
	else
		return compare_bit(a, b, i+1);
}

int common_bits(int a, int b){
	return compare_bit(a, b, 1);
}