/**
set.h - a dynamic set module
**/

struct set{
  int count;
  int len;
  int *data;
};

// new_set(l) returns a new dynamically allocated set that will hold up to l elements
// requires: l > 0
// effects: a new set is dynamically allocated.  user must deallocate with free_set()
// time: O(1)
struct set* new_set(int l);

// free_set(s) frees the memory allocated for s
// requires: s was dynamically allocated
// effects: the memory allocated for s is freed
// time: O(1)
void free_set(struct set* s);


// sym_diff(s1,s2) returns a pointer to a new set that contains all elements
// that are in s1 or s2, but not in both.
// requires: s1,s2 are not NULL
// effects: a new set is allocated.  user must free with free_set
// time: O(nm) where n = s1->count   and m = s2->count
struct set* sym_diff(const struct set *s1, const struct set *s2);
