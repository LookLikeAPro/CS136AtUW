#include "count.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 10, Problem 2

struct node {
	int item;
	int occurrence;
	struct node *next;
};

struct count {
	struct node *first;
};

//Documentation in interface
Count create_Count(void){
	Count c = malloc(sizeof(struct count));
	c->first = NULL;
	return c;
}

void destroy_Count(Count c){
	assert(c);
	struct node *cur = c->first;
	struct node *prev = NULL;
	while(cur){
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	free(c);
}

void next(Count c, int i){
	assert(c);
	struct node *cur = c->first;
	struct node *prev = NULL;
	while (cur){
		if (cur->item == i){
			cur->occurrence++;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	struct node *new = malloc(sizeof(struct node));
	new->item = i;
	new->occurrence = 1;
	new->next = NULL;
	if (c->first == NULL){
		c->first = new;
	}
	else {
		prev->next = new;
	}
}

int total(Count c){
	assert(c);
	int acc = 0;
	struct node *cur;
	for (cur=c->first; cur!=NULL; cur=cur->next){
		acc+=cur->occurrence;
	}
	return acc;
}

int unique(Count c){
	assert(c);
	int acc = 0;
	struct node *cur;
	for (cur=c->first; cur!=NULL; cur=cur->next){
		acc++;
	}
	return acc;
}

int count(Count c, int i){
	assert(c);
	struct node *cur;
	for (cur=c->first; cur!=NULL; cur=cur->next){
		if (cur->item == i){
			return cur->occurrence;
		}
	}
	return 0;
}

int mostfreq(Count c){
	assert(c);
	assert(total(c)>0);
	int max = c->first->occurrence;
	for (struct node *cur=c->first; cur!=NULL; cur=cur->next){
		if (cur->occurrence > max){
			max = cur->occurrence;
		}
	}
	for (struct node *cur=c->first; cur!=NULL; cur=cur->next){
		if (cur->occurrence == max){
			return cur->item;
		}
	}
	return -1;
}

void stats(Count c){
	assert(c);
	for (struct node *cur=c->first; cur!=NULL; cur=cur->next){
		printf("%d: %d\n", cur->item, cur->occurrence);
	}
}