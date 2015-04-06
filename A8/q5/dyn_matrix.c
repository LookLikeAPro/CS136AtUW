#include "dyn_matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 8, Problem 5

struct matrix * new_matrix(int rows, int cols){
	assert(rows>0 && cols>0);
	struct matrix *m = malloc(sizeof(struct matrix));
	m->nr = rows;
	m->nc = cols;
	m->data = malloc(sizeof(int)*(rows+1)*(cols+1));
	for (int i=0; i<(rows+1)*cols; i++){
		m->data[i] = 0;
	}
	return m;
}

void free_matrix(struct matrix *m){
	assert(m);
	free(m->data);
	free(m);
}

void resize_matrix(struct matrix *m, int new_rows, int new_cols){
	assert(m);
	assert(new_rows>0 && new_cols>0);
	m = realloc(m->data, sizeof(int)*(new_cols+1)*(new_rows+1));
}

struct matrix *mult_matrix(const struct matrix *m1, const struct matrix *m2){
	assert(m1 && m2);
	int acc = 0;
    if (m1->nr!=m2->nc || m1->nc!=m2->nr){
		return NULL;
	}
	struct matrix *m = malloc(sizeof(struct matrix));
	if (m1->nr>m2->nr){
		m->nr = m2->nr;
	}
	else {
		m->nr = m1->nr;
	}
	if (m1->nc>m2->nc){
		m->nc = m2->nc;
	}
	else {
		m->nc = m1->nc;
	}
	m->data = malloc(sizeof(int)*(m->nr+1)*(m->nc+1));
	for (int i=0; i<m->nr;i++){
		for (int i2=0; i2<m->nc; i2++){
			acc = 0;
			for (int i3=0; i3<m1->nc; i3++){
				acc += m1->data[m1->nr*i+i3] * m2->data[i2+i3*m2->nc];
			}
			m->data[i*m->nr+i2] = acc;
		}
	}
	return m;
}

struct matrix *add_matrix(const struct matrix *m1, const struct matrix *m2){
	assert(m1 && m2);
	if (m1->nr != m2->nr || m1->nc != m2->nc){
		return NULL;
	}
	else{
		struct matrix *m = malloc(sizeof(struct matrix));
		m->nr = m1->nr;
		m->nc = m1->nc;
		m->data = malloc(sizeof(int)*(m->nr+1)*(m->nc+1));
		for (int i=0; i<(m->nr+1)*m->nc; i++){
			m->data[i] = m1->data[i]+m2->data[i];
		}
		return m;
	}
}

void transpose_matrix(struct matrix *m){
	assert(m);
	int key = 0;
	for (int i=0; i<m->nr; i++){
		for (int i2=0; i2<m->nc; i2++){
			if (i2>i){
				key = m->data[i*m->nr+i2];
				m->data[i*m->nr+i2] = m->data[i2*m->nr+i];
				m->data[i2*m->nr+i] = key;
			}
		}
	}
}

void set_matrix_cell(struct matrix *m, int i, int j, int v){
	assert(m);
	assert(i<m->nr && j<m->nc);
	m->data[i*m->nr+j] = v;
}

int get_matrix_cell(const struct matrix *m, int i, int j){
	assert(m);
	assert(i<m->nr && j<m->nc);
	return m->data[i*m->nr+j];
}


/*======================CAUTION===========================
            CS136 STAFF FUNCTIONS BEYOND THIS POINT
                  EDIT AT YOUR OWN PERIL
  ======================CAUTION==========================*/


// num_digits(a) returns the number of decimal digits in a, plus 1 if negative
static int num_digits(int a) {
  int digit_count = 1;
  if (a < 0) { 
    ++digit_count;
    a = -a;
  } 
  if (a < 10) {
    return digit_count;
  }

  while (a >= 10) {
    a /= 10;
    ++digit_count;
  }
  return digit_count;
}

// print_num(a,width) is mostly equivalent to printf("%{width}d",a)
//                    but it puts the minus sign before the padding spaces.
// requires: num_digits(a) <= width
// effects: exactly width characters are printed to the screen
static void print_num(int a, int width) {
  int need = num_digits(a);
  assert(need <= width);
  int i = 0;
  if (a < 0) { // line the minus signs up on the left.
    printf("-");
    a = -a;
  }
  for (; i < (width-need);++i) printf(" ");
  printf("%d",a);
}

// see interface file
void draw_matrix(const struct matrix *m) {
  assert(m);
  int biggest_digit = 0; 
  for (int i = 0; i < m->nr * m->nc; ++i) {
    int nd = num_digits(m->data[i]);
    if (nd > biggest_digit) {
      biggest_digit = nd;
    }
  }
  for (int row = 0; row < m->nr;++row) {
    for (int col = 0; col < m->nc;++col) {
      print_num(get_matrix_cell(m,row,col),biggest_digit);
      if (col == m->nc-1) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  }
}
