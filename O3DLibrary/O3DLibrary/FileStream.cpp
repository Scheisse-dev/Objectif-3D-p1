#include "FileStream.h"
#include "TextReader.h"
#include "TextWritter.h" 
#include "FString.h"
#include "Boolean.h"

#pragma region constructor/desructor
Core::IO::FileStream::FileStream(const char* _path)
{
	path = _path;
	reader = new TextReader(_path);
	writter = new TextWritter(_path); 
}

Core::IO::FileStream::FileStream(const FileStream& _copy)
{
	path = _copy.path;
	reader = _copy.reader;
	writter = _copy.writter;
}

Core::IO::FileStream::~FileStream()
{
	Close(); 
	delete reader;
	reader = nullptr;
	delete writter;
	writter = nullptr;
	delete path;
	path = nullptr; 
}




#pragma endregion constructor/desructor
#pragma region methods
O3DLIBRARY_API void Core::IO::FileStream::Close()
{
	if (writter != nullptr) writter->Close(); 
	if (reader != nullptr) reader->Close(); 

}

O3DLIBRARY_API Core::IO::TextReader* Core::IO::FileStream::Reader() const
{
	return reader;
}

O3DLIBRARY_API  Core::IO::TextWritter* Core::IO::FileStream::Writter() const
{
	return writter;
}

O3DLIBRARY_API Core::PrimitiveType::FString Core::IO::FileStream::Path() const
{
	return path;
}

#pragma endregion methods

#pragma region override
O3DLIBRARY_API Core::PrimitiveType::FString Core::IO::FileStream::ToString() const
{
	return path;
}

O3DLIBRARY_API Core::PrimitiveType::Boolean Core::IO::FileStream::Equals(const Object* _obj) const
{
	const FileStream* _other = dynamic_cast<const FileStream*>(_obj);
	if (_other == nullptr) return false;
	return Equals(*_other); 
}

O3DLIBRARY_API Core::PrimitiveType::Boolean Core::IO::FileStream::Equals(const FileStream& _other) const
{
	return path == _other.path;
}


#pragma endregion override
#pragma region operator
void Core::IO::FileStream::operator<<(const Object* _obj)
{
	if (writter == nullptr) return;
	*writter << _obj;
}

void Core::IO::FileStream::operator<<(const Object& _obj)
{
	if (writter == nullptr) return;
	*writter << _obj;
}
#pragma endregion operator