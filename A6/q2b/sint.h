// interface for simple string arithmetic operations
// like comparison and addition of positive integers.

// represent an integer as a series of ASCII digits '0'-'9'
struct sint {
   char digits[51];
};

// strim(a) removes leading zeros in a->digits
// assume that a is positive,
//   i.e., the numeric value of a->digits >= 0
// requires: a != NULL
void strim(struct sint *a);

// scomp(a, b) numerically compares a->digits with b->digits. 
// returns 1 if a > b, 0 if a==b and -1 if a < b
// requries: a != NULL and b != NULL
int scomp(const struct sint *a, const struct sint *b);

// sadd(a, b) numerically adds a->digits with b->digits and 
// returns the resulting sint. Assume that no overflow will occur
// assume that a and b are positive,
//   i.e., the numeric value of a->digits >= 0 and b->digits >= 0
// requires: a!= NULL and b!= NULL
struct sint sadd(const struct sint *a, const struct sint *b);
