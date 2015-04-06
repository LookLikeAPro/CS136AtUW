// Jiayu Zhou
// CS136, Winter 2015
// Assignment 9, Problem 1

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


// see list.h for documentation
struct llist *create_list(void) {
	struct llist *lst = malloc(sizeof(struct llist));
	lst->first = NULL;
	lst->last = NULL;
	lst->len=0;
 	return lst;
}

// see list.h for documentation
void destroy_list(struct llist *lst) {
	assert(lst);
	struct llnode *current = lst->first; 
	struct llnode *next;
	while (current != NULL) {
		next = current->next; // note the next pointer
		free(current); // delete the node
		current = next; // advance to the next node
	}
	free(lst); 
}


// see list.h for documentation
int list_length(struct llist *lst) {
  	assert(lst);
	return lst->len;
}


// see list.h for documentation
void print_list(struct llist *lst) {
  	assert(lst);
	struct llnode *current;
	for (current = lst->first; current != NULL; current = current->next)
		printf("  %d", current->item);
	printf("\n");
}

// see list.h for documentation
void add_first(int n, struct llist *lst){
	assert(lst);
	struct llnode *new = malloc(sizeof(struct llnode));
	new->item = n;
	new->next = lst->first;
	lst->first = new;
	if (lst->last == NULL){
		lst->last = new;
	}
	lst->len++;
}

// see list.h for documentation
void add_last(int n, struct llist *lst){
	assert(lst);
	struct llnode *new = malloc(sizeof(struct llnode));
	new->item = n;
	new->next = NULL;
	if (lst->last != NULL){
		lst->last->next = new;
		lst->last = new;
	}
	else{
		lst->first->next = new;
		lst->last = new;
	}
	lst->len++;
}

// see list.h for documentation
int delete_first(struct llist *lst){
	assert(lst);
	assert(lst->len>0);
	struct llnode *temp = lst->first->next;
	int returnInt = lst->first->item;
	free(lst->first);
	lst->first = temp;
	lst->len--;
	return returnInt;
}

// see list.h for documentation
int get_ith(struct llist *lst, int index){
	assert(lst);
	assert(lst->len>index);
	struct llnode *key = lst->first;
	for (int i=0; i<index; i++){
		key = key->next;
	}
	return key->item;
}

// see list.h for documentation
void insert_ith(struct llist *lst, int index, int data){
	assert(lst);
	assert(lst->len+1>index);
	struct llnode *prev = NULL;
	struct llnode *next = lst->first;
	for (int i=0; i<index; i++){
		prev = next;
		next = next->next;
	}
	struct llnode *new = malloc(sizeof(struct llnode));
	new->item = data;
	new->next = next;
	if (prev==NULL){
		lst->first = new;
	}
	else {
		prev->next = new;
	}
	if (lst->last == prev){
		lst->last = new;
	}
	lst->len++;
}

// see list.h for documentation
void lst_append(struct llist *lst1, struct llist *lst2){
	assert(lst1);
	assert(lst2);
	lst1->last->next = lst2->first;
	lst1->last = lst2->last;
	lst1->len += lst2->len;
	lst2->first = NULL;
	lst2->last = NULL;
	lst2->len = 0;
}

// see list.h for documentation
bool eq_list(struct llist *lst1, struct llist *lst2){
	assert(lst1);
	assert(lst2);
	if (lst1->len != lst2->len){
		return false;
	}
	struct llnode *node1 = lst1->first;
	struct llnode *node2 = lst2->first;
	for (int i=0; i<lst1->len; i++){
		if (node1->item!=node2->item){
			return false;
		}
		node1 = node1->next;
		node2 = node2->next;
	}
	return true;
}

// see list.h for documentation
int maxminlist(struct llist *lst, int *max, int *min){
	assert(lst);
	if (lst->len==0){
		return 0;
	}
	*min = lst->first->item;
	*max = lst->first->item;
	struct llnode *cur;
	for (cur = lst->first; cur!=NULL; cur = cur->next){
		if (cur->item<*min){
			*min = cur->item;
		}
		if (cur->item>*max){
			*max = cur->item;
		}
	}
	return 1;
}

// see list.h for documentation
void list_map( struct llist *lst, int (*function_ptr)(int) ){
	assert(lst);
	struct llnode *cur;
	for (cur = lst->first; cur!=NULL; cur = cur->next){
		cur->item = function_ptr(cur->item);
	}
}