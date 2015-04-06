// Jiayu Zhou
// CS136, Winter 2015
// Assignment 9, Problem 0a

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// You are not allowed to change structure definition

struct lnode {
	int item;
	struct lnode *next;
};

// destroy_list(lst) frees all memory allocated for lst
// requires: lst is not NULL
// effects: lst is deallocated
//   time: O(n) where n is the length of lst
void destroy_list(struct lnode *lst) {
      assert(lst);
	struct lnode *next;
	while (lst != NULL) {
		next = lst->next;  // note the next pointer
		free(lst);         // delete the node
		lst = next;        // advance to the next node
	}
}	


// print_list(lst) prints the items in the list lst 
// requires: lst is not NULL
// effects: lst is printed to the screen
//   time: O(n) where n the length of lst
void print_list(struct lnode *lst) {
	struct lnode *current;
	for (current = lst; current != NULL; current = current->next) {
		printf("  %d", current->item);
  }
	printf("\n");
}


int main(void)
{
   
	
  // YOU CODE SHOULD BE ADDED HERE
  struct lnode *myl = NULL;
	for (int i=1; i<=10; i++){
		struct lnode *temp = malloc(sizeof(struct lnode));
		temp->item = i;
		temp->next = myl;
		myl = temp;
	}
  print_list(myl);
  destroy_list(myl);
  return 0;
}



