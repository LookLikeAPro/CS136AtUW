// A module for analyzing a sequence of integers

// data_cb(n) updates the internal state based on the value of n 
void data_cb(int n);

// total_data_points() returns the number of integers processed so far
int total_data_points(void);

// negative_sum() returns the sum of the negative integers processed so far
//    NOTE: you do not have to worry about overflow
int negative_sum(void);

// positive_sum() returns the sum of the positive integers processed so far
//    NOTE: you do not have to worry about overflow
int positive_sum(void);

// data_max() returns the largest processed number
// requires: data_cb is called atleast once
int data_max(void);

// data_min() returns the smallest processed number
// requires: data_cb is called atleast once
int data_min(void);

// data_spread() returns the number of integers that have been processed between
//      the first appearance of the min number and the first appearance of the max number.
//    require:  total_data_points() > 0
//    examples:
//      data: 100 200, the spread is 1 (between 100 and 200)
//      data: -1 10 0 8 -10 5, the spread is 3 (between 10 and -10)
//      data: -1 -10 0 10 10 5, the spread is 2 (between -10 and 10)
//      data: 42, the spread is 0 (between 42 and 42)
int data_spread(void);

// reset() clears all statistics and returns module to its initial state
void reset(void);

