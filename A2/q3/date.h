// date.h

// A module for working with dates which consists of day, month and year values

#include <stdbool.h>

struct date{
	int day;
	int month;
	int year;
};

// is_valid(d) returns true if d is a valid date; false otherwise
bool is_valid(const struct date d);

// d_eq(d1,d2) returns true if date d1 and d2 are the same date; false otherwise
// requires:  d1 and d2 are valid dates
bool d_eq(const struct date d1, const struct date d2);

// greaterthan(d1,d2) returns true if date d1 comes after d2; false otherwise
// requires:  d1 and d2 are valid dates
bool greaterthan(const struct date d1, const struct date d2);

// day_number(d1) returns the number of days from Jan 1st to date d1 in the year
//   of d1.
// requires: d1 is a valid date
int day_number(const struct date d1);

// days_between(d1, d2) returns the number of days between dates d1 and d2
// requires: d1 and d2 are valid dates
int days_between(const struct date d1, const struct date d2);
