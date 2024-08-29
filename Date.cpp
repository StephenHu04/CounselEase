#include "Date.hpp"

//Time complexity would be O(1) since it can be done in constant time
Date::Date() {
	this->day = 0;
	this->month = 0;
	this->year = 0;

}

//Time complexity would be O(1) since it can be done in constant time
Date::~Date() {
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

//Time complexity would be O(1) since it can be done in constant time
int Date::getDay() const {
	return day;
}

//Time complexity would be O(1) since it can be done in constant time
//there are only if statements that run once
bool Date::setDay(int day, int month, int year) {

	if(year == 0 || month == 0)								//returns false if the user didn't set year first and also prompts them
	{
			return false;
	}


	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {		//for all the months that have at most 31 days
		if (day >= 1 && day <= 31){				//return true if the number of days is between 1-31 and store it
			this->day = day;
			return true;
		}

		else {									//if it is not 1-31 return false
			return false;
		}
	}


	else if(month == 4 || month == 6 || month == 9 || month == 11) {		//for all the months that have at most 31 days
			if (day >= 1 && day <= 30){				//return true if the number of days is between 1-30 and store it
				this->day = day;
				return true;
			}

			else {									//if it is not 1-30 return false
				return false;
			}
		}


	else if(month == 2) {		//for all the months that have at most 28 days
			if (day >= 1 && day <= 28){				//return true if the number of days is between 1-28 and store it
				this->day = day;
				return true;
			}

			else {									//if it is not 1-28 return false
				return false;
			}
		}
	else{													//returns false if the number is greater than 31 or less than 1
		return false;
	}

}


//Time complexity would be O(1) since it can be done in constant time
int Date::getMonth() const {
	return month;
}

//Time complexity would be O(1) since it can be done in constant time
bool Date::setMonth(int month, int year) {
	if(year == 0)								//returns false if the user didn't set year first and also prompts them
	{
		return false;
	}

	else if (month >= 1 && month <= 12) {		//returns true if month is between 1-12
		this->month = month;
		return true;
	}

	else{
		return false;						//returns false if month is not between 1-12
	}
}



//Time complexity would be O(1) since it can be done in constant time
int Date::getYear() const {
	return year;
}



//Time complexity would be O(1) since it can be done in constant time
bool Date::setYear(int year) {
	if (year >= 1 && year <= 9999 ) {		//returns true if year is between 1 - 9999
		this->year = year;
		return true;
	}

	else{
		return false;					//returns true if year is not between 1 - 9999
	}
}


//Time complexity would be O(1) since it can be done in constant time
bool Date::operator == (Date &rightDate) {
	if ((this->day == rightDate.day) && (this->month == rightDate.month) && (this->year == rightDate.year)) {
		return true;
	}
	else {						//if the dates aren't equal return false
		return false;
	}
}




//Time complexity would be O(1) since it can be done in constant time
std::ostream& operator<<(std::ostream& date, Date &theDate) {

	if ((theDate.getYear() == 0) || (theDate.getMonth() == 0) || (theDate.getDay() == 0))		//if the date isn't set
	{
//		date << "Invalid date sent";
	}
	else if ((theDate.getMonth() >= 1) && (theDate.getMonth() < 10))    //if months are single digits
	{
		if((theDate.getDay() >= 1) && (theDate.getDay() < 10)){
			date << "0" << theDate.getMonth() << "/0" << theDate.getDay() << "/" << theDate.getYear();
		}
		else{
			date << "0" << theDate.getMonth() << "/" << theDate.getDay() << "/" << theDate.getYear();
		}

	}

	else{																						//if months are double digits
		if ((theDate.getDay() >= 1) && (theDate.getDay() < 10)) {
			date << theDate.getMonth() << "/0" << theDate.getDay() << "/"
					<< theDate.getYear();
		} else {
			date << theDate.getMonth() << "/" << theDate.getDay() << "/"
					<< theDate.getYear();
		}
	}

	return date;
}

//Time complexity would be O(1) since it can be done in constant time
bool Date::operator < (Date &rightDate){

	if (this->year < rightDate.year){ 		//If the year of the left hand date is less than the right hand date, return true
		return true;
	}

	else if ((this->year == rightDate.year) && (this->month < rightDate.month)) //If the year of the two dates are equal, but the left date’s month is less than the right date’s month, return true
	{
		return true;
	}

	else if((this->year == rightDate.year) && (this->month == rightDate.month) && (this->day < rightDate.day) ) {//If the year and the month are equal, but the left date’s day is less than the right date’s day, return true
		return true;
	}

	else{
		return false;
	}
}


//Time complexity would be O(1) since it can be done in constant time
bool Date::operator > (Date &rightDate){
	if (this->year > rightDate.year){ 		//If the year of the left hand date is greater than the right hand date, return true
		return true;
	}

	else if ((this->year == rightDate.year) && (this->month > rightDate.month)) //If the year of the two dates are equal, but the left date’s month is greater than the right date’s month, return true
	{
		return true;
	}

	else if((this->year == rightDate.year) && (this->month == rightDate.month) && (this->day > rightDate.day) ) {//If the year and the month are equal, but the left date’s day is greater than the right date’s day, return true
		return true;
	}

	else{
		return false;
	}
}
