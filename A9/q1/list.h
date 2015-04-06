// list.h


// Note: You are not allowed to change the structure definitions


#include <stdbool.h>

struct llnode {
	int item;
	struct llnode *next;
};

struct llist {
	struct llnode *first;  // points to first node in the list
	struct llnode *last;   // points to the last node in the list
	int len;
};

// create_list() creates an empty list
// effects: allocates a new struct llist. 
//          first and last initialized to NULL
//          len initialized to 0
//          caller must eventually call destroy_list to free
// time: O(1)
struct llist *create_list(void);


// destroy_list(lst) destroys lst
// requires: lst is not NULL
// effects: lst is deallocated (no longer valid)
// time: O(n) where n is the length of lst
void destroy_list(struct llist *lst);


// list_length(lst) determines the number of nodes in lst
// requires: lst is not NULL
// time: O(1)
int list_length(struct llist *lst);


// print_list(lst) prints the items in the list lst from first to last
// requires: lst is not NULL
// effects: lst is printed to the screen
// time: O(n) where n the length of lst
void print_list(struct llist *lst);


// add_first(n, lst) adds n to the beginning of lst
// requires: lst is not NULL
// effects: allocates a new struct llnode 
//          adds it to the beginning of lst
//          caller must eventually free the added llnode
// time: O(1)
void add_first(int n, struct llist *lst);


// add_last(n, lst) adds n to the end of lst
// requires: lst is not NULL
// effects: allocates a new struct llnode 
//          adds it to the end of lst
//          caller must eventually free the added llnode
// time: O(1)
void add_last(int n, struct llist *lst);


// delete_first(lst) removes the first node from lst
//    and returns the item that was in that node
// requires: lst length is > 0 
// effects: first node of lst is deallocated (no longer valid)
// time: O(1)
int delete_first(struct llist *lst);


// get_ith(lst, index) returns the item at the ith node in lst
//     (for example, get_ith(lst, 0) returns the first item
// requires: index is a valid index (0 ... length-1) [assert this!]
// time: O(n) where n = index
int get_ith(struct llist *lst, int index);


// insert_ith(lst, index, data) inserts a new node with item data
//     to lst at location index
// requires: index is a valid new index (0 ... length) [assert this!]
// effects: allocates a new struct llnode 
//          adds it to lst
//          caller must eventually free the added llnode
// time: O(n) where n = index
void insert_ith(struct llist *lst, int index, int data);


// lst_append(lst1, lst2) appends contents of lst2 to the end of lst1 and
//     then empties lst2
// requires: both lst1 and lst2 are not NULL
// effects: lst1 will be modified
//          lst2 will become empty (first and last initialized to NULL
//          len initialized to 0)
// time: O(1) 
void lst_append(struct llist *lst1, struct llist *lst2);


// eq_list(lst1, lst2) determines if lst1 and lst2 are identical
//  requires: both lst1 and lst2 are not NULL
//   time: O(n) where n is the length of lst1
//         O(1) if length of lst1 != length of lst2
bool eq_list(struct llist *lst1, struct llist *lst2);


// maxminlist(lst, &min, &max) finds the maximum and minimum items in lst. 
// returns 1 and modifies *min/*max to store minimum/maximum item in lst
//   OR returns 0 if lst is empty and does not modify *min/*max
//requires: lst valid
//effects: min and max might be modified
//   time: O(n) where n is the length of lst
int maxminlist(struct llist *lst, int *max, int *min);

// list_map(lst, function_ptr) applies the function pointed to by function_ptr to every value at nodes in lst.
//requires: lst is not NULL
//effects: item(s) in lst are modified
//time: O(n) where n is the length of lst 
//      assuming that applying the function on each node is O(1).
void list_map( struct llist *lst, int (*function_ptr)(int) );

