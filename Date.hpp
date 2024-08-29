#ifndef DATE_HPP_
#define DATE_HPP_
#include <iostream>

class Date {
public:
	Date();
	virtual ~Date();
	int getDay() const;
	//sets the day
	bool setDay(int day, int month, int year);
	int getMonth() const;
	//sets the month
	bool setMonth(int month, int year);
	int getYear() const;
	//sets the year
	bool setYear(int year);
	//returns true if both dates are equal
	bool operator == (Date &rightDate);
	//returns true if right date is further from left date
	bool operator < (Date &rightDate);
	//returns true if left date is further from right date
	bool operator > (Date &rightDate);

private:
	int day;
	int month;
	int year;
};

std::ostream& operator<<(std::ostream& date, Date &theDate);
#endif /* DATE_HPP_ */


