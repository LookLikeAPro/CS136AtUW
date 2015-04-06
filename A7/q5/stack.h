/**
 * File: stack.h
 * provide functions to implement stack ADT
*/
#include <stdbool.h>

struct stack;

// create_stack() creates an empty stack;
//TIME: O(1)
struct stack *create_stack(void);

//destroy_stack(stk) destroys stack stk
// this function must be called when the user done using the stack
//requires: stk is a created stack
//TIME: O(n) where n is number of elements in stack
void destroy_stack(struct stack *stk);


//is_empty(stk) returns true if stk is an empty stack, false otherwise
//requires: stk is a valid stack
//TIME: O(1)
bool is_empty(struct stack *stk);


//(push(c, stk) pushes c to the top of stack stk
//requires: stk is a valid list
// TIME: O(1)
void push(char c, struct stack *stk);


//pop(stk) removes element from the top of stack stk and returns it
//requires: stk is a valid non empty stack
// TIME: O(1)
char pop(struct stack *stk);

