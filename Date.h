#ifndef DATE_H
#define DATE_H
/*
 * =====================================================================================
 *
 *       Filename:  Date.h
 *
 *    Description:  Header file for Date class
 *
 *        Version:  1.0
 *        Created:  04/25/2012 20:50:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Justin Ridgewell
 *       Comments:  Andrew Wagenheim
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
 */
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>


/*
* Outlines the Date class and the features contained therein.
* Dates consist of a day, month, and year
* Creates dates through one of the following:
* 1) A default constructor
* 2) A constructor with passed in values
* 3) An existing date object, copying its values
* 4) Date data retrieved from a node on the YAML
* In addition, the class is able to set/get the date's values using accessor methods
*/

struct Month {
	std::string name;
	int days;
	Month() {
		this->name = "";
		this->days = 0;
	}
	Month(std::string n, int d) {
		this->name = n;
		this->days = d;
	}
};

class Date {
	private:
		Month months[14];
		int myDay;
		int myMonth;
		int myYear;
		void checkDays();
		void createMonths();
	public:
		Date();
		Date(int year, int month, int day);
		Date(const Date& date);
		Date(std::string date);
		~Date() {}
		int getDay() const;
		int getDaysInMonth() const;
		int getMonth() const;
		const std::string& getMonthName() const;
		int getYear() const;
		bool isLeapYear() const;
		bool isLeapYear(int year) const;
		std::string serializeDate() const;
		void setDay(int day);
		void setMonth(int month);
		void setYear(int year);
};
#endif
