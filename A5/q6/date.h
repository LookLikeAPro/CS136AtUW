// =======================================
// = CS136, W15: Assignment 5, Problem 6 =
// = =================================== =
// = Author: John Fakename [12345678]    =
// =======================================

// Interface for a C module that provides functions to work with dates

#include <stdbool.h>

// A valid date is when:
// - 1 <= month < 12,
// - 1 <= day < number of day in that month (this will also depend on the year)

// You can assume that all functions are given valid dates (do not assert this)

struct date {
  int day;
  int month;
  int year;
};

// date(day,month,year) constructs a valid date structure from the given values
// if the values are not valid, it returns January 1st, 1990.
struct date date(int day, int month, int year);

// date_equal(d1, d2) determines if *d1 and *d2  represent the same date
// requires: d1 and d2 are not NULL
bool date_equal( struct date *d1,  struct date *d2);


// date_lt(d1,d2) determins if *d1 comes before *d2 on the calendar
// requires: d1 and d2 are not NULL
bool date_lt( struct date *d1,  struct date *d2);


// next_day(d) updates *d to be the next day on the calendar (this may involve 
//    changing the month and the year as well).
// requires:  d is not NULL
// effects: the fields are *d are altered.
void next_day(struct date *d);

// days_between(d1,d2) returns the absolute number of days between *d1 and *d2
//    (there are 0 days between a day and itself, 
//    and 1 day between a day and the next).
// requires: d1 and d2 are not NULL
int days_between( struct date *d1,  struct date *d2);


// print_ymd(d) prints *d in yyyy-mm-dd format, with no newline.
// requires:  d is not NULL
// effects: the date is printed to the screen
void print_ymd( struct date *d);

// print_doy(d) prints *d in day-of-year format 
// eg: Febuary 27th, 2015 is printed as "D35, 2015"
// requires:  d is not NULL
// effects: the date is printed to the screen in day-of-year format

void print_doy( struct date *d);
