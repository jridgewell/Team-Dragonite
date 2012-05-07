#ifndef INPUT_H
#define INPUT_H
/*
 *
 */

#include <iostream>
#include <string>
#include <limits>

struct Input {
	static std::istream& getLine(std::string& str, std::istream& in = std::cin, const char delim = '\n');
	static bool getInteger(int& i, std::istream& in = std::cin, const char delim = '\n');
	static bool getPositiveInteger(int& i, std::istream& in = std::cin, const char delim = '\n');
	static bool getIntegerInRange(int& i, const int high = std::numeric_limits<int>::max(), const int low = std::numeric_limits<int>::min(), std::istream& in = std::cin, const char delim = '\n');
	static bool isNumeric(const std::string& str);
	static bool isNumericPositive(const std::string& str);
	static void wait(const std::string str = std::string("Press enter to continue"), std::ostream& out = std::cout, std::istream& in = std::cin, const char delim = '\n');
};

#endif
