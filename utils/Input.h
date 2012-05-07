#ifndef INPUT_H
#define INPUT_H
/*
 *
 */

#include <iostream>
#include <string>

struct Input {
	static std::istream& getLine(std::string& str, std::istream& in = std::cin, const char delim = '\n');
	static bool getInteger(int& i, std::istream& in = std::cin, const char delim = '\n');
	static bool isNumeric(const std::string& str);
	static bool isNumericPositive(const std::string& str);
	static void wait(const std::string str = std::string("Press enter to continue"), std::ostream& out = std::cout, std::istream& in = std::cin, const char delim = '\n');
};

#endif
