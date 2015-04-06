// collatz.h
/*----------------------------------------------------------------------------
 * This module allows you to start with an arbitrary natural number and  find 
 * the numbers in Collatz sequence one by one.
 * The Collatz conjecture is as follows: 
 *  1. Start with any  natural number n.
 *  2. If n is even then
            n <-- n / 2 
       else n <-- 3n + 1
 *  3. n will always eventually reach 1 by performing the above step (2) repeatedly. 
 *----------------------------------------------------------------------------*/

// collatz_init(n) sets the internal state to n
// requires: n >= 1
void collatz_init(int n);

// collatz_next() returns the next collatz number in collatz sequence
// requires: collatz_init(n) has been called.
int collatz_next(void);
