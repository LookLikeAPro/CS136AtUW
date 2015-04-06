// Jiayu Zhou
// CS136, Winter 2015
// Assignment 7, Problem 5

#include "stack.h"
#include <stdio.h>
#include <assert.h>

int main(void) {
	char in;
	int step = 0;
    char current;
    int level11 = 0;
    int level12 = 0;
    int level13 = 0;
    int level21 = 0;
    int level22 = 0;
    int level23 = 0;
    int level31 = 0;
    int level32 = 0;
    int level33 = 0;
    int valid = 1;
	while (1){
		printf("Would you like to enter an expression?\n");
		while (scanf("%c", &in)!=EOF){
			if (in == 'y' || in=='Y'){
				step = 2;
				break;
			}
			else if (in == 'n' || in=='N'){
				step = 5;
				break;
			}
            else if (in == '\n'){
            }
			else {
				printf("Wrong answer! Let us try again.\n");
                printf("Would you like to enter an expression?\n");
			}
		}
        while(getchar() != '\n')
            continue;
		if (step == 5){
			printf("GOOD BYE!!!\n");
			break;
		}
		else if (step == 2){
			printf("Enter expression to check:\n");
            struct stack *st = create_stack();
            assert(is_empty(st));
			while (scanf("%c", &in)!=EOF && in!='\n'){
                if (in=='(' || in==')' || in=='{' || in=='}' || in=='[' || in==']'){
				    push(in,st);
                }
			}
            valid = 1;
            while (!is_empty(st) && valid){
                current = pop(st);
                if (current == '}'){
                    level11++;
                    level12 = level21;
                    level13 = level31;
                }
                else if (current == ']'){
                    level21++;
                    level22 = level11;
                    level23 = level31;
                }
                else if (current == ')'){
                    level31++;
                    level32 = level11;
                    level33 = level21;
                }
                else if (current == '{'){
                    level11--;
                    if (level12!= level21 || level13!=level31){
                        valid = 0;
                    }
                }
                else if (current == '['){
                    level21--;
                    if (level22!= level11 || level23!=level31){
                        valid = 0;
                    }
                }
                else if (current == '('){
                    level31--;
                    if (level32!= level11 || level33!=level21){
                        valid = 0;
                    }
                }
            }
            destroy_stack(st);
            if (level11+level21+level31!=0){
                valid = 0;
            }
            if (valid){
                printf("Balanced parentheses expression\n");
            }
            else {
                printf("Non-balanced parentheses expression\n");
            }
            
		}
	}
}
