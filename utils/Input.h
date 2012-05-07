#ifndef INPUT_H
#define INPUT_H
/*
 *
 */

#include <iostream>
#include <string>

struct Input {
	static std::istream& getLine(std::string& str, std::istream& in = std::cin, char delim = '\n');
	static bool isNumeric(std::string& str);
	static void wait(std::string str = std::string("Press enter to continue"), std::ostream& out = std::cout, std::istream& in = std::cin, char delim = '\n');
};

#endif
