#include <stdbool.h>

// strfilter(s,f) keeps only those characters in s where f(c) is true
// requires: s is a null terminated string
// effects: s is mutated
// time: O(n) * T_f, where n is the number of characters in s, 
//       and T_f is the running time of f.
void strfilter(char s[], bool (*f)(char c));
