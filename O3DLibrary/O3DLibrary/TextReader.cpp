#include "TextReader.h"
#include "FString.h"
#include "Boolean.h"

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

#pragma region methods

void Core::IO::TextReader::Close()
{
	if(!IsOpen()) return;
	stream.close();
}
Core::PrimitiveType::Boolean Core::IO::TextReader::IsOpen() const
{
	return stream.is_open(); 
}
Core::PrimitiveType::Boolean Core::IO::TextReader::IsValid() const
{
	return stream.good() && stream.is_open(); 
}
Core::PrimitiveType::Boolean Core::IO::TextReader::ReadeLine(PrimitiveType::FString& _out)
{
	if (!IsOpen()) return false;
	std::string _str = "";
	std::getline(stream, _str); 
	_out = _str.c_str(); 
	return !Core::PrimitiveType::FString::IsNullOrEmpty(_out); 
}
Core::PrimitiveType::Boolean Core::IO::TextReader::ReadeLine()
{
	if (!IsOpen()) return false;
	std::string _str = "";
	std::getline(stream, _str);
	return _str.c_str(); 
}
Core::PrimitiveType::FString Core::IO::TextReader::ReadToEnd()
{
	Core::PrimitiveType::FString _result = ""; 
	std::string _str = ""; 
	while (std::getline(stream, _str))
	{
		_result += _str.c_str(); 
		_result += " "; 
	}
	return _result; 
}
Core::PrimitiveType::FString Core::IO::TextReader::Path() const
{
	return path; 
}

O3DLIBRARY_API Core::PrimitiveType::Boolean Core::IO::TextReader::Equals(const TextReader& _textReader) const 
{
	return path == _textReader.path; 
}



#pragma endregion methods

#pragma region override

O3DLIBRARY_API Core::PrimitiveType::FString Core::IO::TextReader::ToString() const
{
	return path;
}

O3DLIBRARY_API Core::PrimitiveType::Boolean Core::IO::TextReader::Equals(const Object* _obj) const
{
	const TextReader* _other = dynamic_cast<const TextReader*>(_obj);
	if (_other == nullptr) return false; 
	return Equals(*_other); 
}
#pragma endregion override