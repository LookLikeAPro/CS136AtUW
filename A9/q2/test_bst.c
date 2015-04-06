
#include <stdio.h>
#include "bst.h"
#include <assert.h>
#include <stdlib.h>



int main(void)

{

 	struct bsttree *t1 = create_bst();
	assert(is_bstempty(t1));
 	assert(bst_height(t1)==0);
	bst_insert(49, t1);  
  	assert(is_bst(t1));
	traverse_inorder(t1); 
	bst_insert(35, t1);  
 	assert(is_bst(t1));
	traverse_inorder(t1); 
	bst_insert(66, t1);  
  	assert(is_bst(t1));
	traverse_inorder(t1);  
	bst_insert(13, t1);  
	traverse_inorder(t1);  
	assert(!bst_search(t1, 62));
	assert(bst_search(t1, 49));
  	assert(bst_height(t1)==3);
  	mirror(t1);
  	assert(!is_bst(t1));
  	traverse_inorder(t1);  
 	destroy_bst(t1);  
    
	return 0;

}

