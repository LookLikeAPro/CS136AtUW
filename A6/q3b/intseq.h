// Interface for the intseq C module. Provides functions to keep track of 
// statistics on a sequence of integers.

#include <stdbool.h>

// number_sum(seq, len) returns the sum of all of the integers in seq.
// requires:  seq is not NULL and len > 0
int number_sum(int *seq, int len);

// max_number(seq, len) returns the greatest integer in seq.
// requires:  seq is not NULL and len > 0
int max_number(int *seq, int len);

// min_number(seq, len) returns the smallest integer in seq.
// requires:  seq is not NULL and len > 0
int min_number(int *seq, int len);

// minmax_dist(seq, len) returns the quantity of integers in seq between the 
// first appearance of the minimum integer and the first appearance of the 
// maximum integer.
// requires:  seq is not NULL and len > 0
// Examples: seq = { 100, 200 }, the distance is 1 (between 100 and 200), 
//           seq = { -1, 10, 0, 8, -10, 5 }, the distance is 3 (between 10 and -10), 
//           seq = { -1, 10, 0, 10, -10, 5 }, the distance is 3 (between 10 and -10), 
//           seq = { 42 }, the distance is 0 (between 42 and 42).
int minmax_dist(int *seq, int len);

// seq_avg(seq, len) returns the average (mean) of the elements in seq.
// requires:  seq is not NULL and len > 0
float seq_avg(int *seq, int len);

// seq_has_duplicates(seq, len) determines if seq has any duplicates.
// requires:  seq is not NULL and len > 0
bool seq_has_duplicates(int *seq, int len);

// seq_most_occurrences(seq, len) returns the most frequent integer in seq. If 
// there is a tie, return the integer with the lowest index of its first occurrence.
// requires:  seq is not NULL and len > 0
int seq_most_occurrences(int *seq, int len);

