/*
 File: test.c
Enter a description for this file.
*/


#include "fortesting.h"
#include <stdlib.h>


// testing 

int main(void) {
    struct node *root = NULL;
    struct node *head;
    
    bst_insert(&root, 4);
    bst_insert(&root, 2);
    bst_insert(&root, 1);
    bst_insert(&root, 3);
    bst_insert(&root, 5);
    
    head = tree2list(root);
    
    print_list(head);  /* prints: 1 2 3 4 5  */
  
    free_list(&head);
  
}
 
  