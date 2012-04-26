#include "../Date.h"
#include <gtest/gtest.h>

TEST(Date, Constructor) {
	Date d = Date(11, 11, 1111);
	EXPECT_EQ(d.getDay(), 11);
	EXPECT_EQ(d.getMonth(), 11);
	EXPECT_EQ(d.getYear(), 1111);
}

TEST(Date, DefaultConstructor) {
	Date d = Date();
	EXPECT_EQ(d.getDay(), 1);
	EXPECT_EQ(d.getMonth(), 1);
	EXPECT_EQ(d.getYear(), 2012);
}

TEST(Date, CopyConstructor) {
	Date d = Date(11, 11, 1111);
	Date d2 = d;
	EXPECT_EQ(d.getDay(), d2.getDay());
	EXPECT_EQ(d.getMonth(), d2.getMonth());
	EXPECT_EQ(d.getYear(), d2.getYear());
}

TEST(Date, IsLeapYear) {
	Date d = Date(2, 28, 4);
	EXPECT_EQ(d.isLeapYear(), true);
	EXPECT_EQ(d.getDaysInMonth(), 29);
	d.setYear(100);
	EXPECT_EQ(d.isLeapYear(), false);
	EXPECT_EQ(d.getDaysInMonth(), 28);
	d.setYear(400);
	EXPECT_EQ(d.isLeapYear(), true);
	EXPECT_EQ(d.getDaysInMonth(), 29);
}

TEST(Date, IncreaseDayMonthYear) {
	Date d = Date(12, 31, 2012);
	d.setDay(d.getDay() + 1);
	EXPECT_EQ(d.getDay(), 1);
	EXPECT_EQ(d.getMonth(), 1);
	EXPECT_EQ(d.getYear(), 2013);
}

TEST(Date, IncreaseDayMonth) {
	Date d = Date(1, 31, 2012);
	d.setDay(d.getDay() + 1);
	EXPECT_EQ(d.getDay(), 1);
	EXPECT_EQ(d.getMonth(), 2);
	EXPECT_EQ(d.getYear(), 2012);
	d.setMonth(1);
	d.setYear(2012);
	d.setDay(31);
	d.setDay(d.getDay() + 10);
	EXPECT_EQ(d.getDay(), 10);
	EXPECT_EQ(d.getMonth(), 2);
	EXPECT_EQ(d.getYear(), 2012);
}

TEST(Date, DecreaseDayMonthYear) {
	Date d = Date(1, 1, 2012);
	d.setDay(d.getDay() - 1);
	EXPECT_EQ(d.getDay(), 31);
	EXPECT_EQ(d.getMonth(), 12);
	EXPECT_EQ(d.getYear(), 2011);
}

TEST(Date, DecreaseDayMonth) {
	Date d = Date(2, 1, 2012);
	d.setDay(d.getDay() - 1);
	EXPECT_EQ(d.getDay(), 31);
	EXPECT_EQ(d.getMonth(), 1);
	EXPECT_EQ(d.getYear(), 2012);
	d.setMonth(2);
	d.setYear(2012);
	d.setDay(1);
	d.setDay(d.getDay() - 10);
	EXPECT_EQ(d.getDay(), 22);
	EXPECT_EQ(d.getMonth(), 1);
	EXPECT_EQ(d.getYear(), 2012);
}

TEST(Date, IncreaseMonthDay) {
	Date d = Date(1, 31, 2012);
	d.setMonth(d.getMonth() + 1);
	EXPECT_EQ(d.getDay(), 29);
	EXPECT_EQ(d.getMonth(), 2);
	EXPECT_EQ(d.getYear(), 2012);
}

TEST(Date, DecreaseMonthDay) {
	Date d = Date(3, 31, 2012);
	d.setMonth(d.getMonth() - 1);
	EXPECT_EQ(d.getDay(), 29);
	EXPECT_EQ(d.getMonth(), 2);
	EXPECT_EQ(d.getYear(), 2012);
}

TEST(Date, DateFromString) {
	std::string str = "2000/02/29";
	Date d = Date(str);
	EXPECT_EQ(d.getDay(), 29);
	EXPECT_EQ(d.getMonth(), 2);
	EXPECT_EQ(d.getYear(), 2000);
}

TEST(Date, DateToString) {
	Date d = Date(2000, 02, 29);
	EXPECT_EQ(d.serializeDate(), "2000/02/29");
	d.setYear(4);
	d.setMonth(2);
	d.setDay(1);
	EXPECT_EQ(d.serializeDate(), "0004/02/01");
}