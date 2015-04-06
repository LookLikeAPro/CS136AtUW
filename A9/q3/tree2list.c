#include "tree2list.h"
#include <stdlib.h>
#include <stdio.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 9, Problem 3

void connect(struct node *lst1, struct node *lst2){
	struct node *cur;
	for (cur=lst1; cur->right!=NULL; cur=cur->right){
	}
	cur->right = lst2;
	lst2->left = cur;
}

struct node *tree2list_helper(struct node *node) {
	if (node){
		struct node *left = tree2list_helper(node->left);
	    struct node *right = tree2list_helper(node->right);
        if (left && right){
            connect(left, node);
            return left;
        }
        else if (left){
            connect(left, node);
            return left;
        }
        else if (right){
            connect(node, right);
            return node;
        }
        else{
            return node;
        }
	}
	else {
		return NULL;
	}
}

struct node *tree2list(struct node *root) {
    return tree2list_helper(root);
}