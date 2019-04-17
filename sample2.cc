
#include "sample2.h"
// Constructor functions
Date::Date(int dd,int mm,int yy)
{
	day = dd;
	month = mm;
	year = yy;
}

Date::Date()
{
	day = 1;
	month = 1;
	year = 1900;
}

// Accessor functions

int Date::get_day()
{
	return day;
}

int Date::get_month()
{
	return month;
}

int Date::get_year()
{
	return year;
}

// Other functions
/* REMOVED DUE TO MULTIPLE COMPILER GIVING ERROR WITH IOSTREM
void Date::print()
{
cout << day << ’/’
<< month << ’/’
<< year;
}
*/

void Date::next_day()
	{
		int days_in_month;
	day++;
	switch (month)
	{
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10:
		case 12: days_in_month = 31;
			 break;
		case 4 :
		case 6 :
		case 9 :
		case 11: days_in_month = 30;
			 break;
		case 2 : if (leap_year())
			days_in_month = 29;
			else days_in_month = 28;
			 break;
	}
	if (day > days_in_month)
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
}

int Date::days_between(int dd,int mm,int yy)
{
	int days = 0;
	int day_old = day;
	int month_old = month;
	int year_old = year;
	if (yy > year || (yy == year && mm > month) || (yy == year && mm == month && dd > day))
	{
		//return 6;
		while ('0')
		{
			if (day == dd && month == mm && year == yy)
			{
				day = day_old;
				month = month_old;
				year = year_old;
				return days;
			}
			next_day();
			days++;
		}
	}
	else
	{
		//return 7;
		Date temp(dd,mm,yy);
		while ('0')
		{
			if (temp.day == day && temp.month == month && temp.year == year)
			{
				return days;
			}
			temp.next_day();

			days++;
		}
	}
return 40404;
}

int Date::days_since_newyear()
{
	return days_between(1, 1, year);
}

// Private function
int Date::leap_year()
{
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return 0;
	else if (year % 4 == 0)
		return 1;
	else return 0;
}
