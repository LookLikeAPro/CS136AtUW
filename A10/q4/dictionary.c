#include <stdlib.h>
#include <assert.h>
#include "dictionary.h"

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 10, Problem 4

struct node {
	void *key;
	void *val;
	struct node *left;
	struct node *right;
};

struct dictionary{
	int (*comp_k)(const void *, const void *);
	void (*free_v)(void *);
	void (*free_k)(void *);
	struct node *root;
};

// See documentation in interface
Dictionary create_Dictionary(CompareFunction comp_k, FreeFunction free_k, FreeFunction free_v){
	assert(comp_k);
	assert(free_k);
	assert(free_v);
	Dictionary dict = malloc(sizeof(struct dictionary));
	dict->comp_k = comp_k;
	dict->free_k = free_k;
	dict->free_v = free_v;
	dict->root = NULL;
	return dict;
}


// destroy_Dictionary_helper(n, free_k, free_v): 
//   Frees all memory allocated for node, 
//    and all connected leaf nodes
//   requires: n is not NULL, 
//             free_k and free_v free memory of key and value of node
//   effects: all nodes under n become NULL
//   time: O(n * f), where n is the number of items under node, 
//         f is time to free key & value
void destroy_Dictionary_helper(struct node *n, FreeFunction free_k, FreeFunction free_v){
	if (n){
		if (n->left){
			destroy_Dictionary_helper(n->left, free_k, free_v);
		}
		if (n->right){
			destroy_Dictionary_helper(n->right, free_k, free_v);
		}
		free_k(n->key);
		free_v(n->val);
        free(n);
	}
}

void destroy_Dictionary(Dictionary dict){
	assert(dict);
	destroy_Dictionary_helper(dict->root, dict->free_k, dict->free_v);
	free(dict);
}

void insert(Dictionary dict, void *k, void *v){
	assert(dict);
	assert(k);
	assert(v);
	struct node *cur = dict->root;
	struct node *prev = NULL;
	int compareResult = 0;
	while (cur){
		prev = cur;
		compareResult = dict->comp_k(cur->key, k);
		if (compareResult==0){
			free(cur->val);
			cur->val = v;
			return;
		}
		else if (compareResult>0){
			cur = cur->right;
		}
		else if (compareResult<0){
			cur = cur->left;
		}
	}
	struct node *new = malloc(sizeof(struct node));
	new->key = k;
	new->val = v;
	new->left = NULL;
	new->right = NULL;
	if (prev){
		if (compareResult>0){
			prev->right = new;
		}
		else if (compareResult<0){
			prev->left = new;
		}
	}
	else {
		dict->root = new;
	}
}

void *lookup(Dictionary dict, void *k){
	assert(k);
	assert(dict);
	struct node *cur = dict->root;
	while (1){
		if (cur){
			int compareResult = dict->comp_k(cur->key, k);
			if (compareResult==0){
				return cur->val;
			}
			else if (compareResult>0){
				cur = cur->right;
			}
			else if (compareResult<0){
				cur = cur->left;
			}
		}
		else {
			return NULL;
		}
	}
}
