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
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
 */
#include "Date.h"

//TODO: javadocs

Date::Date() {
	this->createMonths();
	this->setMonth(1);
	this->setYear(2012);
	this->setDay(1);
}

Date::Date(int year, int month, int day) {
	this->createMonths();
	this->setMonth(month);
	this->setYear(year);
	this->setDay(day);
}

Date::Date(const Date& date) {
	this->createMonths();
	this->setMonth(date.myMonth);
	this->setYear(date.myYear);
	this->setDay(date.myDay);
}

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

void Date::checkDays() {
	if (myDay > months[myMonth].days) {
		this->setDay(months[myMonth].days);
	}
}

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


int Date::getDay() const {
	return myDay;
}

int Date::getDaysInMonth() const {
	return months[myMonth].days;
}

int Date::getMonth() const {
	return myMonth;
}

const std::string& Date::getMonthName() const {
	return months[myMonth].name;
}

int Date::getYear() const {
	return myYear;
}

bool Date::isLeapYear() const {
	return this->isLeapYear(myYear);
}

bool Date::isLeapYear(int year) const {
	if (year % 4 == 0) {
		if ((year % 100 == 0) && (year % 400 != 0)) {
			return false;
		}
		return true;
	}
	return false;
}

const std::string& Date::serializeDate() {
	std::stringstream ss;
	ss << ((myYear < 1000) ? "0" : "");
	ss << ((myYear < 100) ? "0" : "");
	ss << ((myYear < 10) ? "0" : "");
	ss << myYear << "/";
	ss << ((myMonth < 10) ? "0" : "");
	ss << myMonth << "/";
	ss << ((myDay < 10) ? "0" : "");
	ss << myDay;
	myString = ss.str();
	return myString;
}

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
	myDay = day;
}

void Date::setMonth(int month) {
	while (month > 12) {
		month -= 12;
		this->setYear(myYear + 1);
	}
	while (month < 1) {
		month += 12;
		this->setYear(myYear - 1);
	}
	myMonth = month;
	this->checkDays();
}

void Date::setYear(int year) {
	if (this->isLeapYear(year)) {
		months[2] = Month("February", 29);
	} else {
		months[2] = Month("February", 28);
	}
	myYear = year;
}