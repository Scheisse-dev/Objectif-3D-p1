#pragma once
#include <string>
#include <vector>

class StringUtils
{
public:
	static std::vector<std::string> Split(const std::string& _str, const char _c);
	static std::string Replace(const std::string& _str, const std::string& _old, const std::string& _new);
};

