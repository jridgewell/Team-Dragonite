#include "Input.h"

std::istream& Input::getLine(std::string& str, std::istream& in, char delim) {
	char ch;
	str = "";

	while (in.get(ch) && ch != delim) {
		str += ch;
	}

	return in;
}

bool Input::isNumeric(std::string& str) {
	unsigned i = 0;
	if (str[0] == '-') {
		i = 1;
	}
	for ( ; i < str.length(); ++i) {
		if (!(str[i] >= '0' && str[i] <= '9')) {
			return false;
		}
	}
	return true;
}

void Input::wait(std::string str, std::ostream& out, std::istream& in, char delim) {
	out << str << std::endl;
	char ch;

	while (in.get(ch) && ch != delim) {
	}
}
