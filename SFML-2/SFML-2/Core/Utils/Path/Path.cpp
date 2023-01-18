#include "Path.h"
#pragma warning(disable : 4996)


std::string Core::Utils::Path::GetPath(const std::string& _path)
{
	const size_t _length = _path.length();
	char* _array = new char[_length];
	strcpy(_array, _path.data());
	for (size_t i = 0; i < _length; i++)
	{
		if (_path[i] == '\\')
			_array[i] = DirectorySeparator;
	}
	return _array;
	

}

std::string Core::Utils::Path::Combine(const std::initializer_list<std::string>& _paths)
{
	std::string _result = "";
	int _index = 0;
	const size_t _size = _paths.size(); 
	for (const std::string& _path : _paths)
	{
		_result +=  _path;
		if (_index < _size - 1)
			_result += DirectorySeparator;
		_index++;
	}
	return GetPath(_result);
}
