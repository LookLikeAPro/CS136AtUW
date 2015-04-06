/**
  interactive testing module for dyn_matrix module.  
  input is not error checked.  enter something invalid and it will probably crash.
  Or fail an assertion in dyn_matrix.c
 **/
#include "dyn_matrix.h"
#include <stdio.h>
/**
 commands:
 for all commands:  requires 0 <= n <= 9

 f [n] - free matrix n  Prints "OK" on success, 
       - Prints "matrix n not found" if matrix n has not been created.

 n [n] [nr] [nc] - matrix n is a new matrix with nr rows and nc columns
                 - if matrix n exists, prints "error, matrix n already exists"
    requires: nr > 0, nc > 0

 p [n] - print matrix n, or "matrix n not found" if no matrix n

 t [n] - transpose matrix n, prints "matrix n not found" if no matrix n

 r [n] [nr] [nc] - resizes matrix n to have nr rows and nc columns
       - requires: nr > 0, nc > 0
 = [n] [v1]....[vk] sets matrix m to contain values v1 through vk, 
       - values must be entered in row major form.
       - must enter exactly k values or who knows what will happen. 
          (Bad things, probably)

 + [n1] [n2] [n3 or 'p'] - if integer n3 is given, sets matix n3 to be n1 + n2
      if 'p' is given instead, prints the result of n1 + n2.
     - if n3 is given and matrix n3 exists, frees old matrix n3 before setting 
     - if the operation fails  then "invalid operation"
      is printed and matrix n3 is not changed


      * [n1] [n2] [n3 or 'p'] - if integer n3 is given, sets matrix n3 to be n1 * n2
      if 'p' is given instead, prints the result of n1 * n2
      - if n3 is given and matrix n3 exists, frees old matrix n3 before setting 
      - if the operation fails  then "invalid operation"
      is printed and matrix n3 is not changed

 **/


// chomp_line() does what it says on the tin (it eats the rest of the line).
// effects: removes input until newline (or EOF) is reached
static void chomp_line(void) {
  char c;
  while (scanf("%c",&c) == 1 && c != '\n');
}

int main(void) {
  struct matrix *m[10];
  for (int i = 0; i < 10; ++i) m[i] = NULL;
  int n1;
  int n2;
  int n3;
  int v;
  struct matrix *result;

  char command;
  // yikes.  Don't even look.  Please.
  while (scanf(" %c",&command) == 1) {
    if (command == 'f') {
      if (scanf("%d",&n1) == 1) {
        if (m[n1]) {
          free_matrix(m[n1]);
          m[n1] = NULL;
        } else {
          printf("matrix %d does not exist\n",n1); 
        }
      }
    } else if (command == 'n') {
      if ((scanf("%d",&n1) == 1) && (scanf("%d",&n2) == 1)  && 
          (scanf("%d",&n3) == 1)) {
        if (m[n1]) {
          printf("matrix %d already exists\n", n1);
        } else {
          m[n1] = new_matrix(n2,n3); 
        }
      }
    } else if (command == 'p') {
      if (scanf("%d",&n1) == 1) {
        if (m[n1]) {
          draw_matrix(m[n1]); 
        } else {
          printf("matrix %d does not exist\n",n1); 
        }
      }
    } else if (command == 't') {
      if (scanf("%d",&n1) == 1) {
        if (m[n1]) {
          transpose_matrix(m[n1]); 
        } else {
          printf("matrix %d does not exist\n",n1); 
        }
      }
    } else if (command == '=') {
      if (scanf("%d", &n1) == 1) {
        if (m[n1]) {
          for (int i = 0; i < m[n1]->nr; ++i) {
            for (int j = 0; j < m[n1]->nc; ++j) {
              if (scanf("%d",&v) == 1) {
                set_matrix_cell(m[n1],i,j,v); 
              }
            }
          }
        } else {
          printf("matrix %d does not exist\n",n1); 
        }
      }
    } else if (command == 'r') {
      if ((scanf("%d",&n1) == 1) && (scanf("%d",&n2) == 1)  && 
          (scanf("%d",&n3) == 1)) {
        if (!m[n1]) {
          printf("matrix %d does not exist\n", n1);
        } else {
          resize_matrix(m[n1],n2,n3); 
        }
      }
    } else if (command == '+') {
      if ((scanf("%d",&n1) == 1) &&
          (scanf("%d",&n2) == 1)) {
        result = add_matrix(m[n1],m[n2]);
        if (result) {
          if (scanf("%d",&n3) == 1) {
            if (m[n3]) free_matrix(m[n3]);
            m[n3] = result;
            result = NULL;
          } else {
            draw_matrix(result);
            free_matrix(result);
            result = NULL;
          }
        } else {
          printf("invalid operation\n"); 
        }
      }
    } else if (command == '*') {
      if ((scanf("%d",&n1) == 1) &&
          (scanf("%d",&n2) == 1)) {
        result = mult_matrix(m[n1],m[n2]);
        if (result) {
          if (scanf("%d",&n3) == 1) {
            if (m[n3]) free_matrix(m[n3]);
            m[n3] = result;
            result = NULL;
          } else {
            draw_matrix(result);
            free_matrix(result);
            result = NULL;
          }
        } else {
          printf("invalid operation\n"); 
        }
      }
    }

    chomp_line();
  }

  // show's over, clean up the mess

  for (int i =0 ; i < 10; ++i) {
    if (m[i]) free_matrix(m[i]); 
  }

}
