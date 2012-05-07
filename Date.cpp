/*
 * =====================================================================================
 *
 *       Filename:  Date.cpp
 *
 *    Description:  Class implementation for Date
 *
 *        Version:  1.0
 *        Created:  04/25/2012 20:50:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Justin Ridgewell
 *	 Comments:  Andrew Wagenheim
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
 */
#include "Date.h"

/*
* Default constructor, creates a new date with default values
* Pre: None
* Post: Date created with default values
*/
Date::Date() {
	myNull = false;
	this->createMonths();
	this->setMonth(1);
	this->setYear(2012);
	this->setDay(1);
}

/*
* Creates a new date passed in values
* Pre: Values for the year, month and day are passed in as ints
* Post: Date created with input values
*/
Date::Date(const int year, const int month, const int day) {
	myNull = false;
	this->createMonths();
	this->setMonth(month);
	this->setYear(year);
	this->setDay(day);
}

/*
* Clones an existing date
* Pre: An existing date object is passed in
* Post: A new date is made using the same values
*/
Date::Date(const Date& date) {
	this->createMonths();
	this->setMonth(date.myMonth);
	this->setYear(date.myYear);
	this->setDay(date.myDay);
	myNull = date.myNull;
}

/*
* Creates a new date out of one input in YYYY/MM/DD format
* Pre: A date string is passed in the format YYYY/MM/DD
* Post: The values for the date are extracted and made into a new date object
*/
Date::Date(std::string date) {
	this->createMonths();
	char* string = &date[0];
	char* split;
	split = strtok(string, "/");
	this->setYear(atoi(split));
	split = strtok(NULL, "/");
	this->setMonth(atoi(split));
	split = strtok(NULL, "/");
	this->setDay(atoi(split));
}

/*
* Checks the validity of the current myDay value
* Pre: None
* Post: If the day is found to be invalid, it is rounded down to the highest possible day
ct
*/
void Date::checkDays() {
	if (myDay > months[myMonth].days) {
		this->setDay(months[myMonth].days);
	}
}

/*
* Creates an array of months and their corresponding number of days
* Pre: None
* Post: An array is made with each month and its number of days assigned to a spot in the array
*/
void Date::createMonths() {
	this->months[0] = Month("", 31);
	this->months[1] = Month("January", 31);
	this->months[2] = Month("February", 28);
	this->months[3] = Month("March", 31);
	this->months[4] = Month("April", 30);
	this->months[5] = Month("May", 31);
	this->months[6] = Month("June", 30);
	this->months[7] = Month("July", 31);
	this->months[8] = Month("August", 31);
	this->months[9] = Month("September", 30);
	this->months[10] = Month("October", 31);
	this->months[11] = Month("November", 30);
	this->months[12] = Month("December", 31);
	this->months[13] = Month("", 31);
}

/*
* Gets the day of the date
* Pre: None
* Post: Returns the date's day value
*/
int Date::getDay() const {
	return myDay;
}

/*
* Gets the number of days in the month of the date
* Pre: None
* Post: Returns the number of days in the month of the date
*/
int Date::getDaysInMonth() const {
	return months[myMonth].days;
}

/*
* Gets the number month of the date
* Pre: None
* Post: Returns the date's month's number value
*/
int Date::getMonth() const {
	return myMonth;
}

/*
* Gets the name of the month of the date
* Pre: None
* Post: Returns the date's month's name
*/
const std::string& Date::getMonthName() const {
	return months[myMonth].name;
}

/*
* Gets the year of the date
* Pre: None
* Post: Returns the date's year
*/
int Date::getYear() const {
	return myYear;
}


/*
* Checks to see if the myYear value is a leap year
* Pre: None
* Post: Runs the isLeapYear method using the myYear value. Returns true if it is a leap year, returns false if it is not.
*/
bool Date::isLeapYear() const {
	return this->isLeapYear(myYear);
}

/*
* Computes if the input year is a leap year
* Pre: A year is input at an int
* Post: Returns true if the input year is a leap year, returns false if it is not
*/
bool Date::isLeapYear(int year) const {
	if (year % 4 == 0) {
		if ((year % 100 == 0) && (year % 400 != 0)) {
			return false;
		}
		return true;
	}
	return false;
}

/*
* Converts int values of a date into a string with the format YYYY/MM/DD
* Pre: None
* Post: Returns a string in the format YYYY/MM/DD using the myYear, myMonth and myDay value
*/
std::string Date::serializeDate() const {
	std::stringstream ss;
	ss << ((myYear < 1000) ? "0" : "");
	ss << ((myYear < 100) ? "0" : "");
	ss << ((myYear < 10) ? "0" : "");
	ss << myYear << "/";
	ss << ((myMonth < 10) ? "0" : "");
	ss << myMonth << "/";
	ss << ((myDay < 10) ? "0" : "");
	ss << myDay;
	return ss.str();
}

/*
* Sets the myDay value to the input, checking to make sure the input value is valid
* Pre: A value is input as an int for the new myDay
* Post: The myDay value is set to the input value, where a value less than 1 or greater than the maximum number of days wraps around and sets the month accordingly
*/
void Date::setDay(int day) {
	int daysInMonth = months[myMonth].days;
	while (day > daysInMonth) {
		day -= daysInMonth;
		this->setMonth(myMonth + 1);
	}
	while (day < 1) {
		day += months[myMonth - 1].days;
		this->setMonth(myMonth - 1);
	}
	myNull = false;
	myDay = day;
}

/*
* Sets the myMonth value to the input, checking to make sure the value is valid
* Pre: A value is input as an int for the new myMonth
* Post: The myMonth value is set to the input value, where a value less than 1 or greater than 12 wraps around and decrements or increments the year respectively
*/
void Date::setMonth(int month) {
	while (month > 12) {
		month -= 12;
		this->setYear(myYear + 1);
	}
	while (month < 1) {
		month += 12;
		this->setYear(myYear - 1);
	}
	myNull = false;
	myMonth = month;
	this->checkDays();
}

/*
* Sets the myYear value to the input, checking to make sure the value is valid
* Pre: A value is input as an int for the new myYear
* Post: The myYear value is set to the input value, where the year is checked to be a leap year, and changes the maximum number of days in February accordingly
*/
void Date::setYear(int year) {
	if (this->isLeapYear(year)) {
		months[2] = Month("February", 29);
	} else {
		months[2] = Month("February", 28);
	}
	myNull = false;
	myYear = year;
}

void Date::setNull() {
	myNull = true;
}

bool Date::isNull() const {
	return myNull;
}

bool Date::operator==(const Date& date) const {
	bool b = false;
	if (myYear == date.myYear && myMonth == date.myMonth && myDay == date.myDay) {
		b = true;
	}
	
	return b;
}
