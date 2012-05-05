#ifndef INPUT_H
#define INPUT_H
/*
 *
 */

#include <istream>
#include <string>

struct Input {
	static std::istream& getLine(std::istream& in, std::string& str, char delim = '\n');
};

#endif
