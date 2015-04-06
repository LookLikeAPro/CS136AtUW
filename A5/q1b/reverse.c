// Jiayu Zhou
// CS136, Winter 2015
// Assignment 5, Problem 1b

int reverse(const int a){
	int b = 0;
	int acon = a;
	while (acon*10>9){
		b *= 10;
		b += acon%10;
		acon /= 10;
	}
	return b;
}