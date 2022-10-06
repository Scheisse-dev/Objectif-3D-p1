#pragma once
#include <string>

class FileStream;

class File
{
#pragma region f/p
private:
	std::string path = "";
#pragma endregion f/p
#pragma region constructor
public:
	File() = default;
	File(const std::string& _path);
	File(const File& _copy);
#pragma endregion constructor
#pragma region methods
public:
	static bool Exist(const std::string& _path);
	static FileStream* Create(const std::string& _path);
#pragma endregion methods
};

