#include "TextReader.h"
#include "FString.h"

#pragma region constructor
Core::IO::TextReader::TextReader(const char* _path)
{
	path = _path;
	stream = std::ifstream(_path);
}

Core::IO::TextReader::TextReader(const PrimitiveType::FString& _path)
	:TextReader(_path.ToCstr())
{
}

Core::IO::TextReader::TextReader(const TextReader& _copy)
{
	path = _copy.path;
	stream = std::ifstream(path);
}
#pragma endregion constructor