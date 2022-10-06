#pragma once
#include <string>
#include <fstream>

class FileWriter
{
#pragma region f/p
private:
	std::string path = "";
	std::ofstream stream = std::ofstream();
#pragma endregion f/p
#pragma region constructor
public:
	FileWriter() = default;
	FileWriter(const std::string& _path);
	FileWriter(const FileWriter& _copy);
#pragma endregion constructor
#pragma region methods
public:
	bool IsOpen() const;
	void Write(const std::string& _value);
	void Clear();
	void Close();
#pragma endregion methods
};

