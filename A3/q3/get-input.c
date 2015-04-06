#include "get-input.h"

// Note: you may not use arrays on this assignment but we will get to them soon
// You can change the characters in input for your own testing
char input[25] = {'F', 'F', 'L', 'F', 'B', 'L', 'l', 'f'};

int idx = 0;

char get_character(void) {
   return input[idx++];
}


