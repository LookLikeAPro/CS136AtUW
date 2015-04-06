// Your Name
// CS136 Winter 2015
// Assignment 2, Problem 1

//countOccurrence (int a, int b, int base, int exp, int adder, 
//int addAmount) returns a Natural number such that b^number = a, 
//if a is some power of b. Otherwise it returns 0

int countOccurrence (int a, int b, int base, int exp, int adder, int addAmount){
	if (a<b)
		return 0;
	else if (a==b){
		return exp;
	}
	else if (adder == base)
		return countOccurrence(a, b, base, exp+1, 1, b);
	else{
		return countOccurrence(a, b+addAmount, base, exp, adder+1, addAmount);
	}
}

//is_apowb(int a, int b) returns a Natural number such that 
//b^number = a, if a is some power of b. Otherwise it returns 0
int is_apowb(int a, int b) {
	if (a!=1 && b==1)
		return 0;
	else if (a == b)
		return 1;
	else 
		return countOccurrence (a, b, b, 2, 1, b);
}