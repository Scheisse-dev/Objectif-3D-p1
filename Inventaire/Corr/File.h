#pragma once
#include <iostream>
#include <vector>
class File
{
public:
	static std::vector<std::string> GetAllLines(const std::string& _path); 
};

