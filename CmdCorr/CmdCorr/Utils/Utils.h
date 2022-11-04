#pragma once
#include "../Object/Object.h"
#include <vector>

#pragma comment(lib, "version.lib")

class Utils : public Object
{
public:
	static std::string GetWindowsVersion();
	static std::vector < std::string> GetArguments(const std::string& _command, std::string& _commandLabel);
};

