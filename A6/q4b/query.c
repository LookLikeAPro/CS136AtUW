/**
 Jiayu Zhou
 CS136, Winter 2015
 Assignment 6, Problem 4b
 File: query.c
 Performs basic queries on a list of student scores
 */
#include <stdio.h>
#include <assert.h>
#include "score.h"

// example query using the foldl function from score.h
// Number of students with zero marks in final exam
int query_0(const struct score *data, int acc) {
  assert(data);
  return acc + (data->final == 0);
}

/* ---------------------------------------------------------- */
// Add your functions here
// You are not allowed to use any kind of loop (e.g., for, 
//          while or do..while loops) or recursion.

int query_1(const struct score *data, int acc) {
	assert(data);
	if (data->final+data->mid+data->clicker+data->assn >= 50 && data->assn>=10 && data->mid+data->final>32){
		return acc+1;
	}
	else {
		return acc;
	}
}

int query_2(const struct score *data, int acc) {
	assert(data);
	if (data->final+data->mid+data->clicker+data->assn >= 50 && data->assn>=10 && data->mid+data->final>32) {
		return acc;
	}
	else if (data->assn<10 && data->final+data->mid+data->clicker>=40){
		return acc+1;
	}
	return acc;
}

int query_3(const struct score *data, int max) {
	assert(data);
	if (data->final+data->mid+data->clicker+data->assn > max){
		return data->final+data->mid+data->clicker+data->assn;
	}
	else{
		return max;
	} 
}

int query_3_print(const struct score *data, int max) {
	assert(data);
	if (data->final+data->mid+data->clicker+data->assn == max){
		printf("%s\n", data->id);
	}
	return max;
}



/* ---------------------------------------------------------- */

int main(void) {
    struct database db;
    db.count= 0;
	if (read_database(&db) == true) {
		printf("query-0:%d\n", foldl(query_0, 0, &db));
		printf("query-1:%d\n", foldl(query_1, 0, &db));
		printf("query-2:%d\n", foldl(query_2, 0, &db));
		printf("query-3:\n");
		foldl(query_3_print, foldl(query_3, 0, &db), &db);
	}
}
