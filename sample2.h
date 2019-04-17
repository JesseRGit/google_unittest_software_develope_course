#pragma once
class Date
{
	public:
	// Constructors
	// initialise to 1/1/1900
	Date();
	// initialise to dd/mm/yy
	Date(int dd,int mm,int yy);
	// member functions
	//void print();
	// prints date
	void next_day(); // sets date to next day
	// Accessor functions
	int get_day();
	// returns day
	int get_month(); // returns month
	int get_year(); // returns year
	int days_between(int dd, int mm, int yy);
	int days_since_newyear();
	private:
	int day;
	int month;
	int year;
	int leap_year();
	// returns true if year is a leap
	// year. Required in next_day()
};
