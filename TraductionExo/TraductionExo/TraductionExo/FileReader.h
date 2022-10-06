#pragma once
#include <fstream>
#include <string>
#include <vector>

class FileReader
{
#pragma region f/p
private:
	std::string path = "";
	std::ifstream stream = std::ifstream();
#pragma endregion f/p
#pragma region constructor
public:
	FileReader() = default;
	FileReader(const std::string& _path);
	FileReader(const FileReader& _copy);
#pragma endregion constructor
#pragma region methods
public:
	bool IsOpen() const;
	void Close();
	std::vector<std::string> GetAllLines();
#pragma endregion methods
};

