
#pragma once
#include "weeklater.h"


Date week_later(Date date)
{
	Date temp;
	int days_in_month;
	int day, month, year;
	day = date.get_day();
	month = date.get_month();
	year = date.get_year();
	day += 7;
	switch( month )
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: days_in_month = 31;
				 break;
		case 4:
		case 6:
		case 9:
		case 11: days_in_month = 30;
				 break;
		case 2: if (leap_year(year))
					days_in_month = 29;
				else days_in_month = 28;
				break;
	}
	if (day > days_in_month)
	{
		day = day - days_in_month;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
	temp = Date(day,month,year);
	return temp;
}

int leap_year(int year)
{
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return 0;
	else if (year % 4 == 0)
		return 1;
	else return 0;
}

