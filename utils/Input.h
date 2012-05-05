#ifndef INPUT_H
#define INPUT_H
/*
 *
 */

#include <iostream>
#include <string>

struct Input {
	static std::istream& getLine(std::string& str, std::istream& in = std::cin, char delim = '\n');
	static bool isNumeric(std::string& str, std::istream& in = std::cin);
};

#endif
