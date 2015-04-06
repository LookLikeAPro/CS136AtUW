// Jiayu Zhou
// CS136, Winter 2015
// Assignment 5, Problem 3

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	srand(1234);
	int y, z;
	int in;
	int errorCount = 0;
	int correctCount = 0;
	int try = 0;
	int askContinue = 0;
	int newQuestion = 1;
	while (1){
		if (newQuestion){
			y = rand()%10+1;
			z = rand()%10+1;
			newQuestion = 0;
		}
		printf("%d X %d = ", y, z);
		scanf("%d", &in);
        printf("%d\n", in);
		if (y*z == in){
			int m = rand()%3;
			if (m == 0){
				printf("Give me five!\n");
			}
			else if (m == 1){
				printf("Keep up the good work!\n");
			}
			else if (m == 2){
				printf("Way to go!\n");
			}
			askContinue = 1;
			correctCount++;
            try = 0;
		}
		else if (try == 0){
			int m = rand()%3;
			if (m == 0){
				printf("Incorrect.\n");
			}
			else if (m == 1){
				printf("That is not right.\n");
			}
			else if (m == 2){
				printf("That is wrong.\n");
			}
			printf("Try again: ");
			newQuestion = 0;
			try = 1;
		}
		else {
			printf("Sorry. The correct answer is %d X %d = %d\n", y, z, y*z);
			errorCount++;
			askContinue = 1;
			try = 0;
		}
		if (askContinue == 1){
			printf("Would you like to continue (y/n)? ");
			char c;
			while (1){
				scanf("%c", &c);
                if (c == 'y' || c== 'n'){
                    printf("%c\n", c);
					break;
                }
			}
			if (c == 'y'){
				askContinue = 0;
				newQuestion = 1;
			}
			else {
				break;
			}
		}
	}
	printf("----- Session Summary -----\n");
	printf("Correct answers: %d\n", correctCount);
	printf("Incorrect answers: %d\n", errorCount);
	printf("Percentage correct: %.2f%%\n", (float)correctCount/(correctCount+errorCount)*100);
}
