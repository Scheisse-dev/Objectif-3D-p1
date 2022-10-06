#pragma once
#include <string>

class Path
{
public:
	static const char DirectorySeparatorChar = '/';
	static std::string Combine(const std::string& _a, const std::string& _b);
	static std::string Combine(const std::string& _a, const std::string& _b, const std::string& _c);
	static std::string GetPath(const std::string& _path);
	static std::string GetDirectoryPath(const std::string& _path);
};

