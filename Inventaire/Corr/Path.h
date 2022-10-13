#pragma once
#include <string>
class Path
{
public: 
	static std::string GetPath(const std::string& _path); 
	static std::string Combine(const std::string& _a, const std::string& _b, const std::string& _c); 
};

