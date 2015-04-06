#include <stdlib.h>
#include <string.h>
#include "strqueue.h"
#include <assert.h>
#include <stdio.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 10, Problem 3

struct item{
	char *string;
	struct item *next;
};

struct strqueue{
	struct item *first;
};

//See interface for documentation
StrQueue create_StrQueue(void){
	StrQueue sq = malloc(sizeof(struct strqueue));
	sq->first = NULL;
	return sq;
}

void destroy_StrQueue(StrQueue sq){
	assert(sq);
	struct item *cur = sq->first;
	struct item *prev;
	while (cur){
		prev = cur;
		cur = cur->next;
		free(prev->string);
		free(prev);
	}
	free(sq);
}

void sq_add_back(StrQueue sq, const char *str){
    /*
	assert(sq);
	assert(str);
	struct item *cur = sq->first;
	struct item *prev = NULL;
	while (cur){
		prev = cur;
		cur = cur->next;
	}
	struct item *new = malloc(sizeof(struct item));
	new->string = malloc(sizeof(str));
	strcpy(new->string, str);
	new->next = NULL;
	if (prev){
		prev->next = new;
	}
	else{
		sq->first = new;
	}*/
}

char *sq_remove_front(StrQueue sq){
	assert(sq);
	if (!sq->first){
		return NULL;
	}
	char *returnString = malloc(sizeof(sq->first->string));
	strcpy(returnString, sq->first->string);
	free(sq->first->string);
	struct item *temp = sq->first->next;
	free(sq->first);
	sq->first = temp;
	return returnString;
}

int sq_length(StrQueue sq){
	assert(sq);
	int count = 0;
	struct item *cur;
	for (cur = sq->first; cur!=NULL; cur=cur->next){
		count++;
	}
	return count;
}

/*
int main (void){
	StrQueue sq = create_StrQueue();
	sq_add_back(sq, "lol");
	sq_add_back(sq, "lol2");
	sq_add_back(sq, "lol3");
	printf("%d\n", sq_length(sq));
	sq_add_back(sq, "lol4");
	printf("%s\n", sq_remove_front(sq));
	printf("%d\n", sq_length(sq));
	printf("%s\n", sq_remove_front(sq));
	printf("%s\n", sq_remove_front(sq));
	destroy_StrQueue(sq);
}*/