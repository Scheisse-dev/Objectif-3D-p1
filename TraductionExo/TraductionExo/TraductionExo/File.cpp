#include "File.h"
#include "Path.h"
#include "Directory.h"
#include "FileStream.h"
#include <fstream>

#pragma region constructor
File::File(const std::string& _path)
{
	path = _path;
}

File::File(const File& _copy)
{
	path = _copy.path;
}
#pragma endregion constructor
#pragma region methods

bool File::Exist(const std::string& _path)
{
	std::ifstream _stream = std::ifstream(_path);
	const bool _exist = _stream.good();
	_stream.close();
	return _exist;
}
FileStream* File::Create(const std::string& _path)
{
	const std::string& _directoryPath = Path::GetDirectoryPath(_path);
	if (!Directory::Exist(_directoryPath))
		Directory::Create(_directoryPath);
	return new FileStream(_path);
}
#pragma endregion methods