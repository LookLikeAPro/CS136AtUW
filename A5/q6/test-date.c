// =======================================
// = CS136, W15: Assignment 5, Problem 6 =
// = =================================== =
// = Author: John Fakename [12345678]    =
// =======================================

// Interactive testing program for the date module
// Note that this expects all input to be valid and no unexpected EOFs!

// Commands (Operations):
// e[1-2] d m y       - calls date and passes d, m, and y as arguments. Stores the resulting 
//                      struct date in either d1 or d2; specified by e1 or e2 (read "enter date 1" or 
//                      "enter date 2").
// n[1-2]             - calls next_day and passes t1 or t2 as arguments; specified by n1 or n2 
//                       (read "next day 1" or "next day 2")
// p[1-2]             - prints  d1 or d2 in yyyy-mm-dd format and in day-of-year format
// c                  - compares d1 and d2 (for both equality and inequality)
// d [1-2] [1-2]        - prints the number of days between the two selected days.
// end the program by sending EOF (Ctrl+D)

// Example (< denotes input and > denotes output):
// < e1 28 2 2015
// < p1
// > 2015-02-28 / D59, 2015
// < e2 28 2 2015
// < c
// > date_equal(date 1, date 2) == 1
// > date_lt(date 1, date 2) == 0
// > date_lt(date 2, date 1) == 0
// < n1
// < p1
// > 2015-03-01 / D60, 2015
// < d 1 2
// > 1
//  Ctrl+D


#include <stdbool.h>
#include <stdio.h>
#include "date.h"
int main(void) {
  int i_in;
  char c_in;
  struct date d1 = {1,1,1990};
  struct date d2 = {1,1,1990};
  struct date *sel, *sel2;
  while (scanf(" %c",&c_in) == 1) {
    if (c_in == 'e') {
      scanf("%d",&i_in);
      if (i_in == 1) {sel = &d1;} else {sel = &d2;}
      scanf("%d",&i_in);
      int day = i_in;
      scanf("%d",&i_in);
      int month = i_in;
      scanf("%d",&i_in);
      int year = i_in;
      *sel = date(day,month,year);
    } else if (c_in == 'n') {
      scanf("%d",&i_in);
      if (i_in == 1) {sel = &d1;} else {sel = &d2;}
      next_day(sel);
    } else if (c_in == 'p') {
      scanf("%d",&i_in);
      if (i_in == 1) {sel = &d1;} else {sel = &d2;}
      print_ymd(sel);
      printf(" / ");
      print_doy(sel);
      printf("\n");    } else if (c_in == 'c') {
      printf("date_equal(&d1, &d2) == %d\n",date_equal(&d1,&d2));
      printf("date_lt(&d1, &d2) == %d\n",date_lt(&d1,&d2));
      printf("date_lt(&d2, &d1) == %d\n",date_lt(&d2,&d1));
    } else if (c_in == 'd') {
      scanf("%d",&i_in);
      if (i_in == 1) {sel = &d1;} else {sel = &d2;}
      scanf("%d",&i_in);
      if (i_in == 1) {sel2 = &d1;} else {sel2 = &d2;}
      printf("%d\n",days_between(sel,sel2));	
    }
     while (scanf("%c",&c_in) == 1 && c_in != '\n');
  } 
}






