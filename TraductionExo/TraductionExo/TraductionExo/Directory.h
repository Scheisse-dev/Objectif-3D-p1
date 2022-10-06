#pragma once
#include <string>

class Directory
{
#pragma region f/p
private:
	std::string name = "";
	std::string path = "";
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Directory() = default;
	Directory(const std::string& _path);
#pragma endregion constructor/destructor
#pragma region methods
public:
	std::string Name() const;
	std::string Path() const;
#pragma endregion methods
#pragma region operator
public:
	static Directory* Create(const std::string& _path);
	static bool Exist(const std::string& _path);
	static bool Delete(const std::string& _path);
#pragma endregion operator
};

