#include "Input.h"

std::istream& Input::getLine(std::istream& in, std::string& str, char delim) {
	char ch;
	str = "";

	while (in.get(ch) && ch != delim) {
		str += ch;
	}

	return in;
}
