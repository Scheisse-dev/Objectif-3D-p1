#pragma once
#include "../../Object/Object.h"
#include <vector>

class StringUtils : public Object
{
public: 
	static std::string Replace(const std::string& _str, const char _old, const char _new); 
	static bool Contains(const std::string& _str, const char _value);
	static std::vector<std::string> Split(const std::string& _str, const char _c); 
};

