/**
 File: fortesting.h
Enter a description for this file.
*/

#include "tree2list.h"
#include <stdio.h>
#include <stdlib.h>


// make_node(data) returns a new node with val=data, 
//   left and right are set to NULL
// effects: allocates a new struct node.
//           caller must eventually free the allocated node
// time: O(1)
struct node *make_node(int data);


// bst_insert(ptr data) adds a new node with data to BST *ptr
//  the new node should be inserted as a leaf
// or makes no change if data already exists
// effects: allocates a new struct node and set val to data and 
//          left and right to NULL
//          caller must eventually free  the added node
// time: O(n) where n is the number of nodes in BST
void bst_insert(struct node ** ptr, int data);
  

// list_free (lst) frees *lst
// effects: *lst is deallocated (no longer valid)
// time: O(n) where n is the length of the list
void free_list(struct node **lst);

// print_list(head) prints the list head 
//effects: the list is printed to the screen
//time: O(n), where n is the length of the list
void print_list(struct node *head);
