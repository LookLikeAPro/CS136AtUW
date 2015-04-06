#include "score.h"
#include <assert.h>
#include <stdio.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 6, Problem 4a

bool read_database(struct database *db){
    assert(db);
	while (scanf("%s", db->data[db->count].id)!=EOF){
		scanf("%d", &db->data[db->count].clicker);
		scanf("%d", &db->data[db->count].assn);
		scanf("%d", &db->data[db->count].mid);
		scanf("%d", &db->data[db->count].final);
		db->count++;
	}
	return db->count!=1;
}

int foldl(int (*fn)(const struct score *scr, int acc),
	int init, const struct database *db) {
	assert(db);
	int acc = init;
	for (int i=0; i<db->count; i++){
		acc = fn(&db->data[i], acc);
	}
	return acc;
}