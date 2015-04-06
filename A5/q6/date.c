// =======================================
// = CS136, W15: Assignment 5, Problem 6 =
// = =================================== =
// = Author: John Fakename [12345678]    =
// =======================================

// Implementation for a C module that provides functions to work with dates

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "date.h"

// see .h
static int days_in_month(int m,int y) {
   if (m == 9 || m == 4 || m == 6 || m == 11) {
     return 30;
   } else if (m == 2) {
     if (!(y % 400)  || (!(y % 4) && y % 100)) return 29;
     return 28;
   }
   return 31;
}

// see .h
static bool is_valid(const struct date *d) {
   assert(d);
   return (d->month >= 1 && d->month <= 12) && (d->day >= 1 && d->day <= days_in_month(d->month,d->year));
}

// see .h
struct date date(int day, int month, int year) {
  struct date result = {day,month,year};
  if (!is_valid(&result)) {
    result.day = 1;
    result.month = 1;
    result.year = 1990;
  }
  return result;
}


// see .h
bool date_equal( struct date *d1,  struct date *d2) {
   assert(d1); assert(d2);
   return d1->day == d2->day && d1->month==d2->month && d1->year==d2->year;
}

// see .h

bool date_lt( struct date *d1,  struct date *d2) {
  assert(d1); assert(d2);
  return d1->year < d2->year || 
         (d1->year == d2->year && d1->month < d2->month) ||
         (d1->year == d2->year && d1->month == d2->month && d1->day < d2->day);
}


// see .h
void next_day(struct date *d) {
  assert(d);
  d->day++;
  if (d->day > days_in_month(d->month,d->year)) {
    d->day = 1;
    d->month++;
    if (d->month == 13) {
      d->month = 1;
      d->year++;
    }
  }
}

// see .h
int days_between( struct date *d1,  struct date *d2) {
  assert(d1); assert(d2);
  const struct date *first;
  struct date *second;
  int count = 0;
  if (date_lt(d1,d2)) { 
     first = d1; second = d2;
  } else {
     first = d2; second = d1;
  }
  struct date tmp = date(first->day, first->month, first->year);        

  while (!date_equal(&tmp,second)) {
    ++count;
    next_day(&tmp);
  }
  return count;
}


// see .h
void print_ymd( struct date *d) {
   assert(d);
   printf("%04d-%02d-%02d",d->year,d->month,d->day);
}

// see .h
void print_doy( struct date *d) {
   assert(d);
   int doy = d->day;
   for (int m = 1; m < d->month;++m) {
      doy += days_in_month(m,d->year);
   }
   printf("D%d, %d",doy,d->year);
}

