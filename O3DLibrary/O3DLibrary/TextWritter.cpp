#include "TextWritter.h"
#include "FString.h"
#include "Boolean.h"

#pragma region constructor
Core::IO::TextWritter::TextWritter(const char* _path)
{
	path = _path;
	stream = std::ofstream(_path, std::ios_base::app | std::ios_base::out);
}

Core::IO::TextWritter::TextWritter(const PrimitiveType::FString& _path)
	:TextWritter(_path.ToCstr())
{

}

Core::IO::TextWritter::TextWritter(const TextWritter& _copy)
{
	path = _copy.path;
	stream = std::ofstream(path, std::ios_base::app | std::ios_base::out); 
}

#pragma endregion constructor

#pragma region methods 
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::IO::TextWritter::IsOpen() const
{
	return stream.is_open(); 
}
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::IO::TextWritter::Exist() const
{
	return stream.good();
}
O3DLIBRARY_API Core::PrimitiveType::FString Core::IO::TextWritter::Path() const
{
	return path; 
}
O3DLIBRARY_API void Core::IO::TextWritter::Close()
{
	if (stream.is_open())
		stream.close();
}
O3DLIBRARY_API void Core::IO::TextWritter::Clear()
{
	Close();
	stream = std::ofstream(path, std::ofstream::out | std::ofstream::trunc);
}
O3DLIBRARY_API void Core::IO::TextWritter::Write(const Object& _obj)
{
	*this << _obj; 
}
O3DLIBRARY_API void Core::IO::TextWritter::Write(const Object* _obj)
{
	*this << _obj;
}

O3DLIBRARY_API Core::PrimitiveType::Boolean Core::IO::TextWritter::Equals(const TextWritter& _obj) const
{
	return path == _obj.path;
}
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::IO::TextWritter::Equals(const TextWritter& _obj) const
{
	return path == _obj.path;
}

#pragma endregion methods 
#pragma region override
O3DLIBRARY_API Core::PrimitiveType::FString Core::IO::TextWritter::ToString() const
{
	return path;
}

O3DLIBRARY_API Core::PrimitiveType::Boolean Core::IO::TextWritter::Equals(const Object* _obj) const
{
	const TextWritter* _other = dynamic_cast<const TextWritter*>(_obj);
	if (_other == nullptr) return false;
	return Equals(*_other);
}



#pragma endregion override

#pragma region operator
O3DLIBRARY_API void Core::IO::TextWritter::operator<<(const Object& _obj)
{
	if (!IsOpen()) return;
	stream << _obj.ToString(); 
	stream << std::endl; 
}

O3DLIBRARY_API void Core::IO::TextWritter::operator<<(const Object* _obj)
{
	if (!IsOpen()) return;
	stream << _obj->ToString();
	stream << std::endl;
}
#pragma endregion operator