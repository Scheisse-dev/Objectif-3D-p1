#include "File.h"
#include <fstream>

#pragma region methods
bool File::Exist(const std::string& _path)
{
	std::ifstream _stream = std::ifstream(_path);
	const bool _result = _stream.good();
	_stream.close();
	return _result;
}

std::string File::ReadToEnd(const std::string& _path)
{
	std::ifstream _stream = std::ifstream(_path);
	std::string _result = "", _line = "";
	while (std::getline(_stream, _line))
	{
		_result += _line + "\n";
	}
	_stream.close();
	return _result; 
}
#pragma endregion methods