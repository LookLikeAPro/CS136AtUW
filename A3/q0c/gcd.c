// Jiayu Zhou
// CS136, Winter 2015
// Assignment 3, P0c

//int gcd(int a, int b) returns the greatest common divisor for the integers a and b.
int gcd(int a, int b);

int gcd(int a, int b){
	if (b==0)
		return a;
	else
		return gcd(b, a%b);
}
