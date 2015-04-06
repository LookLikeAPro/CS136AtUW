// Jiayu Zhou
// CS136, Winter 2015
// Assignment 8, Problem 0a

char *my_strdup(const char *s){
	char *new = malloc(sizeof(char) * (strlen(s)+1));
	strcpy(new, s);
	return new;
}
