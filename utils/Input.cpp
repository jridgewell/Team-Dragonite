#include "Input.h"

std::istream& Input::getLine(std::string& str, std::istream& in, const char delim) {
	char ch;
	str = "";

	while (in.get(ch) && ch != delim) {
		str += ch;
	}

	return in;
}

bool Input::getNonEmptyLine(std::string& str, std::istream& in, const char delim) {
	Input::getLine(str, in, delim);
	return (str != "");
}

bool Input::getInteger(int& i, std::istream& in, const char delim) {
	std::string str;
	Input::getLine(str, in, delim);
	if (Input::isNumeric(str)) {
		i = atoi(str.c_str());
		return true;
	}
	return false;
}

bool Input::getPositiveInteger(int& i, std::istream& in, const char delim) {
	return Input::getIntegerInRange(i, std::numeric_limits<int>::max(), 0, in, delim);
}

bool Input::getIntegerInRange(int& i, const int high, const int low, std::istream& in, const char delim) {
	std::string str;
	Input::getLine(str, in, delim);
	if (Input::isNumericPositive(str)) {
		i = atoi(str.c_str());
		if (i >= low && i <= high) {
			return true;
		}
	}
	return false;
}

bool Input::isNumeric(const std::string& str) {
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

bool Input::isNumericPositive(const std::string& str) {
	bool b = Input::isNumeric(str);
	if (b) {
		b = (str[0] != '-');
	}
	return b;
}

void Input::wait(const std::string str, std::ostream& out, std::istream& in, const char delim) {
	out << str << std::endl;
	char ch;

	while (in.get(ch) && ch != delim) {
	}
}
