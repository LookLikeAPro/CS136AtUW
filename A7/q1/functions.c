#include <stdio.h>

// Summation:  sum[i = 1 to n] O(1)
// Time:       O(n)
void draw_line(int n){
     for (int i = 0; i < n; i++){
   	printf("*");
     }
     printf("\n");
}

//*****************************************************

// Summation: sum[i=0 to n]*sum[j=i+1 to n]*sum[k=j+1 to n] O(1)
// Time: O(n^3)
bool magic_function1(int *a, int n){
   // a is an array of n integers
    for (int i = 0; i < n; i++){
      for (int j = i+1; j < n; j++){
         for (int k = j+1; k < n; k++){
            if (a[i] + a[j] + a[k] == 0){
                return true;
            }
         }
      }
   }
   return false;
}

//*****************************************************



// Summation: T(n)= O(1) + T(n-1)
// Time:  O(n)
// a is an array of n integers, t is initially 0, and b is initially false
bool magic_function2(int *a, int n, int t, bool b){
     if (n == 0) {
              return (t == 0) && b;
     }
     return magic_function2(a, n-1, t, b) || magic_function2(a, n-1, t+a[n-1], true);
}

//*****************************************************


// Summation: T(n) = O(1) + T(n/2)
// Time:  O(log(n))
//For this question, give your solution in terms of minimum number of bits
// required to encode a and/or b in binary
int hamming(int a, int b){
    assert(a>=0);
    assert(b>=0);
    return (a == 0 && b == 0) ? 0 : 
      ((a % 2) != (b % 2)) + hamming(a/2, b/2);
}


//*****************************************************

// Summation: sum[n/10 each time till n=0] O(1)
// Time:   O(n)
//For this question, give your solution in terms of the number
// of digits in the decimal representation of n
bool is_palindrome(int n){
     int orig = n;
     int rev = 0;
     while (n) {
        rev = rev*10 + n % 10;
        n /= 10;
     }
     return rev == orig;
}


//*****************************************************


//Summation: sum[i=0 to len]*sum[j=0 to len] O(1)
// Time: O(len)
bool check_dup(int arr[], int len){
     assert(arr != NULL);
     assert(len >= 0);
     bool retval = false;
     for (int i = 0; (i < len) && !retval; ++i){
        for (int j = 0; (j < len) && !retval; ++j){
          if (i != j){
              retval = (arr[i] == arr[j]);
          }
        }
     }
     return retval;
}

