#include "date.h"
// Jiayu Zhou
// CS136 Winter 2015
// Assignment 2, Problem 3


bool is_leap(const int year){
	if (year%4 != 0)
	  return false;
	else if (year%100 !=0)
		return true;
	else if (year%400 != 0)
		return false;
	else
		return false;
}

bool is_valid(const struct date d){
	if (d.month>12 || d.month<1)
		return false;
	else if (d.month==2)
	{
		if (d.day==29 && is_leap(d.year))
			return true;
		else if (d.day>28 || d.day<1)
			return false;
		else
			return true;
	}
  else if (d.month==1 || d.month==3 || d.month==5 || d.month==7
           || d.month==8 || d.month==10 || d.month==12){
		if (d.day>=1 && d.day<=31)
			return true;
  }
	else{
		if (d.day<=30 && d.day>=1)
			return true;
	}
	return false;
}

bool d_eq(const struct date d1, const struct date d2){
	if (d1.year==d2.year && d1.month==d2.month && d1.day==d2.day)
		return true;
	return false;
}

bool greaterthan(const struct date d1, const struct date d2){
	if (d1.year>d2.year)
		return true;
	else if (d1.year==d2.year){
		if (d1.month>d1.month)
			return true;
		else if (d1.month==d2.month){
			if (d1.day>d2.day)
				return true;
		}
	}
	return false;
}

int addMonth (const int days, const int month, const int i){
	if (i == month)
		return days;
	else if (month==1 || month==3 || month==5 || month==7 ||
             month==8 || month==10 || month==12)
		return addMonth(days+31, month,i+1);
    else if (month==2)
        return addMonth(days+28, month,i+1);
    else
        return addMonth(days+30, month,i+1);
}

int day_number(const struct date d1){
	return addMonth(d1.day, d1.month-1, 0);
}

int addYear(const int start, const int end){
	if (start == end)
		return 0;
	else if (is_leap(start))
		return 366 + addYear(start+1, end);
	else
		return 365 + addYear(start+1, end);
}

int days_between(const struct date d1, const struct date d2){
	return day_number(d2) - day_number(d1) + addYear(d1.year, d2.year);
}