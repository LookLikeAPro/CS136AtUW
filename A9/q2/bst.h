//bst.h
#include <stdbool.h>

// You are not allowed to change the structure definitions

struct bstnode {
	int item;
	struct bstnode *left;
	struct bstnode *right;
};

struct bsttree {
	struct bstnode *root;
};


// create_bst() creates a new empty BST (root is NULL)
// effects: allocates a new struct bsttree
//          and sets the root to NULL
// caller must eventually call destroy_bst to free
//   time: O(1)
struct bsttree *create_bst(void);


//  destroy_bst(t) frees all memory for the BST t
// requires: t is not NULL
// effects: t is deallocated (no longer valid)
//    time: O(n) where n is the number of nodes in t
void destroy_bst(struct bsttree *t);


// make_bstnode(val, l, r) returns a new bstnode with item val 
//           and left/right are  l/r respectively
// effects: allocates a new struct bstnode
//           sets item to val, left to l, and right to r
//           caller must eventually free the added bstnode
//   time: O(1)
struct bstnode *make_bstnode(int val, struct bstnode *l, struct bstnode *r);


// is_bstempty(t) returns true if t is an empty BST, otherwise false.
//     empty BST is when t->root is NULL
// requires: t is not NULL.
//   time: O(1)
bool is_bstempty(struct bsttree *t);


// is_bst(t) returns true if t is a valid BST
//  (meaning it obeys the ordering property), otherwise false
//requires: t is not NULL
// time: O(n) where n is the number of nodes in t
bool is_bst(struct bsttree *t);

//  traverse_inorder(t) prints all nodes of t in order
//      (traverse left, print root, traverse right)
//  requires: t is not NULL
// effects: t is printed to the screen
//  time: O(n) where n is the number of nodes in tree t
void traverse_inorder(struct bsttree *t);


//  bst_insert(val, t) inserts a new node with val into the BST t
//    in such a way the the t remains a BST tree
//    or makes no changes if val already exists
//    val is added as a leaf node
//  requires: t is a valid BST (DON'T assert this, as it will affect
//                 the running time for testing your solution)
//  effects: might allocate a new struct bstnode and add it to t.
//           caller must eventually free the added bstnode
//  time: O(h) where h is the height of t
void bst_insert(int val, struct bsttree *t);


//  bst_search(t, val) determines if val is an item in the bsttree t, 
//                     returns true if val is in BST t, false otherwise
//  requires: t is a valid BST
//    time: O(h) where h is the height of t
bool bst_search(struct bsttree *t, int val);


// bst_height(t) returns the height of BST t. 
//      If t is an empty BST then its height is 0, 
//      if t is a BST with one node, its height is 1.
// requires: t is not NULL
//  time: O(n), where n is the number of nodes in t
int bst_height(struct bsttree *t);


// mirror(t) 
/* 
 Changes the tree t so that the roles of the 
 left and right pointers are swapped at every node.
 So the tree... 
       4 
      / \ 
     2   5 
    / \ 
   1   3

 is changed to... 
       4 
      / \ 
     5   2 
        / \ 
       3   1 
*/ 
// requires: t is not NULL
// effects: modifying the pointers. The result is not a valid BST
//          if it was given a valid BST initially
// time: O(n) where n is the number of nodes in t.
void mirror(struct bsttree *t); 
 
