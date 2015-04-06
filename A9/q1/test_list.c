#include <stdio.h>
#include <assert.h>
#include "list.h"

int sq( int x ) {
  return x * x;
}


int main(void) {
  struct llist *myl = create_list();	
  add_first(25, myl);	
  add_last(17, myl);
  print_list(myl); 
  int max;
  int min;
  maxminlist(myl, &max, &min);
  assert(25==max);
  assert(17==min);
  assert(17==get_ith(myl, 1));
  delete_first(myl);
  print_list(myl);  
  insert_ith(myl, 1, 33);
  assert(get_ith(myl, 1)==33);
  print_list(myl); 		
  assert(2==list_length(myl));	
  struct llist *myl2 = create_list();
  add_first(100, myl2);	
  lst_append(myl, myl2);
  print_list(myl); 	
  struct llist *myl3 = create_list();
  add_first(100, myl3);	
  add_first(100, myl2);	
  assert(eq_list(myl2, myl3));	
  list_map(myl, sq);
  print_list(myl); 	
  destroy_list(myl);
  destroy_list(myl2);
  destroy_list(myl3);
  return 0;
}

