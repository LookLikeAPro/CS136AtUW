
// Jiayu Zhou
// CS136, Winter 2015
// Assignment 3, Problem 4b

/* lcm(int a, int b) computes least common multiple of a and b
 * requires: a > 0, b > 0, least common multiple of a and b is < 2,147,483,648 (2^31) 
*/
int lcm(int a, int b);

int gcd(int a, int b){
	if (b==0)
		return a;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b){
	return a*b/gcd(a, b);
}
