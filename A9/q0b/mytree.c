// Jiayu Zhou
// CS136, Winter 2015
// Assignment 9, Problem 0b

#include <stdlib.h>
#include <stdio.h>

// You are not allowed to change structure definition

struct bstnode {
	int item;
	struct bstnode *left;
	struct bstnode *right;
};


// destroy_tree(t) frees all memory allocated for tree t
// effects: t is deallocated.
//   time: O(n) where n is the number of nodes in t
void destroy_tree(struct bstnode *t) {
	if (NULL == t) {return;}
	destroy_tree(t->left);
	destroy_tree(t->right);
	free(t);
}

// inorder_print(t) prints the values in t in certain order.
// effects: t is printed to the screen
//   time: O(n) where n is the number of nodes in t
void inorder_print(struct bstnode *t) {
	if (NULL == t) {return;}
	inorder_print(t->left);
	printf("  %d", t->item);
	inorder_print(t->right);
}

int main(void) {


  
  //YOUR CODE SHOULD BE ENTERED HERE
    struct bstnode *left = malloc(sizeof(struct bstnode));
    left->item = 20;
	left->left = NULL;
	left->right = NULL;
	struct bstnode *right = malloc(sizeof(struct bstnode));
	right->item = 78;
	right->left = NULL;
	right->right = NULL;
	struct bstnode *myt = malloc(sizeof(struct bstnode));
	myt->item = 35;
	myt->left = left;
	myt->right = right;
 
  inorder_print(myt);
  printf("\n");
  destroy_tree(myt);
  
}


