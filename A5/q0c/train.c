/*
A simple program that draws an ASCII train
*/
#include <stdio.h>

int digits(int n){
	int i = 10;
	int count = 1;
	while (n/i>=1){
		i *= 10;
		count ++;
	}
	return count;
}

int main(void)
{
    int n1,n2, n3;
    scanf("%d%d%d", &n1, &n2, &n3);
	printf("\n");
	printf("     oO                            \n");
	printf("    o   +---+                      \n");
	printf("   H____|___|  _______   _______   \n");
	printf("  |");
    for (int i =0; i<8-digits(n1); i++){
        printf(" ");
    }
    printf("%d | |", n1);
    for (int i =0; i<6-digits(n2); i++){
        printf(" ");
    }
    printf("%d | |", n2);
    for (int i =0; i<6-digits(n3); i++){
        printf(" ");
    }
    printf("%d |  \n", n3);
	printf("  |_________|=|_______|=|_______|  \n");
	printf("   -O-----O-   -O---O-   -O---O-   \n\n");
}
