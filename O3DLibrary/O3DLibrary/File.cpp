#include "File.h"
#include "Boolean.h"
#include "FileStream.h"
#include "TextReader.h"
#include "TextWritter.h"
#include "FString.h"
#include <fstream>

#pragma region constructor/destructor
Core::IO::File::File(const char* _path)
{
	path = _path; 
}

Core::IO::File::File(const File& _copy)
{
	path = _copy.path; 
}
Core::IO::File::~File()
{
	delete path;
	path = nullptr; 
}

#pragma endregion constructor/destructor

#pragma region methods
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::IO::File::Exist(const Core::PrimitiveType::FString& _path)
{
	std::ifstream _stream = std::ifstream(_path.ToCstr());
	const bool _result = _stream.good();
	_stream.close();
	return _result;
}
O3DLIBRARY_API Core::IO::FileStream* Core::IO::File::Create(const PrimitiveType::FString& _path)
{
	if (Exist(_path)) return new FileStream(_path.ToCstr());
	const char* _pathCstr = _path.ToCstr();
	std::ofstream _stream = std::ofstream(_pathCstr);
	return new FileStream(_pathCstr); 
}

#pragma endregion methods