
// Jiayu Zhou
// CS136, Winter 2015
// Assignment 3, Problem 5

//find_root takes the coefficients a,b,c of a quadratic equation and an interval (p, q). It will return the root of this equation in the given interval. 
//Requires: exactly one root in the given interval. Initially f(p) != 0 and f(q) != 0. 
float find_root(float a, float b, float c, float p, float q);

float find_root(float a, float b, float c, float p, float q){
	float x = (p + q)/2;
	float y = a*x*x + b*x + c;
	float y1 = a*p*p + b*p + c;
	if (y<0.00001 && y>-0.00001)
		return x;
	else if ((y/y1)<0)
		return find_root(a, b, c, p, x);
	else
		return find_root(a, b, c, x, q);
}