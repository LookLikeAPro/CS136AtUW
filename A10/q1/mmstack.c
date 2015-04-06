#include <assert.h>
#include "mmstack.h"
#include <stdlib.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 10, Problem 1

//See interface for documentation
struct node {
	int item;
	struct node *next;
};

struct mmstack {
	struct node *first;
	
};

MMStack create_MMStack(){
	MMStack mms = malloc(sizeof(struct mmstack));
	mms->first = NULL;
	return mms;
}

int mms_length(MMStack mms){
	assert(mms);
	int count = 0;
	struct node *cur;
	for (cur=mms->first; cur!=NULL; cur=cur->next){
		count++;
	}
	return count;
}

void mms_push(MMStack mms, int val){
	assert(mms);
	struct node *new = malloc(sizeof(struct node));
	new->item = val;
	new->next = mms->first;
	mms->first = new;
}

int mms_max(MMStack mms){
	assert(mms);
	int max = mms->first->item;
	struct node *cur;
	for (cur=mms->first; cur!=NULL; cur=cur->next){
		if (cur->item>max){
			max = cur->item;
		}
	}
	return max;
}

int mms_min(MMStack mms){
	assert(mms);
	int min = mms->first->item;
	struct node *cur;
	for (cur=mms->first; cur!=NULL; cur=cur->next){
		if (cur->item<min){
			min = cur->item;
		}
	}
	return min;
}

int mms_pop(MMStack mms){
	assert(mms);
	assert(mms_length(mms)>0);
	int returnVal = mms->first->item;
	struct node *temp = mms->first;
	mms->first = mms->first->next;
	free(temp);
	return returnVal;
}

void destroy_MMStack(MMStack mms){
	assert(mms);
	struct node *cur=mms->first;
	struct node *prev;
	while (cur!=NULL){
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	free(mms);
}