// dun_matrix.h -- a module for dynamically allocated matrix stuff

#include <stdbool.h>

struct matrix {
  int nr; // number of rows
  int nc; // number of cols
  int *data; 
};

// new_matrix(rows,cols) returns a pointer to a new cols x rows matrix.  The matrix is initialized with
//       a 0 in each cell.
// requires: rows > 0, cols > 0
// effects: A new dynamically allocated matrix is returned.  
//          Caller **must** free with free_matrix.
// time: O(n) where n is rows * cols
struct matrix * new_matrix(int rows, int cols);

// free_matrix(m) frees the dynamically allocated matrix *m
// requires: m points to a matrix created using new_matrix
// effects: m is deallocated.
// time: O(1)
void free_matrix(struct matrix *m);


// resize_matrix(m,new_rows,new_cols) resizes *m to have new_n rows and new_m cols
//    existing cells retain their value and any new cells added are initialized with 0.0
// requires:  m points to a dynamically allocated matrix,
//            new_n > 0, new_m > 0
// effects:  m is resized to be new_rows x new_cols
// time: O(n) where n is new_rows * new_cols
void resize_matrix(struct matrix *m, int new_rows, int new_cols);


// mult_matrix(m1,m2) returns a new dynamically allocated matrix equal to *m1 times *m2
//   (See: https://en.wikipedia.org/wiki/Matrix_multiplication)
//    if the dimensions of m1 and m2 do not allow for multiplication, returns NULL instead.
// requires: m1 and m2 point to valid matrix structures.
// effects: a non-NULL return value will be a new dynamicallya llocated matrix.  Caller must free with free_matrix.
// time: O(nmp) where n, m, and p are the 3 distinct dimensions of m1 and m2 

struct matrix *mult_matrix(const struct matrix *m1, const struct matrix *m2);

// add_matrix(m1,m2) returns a new dynamically allocated matrix equal to *m1 plus *m2
//   if the dimensions of m1 and m2 do not allow for addition, returns NULL instead
// requires: m1 and m2 point to valid matrix structures
// effects: a non-NULL return value is a dyanamically allocated matrix.  Caller must free with free_matrix.
// time: O(n) where n is m1->nr * m1->nc
struct matrix *add_matrix(const struct matrix *m1, const struct matrix *m2);

// transpose_matrix(m) transposes the matrix m.
// requires: m points to a valid matrix structure
// effects: m is transposed
// time: O(n) where n is m->nr * m->nc
void transpose_matrix(struct matrix *m);


// set_matrix_cell(m,i,j,v) sets the cell at row i, column j in m to be v.
// requires: m points to a valid matrix
//           (i,j) is a valid cell in m
// effects: matrix m is updated
// time: O(1)
void set_matrix_cell(struct matrix *m, int i, int j, int v);

// get_matrix_cell(m,i,j) returns the value in the cell at row i, column j in m
// requires: m points to a valid matrix
//           (i,j) is a valid cell in m
// time: O(1)
int get_matrix_cell(const struct matrix *m, int i, int j);


// draw_matrix(m) draws the matrix pointed to by m.
// requires: m points to a valid matrix
// effects: m is printed to the screen
// time: O(n) where n is m->nr * m->nc
void draw_matrix(const struct matrix *m);
