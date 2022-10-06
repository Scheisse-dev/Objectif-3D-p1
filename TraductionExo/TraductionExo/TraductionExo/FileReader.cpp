#include "FileReader.h"

#pragma region constructor
FileReader::FileReader(const std::string& _path)
{
	path = _path;
	stream = std::ifstream(_path);
}

FileReader::FileReader(const FileReader& _copy)
{
	path = _copy.path;
	stream = std::ifstream(_copy.path);
}

#pragma endregion constructor

#pragma region methods
bool FileReader::IsOpen() const
{
	return stream.is_open();
}
void FileReader::Close()
{
	if (!IsOpen()) return;
	stream.close();
}
std::vector<std::string> FileReader::GetAllLines()
{
	std::vector<std::string> _result = std::vector<std::string>();
	std::string _str = "";
	while (std::getline(stream, _str))
	{
		_result.push_back(_str);
	}
	return _result;
}
#pragma endregion methods