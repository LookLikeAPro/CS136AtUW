
// Jiayu Zhou
// CS136, Winter 2015
// Assignment 3, Problem 1

// char_offset(c1, c2) determines the absolute offset between letters c1 and c2 or -1 otherwise.
int char_offset(char c1, char c2);

int char_offset(char c1, char c2){
	if (c1<97)
		c1+=32;
	if (c2<97)
		c2+=32;
	if (c1>=97 && c2>=97 && c1<=122 && c2<=122){
		if (c1>c2)
			return c1-c2;
		else 
			return c2-c1;
	}
	else return -1;
}