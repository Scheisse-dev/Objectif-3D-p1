#include "StringUtils.h"
#include <algorithm>
#include <sstream>

std::string StringUtils::Replace(const std::string& _str, const char _old, const char _new)
{
	std::string _result = _str;
	std::ranges::replace(_result, _old, _new);
	return _result; 
}

bool StringUtils::Contains(const std::string& _str, const char _value)
{
	return _str.find(_value) != std::string::npos;
}

std::vector<std::string> StringUtils::Split(const std::string& _str, const char _c)
{
	std::vector<std::string> _result = std::vector<std::string>(); 
	std::string _line = ""; 
	std::istringstream _stream(_str);
	while (std::getline(_stream, _line, _c))
	{
		_result.push_back(_line);
	}
	return _result; 
}
