#include "Input.h"

std::istream& Input::getLine(std::string& str, std::istream& in, char delim) {
	char ch;
	str = "";

	while (in.get(ch) && ch != delim) {
		str += ch;
	}

	return in;
}

bool Input::isNumeric(std::string& str, std::istream& in)
{
	for(int i = 0; i < str.length(); i++)
	{
		if( !(s[i] >= '0' && s[i] <= '9' || s[i] == ' '))
			return false;
	}
	return true;
}
