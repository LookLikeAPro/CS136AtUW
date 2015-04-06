// Jiayu Zhou
// CS136, Winter 2015
// Assignment 9, Problem 2

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "bst.h"

// see bst.h documentation
struct bsttree *create_bst(void) {
	struct bsttree *tree = malloc(sizeof(struct bsttree));
	tree->root = NULL;
	return tree;
}


// see bst.h documentation
void destroy_tree(struct bstnode *node) {
	if (NULL == node) {return;}
	destroy_tree(node->left);
	destroy_tree(node->right);
	free(node);
}


// see bst.h documentation
void destroy_bst(struct bsttree *t){
   assert(t);
   destroy_tree(t->root);
   free(t);
}


// see bst.h documentation
struct bstnode *make_bstnode(int val, struct bstnode *l, struct bstnode *r) {
	struct bstnode *new = malloc(sizeof(struct bstnode));
	new->item = val;
	new->left = l;
	new->right = r;
	return new;
}


// see bst.h documentation
bool is_bstempty(struct bsttree *t){
	assert(t);
	return (NULL == t->root);
}


// see bst.h documentation
void inorder_node(struct bstnode *node) {
	if (NULL == node) {return;}
	inorder_node(node->left);
	printf("  %d", node->item);
	inorder_node(node->right);
}

// see bst.h documentation
void traverse_inorder(struct bsttree *t){
	assert(t);
	inorder_node(t->root);
	printf("\n");
}

// is_bst_helper(n) returns true if t is a valid node of BST
//  (meaning it obeys the ordering property), otherwise false
// time: O(n) where n is the number of nodes in n
bool is_bst_helper(struct bstnode *n){
	if (n == NULL){
		return true;
	}
	if (n->left && n->left->item>n->item){
		return false;
	}
	if (n->right && n->right->item<n->item){
		return false;
	}
	return (is_bst_helper(n->left) && is_bst_helper(n->right));
}

// see bst.h documentation
bool is_bst(struct bsttree *t){
	assert(t);
	return is_bst_helper(t->root);
}


//see bst.h documentation
void bst_insert(int val, struct bsttree *t){
	struct bstnode *cur = t->root;
	struct bstnode *prev = NULL;
	while (cur){
		if (val > cur->item){
			prev = cur;
			cur = cur->right;
		}
		else if (val < cur->item){
			prev = cur;
			cur = cur->left;
		}
		else{
			break;
		}
	}
	cur = make_bstnode(val, NULL, NULL);
	if (prev){
		if (prev->item>cur->item){
			prev->left = cur;
		}
		else if (prev->item<cur->item){
			prev->right = cur;
		}
	}
	else{
		t->root = cur;
	}
}


//see bst.h documentation
bool bst_search(struct bsttree *t, int val){
	struct bstnode *cur = t->root;
	while (cur){
		if (cur->item > val){
			cur = cur->left;
		}
		else if (cur->item < val){
			cur = cur->right;
		}
		else{
			return true;
		}
	}
	return false;
}


// bst_height_helper(n) returns the height of nodes n. 
//      If n is an empty node then its height is 0, 
//      if n is a node with leaf nodes, its hhas height bigger than 1.
//  time: O(n), where n is the number of nodes in n
int bst_height_helper (struct bstnode *n){
	if (!n){
		return 0;
	}
	int leftlevel = 1 + bst_height_helper(n->left);
	int rightlevel = 1 + bst_height_helper(n->right);
	if (leftlevel>rightlevel){
		return leftlevel;
	}
	else{
		return rightlevel;
	}
}

// see bst.h documentation
int bst_height(struct bsttree *t){
	assert(t);
	return bst_height_helper(t->root);
}

// mirror(n) 
/* 
 Changes the nodes under n so that the roles of the 
 left and right pointers are swapped at every node.
 So the tree... 
       4 
      / \ 
     2   5 
    / \ 
   1   3

 is changed to... 
       4 
      / \ 
     5   2 
        / \ 
       3   1 
*/ 
// time: O(n) where n is the number of nodes in n.
void mirror_helper(struct bstnode *n){
	if (n){
		struct bstnode *temp = n->left;
		n->left = n->right;
		n->right = temp;
		mirror_helper(n->left);
		mirror_helper(n->right);
	}
}

// see bst.h documentation
void mirror(struct bsttree *t){
	assert(t);
	mirror_helper(t->root);
}
 


