#pragma once
#include <string>

class FileWriter;
class FileReader;

class FileStream
{
#pragma region f/p
private:
	FileWriter* writer = nullptr;
	FileReader* reader = nullptr;
#pragma endregion f/p
#pragma region constructor
public:
	FileStream() = default;
	FileStream(const std::string& _path);
	FileStream(const FileStream& _copy);
#pragma endregion constructor
#pragma region methods
public:
	void Close() const;
	FileWriter* Writer() const;
	FileReader* Reader() const;
	bool IsValid() const;
#pragma endregion methods
};

