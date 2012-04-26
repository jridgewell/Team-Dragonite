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
 *   Organization:  Team Dragonite
 *
 * =====================================================================================
 */
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

//TODO: javadocs

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
		std::string myString;
		void checkDays();
		void createMonths();
	public:
		Date();
		Date(int day, int month, int year);
		Date(const Date & date);
		Date(std::string date);
		~Date() {}
		int getDay();
		int getDaysInMonth();
		int getMonth();
		const std::string& getMonthName();
		int getYear();
		bool isLeapYear();
		bool isLeapYear(int year);
		const std::string& serializeDate();
		void setDay(int day);
		void setMonth(int month);
		void setYear(int year);
};
#endif