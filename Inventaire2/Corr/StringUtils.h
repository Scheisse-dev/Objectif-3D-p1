#pragma once
#include <string>
class StringUtils
{
public:
	static std::string Replace(const std::string& _str, const char _old, const char _new); 
	static std::string Replace(const std::string& _str, const std::string& _old, const std::string& _new);
	
};

