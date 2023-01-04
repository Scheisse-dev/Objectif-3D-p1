#include "Uri.h"

#pragma region constructor
Core::Net::Uri::Uri(const PrimitiveType::FString& _path)
{
	path = _path; 
}

Core::Net::Uri::Uri(const Uri& _copy)
{
	path = _copy.path;
}

#pragma endregion constructor
#pragma region override
Core::PrimitiveType::FString Core::Net::Uri::ToString() const
{
	return PrimitiveType::FString::Format("Path: {}", path);
}
Core::PrimitiveType::FString Core::Net::Uri::Path() const
{
	return path; 
}
int Core::Net::Uri::GetHashCode() const
{
	return path.GetHashCode(); 
}

#pragma endregion override
#pragma region operator
Core::Net::Uri::operator LPCWSTR() const
{
	const std::wstring _path = path.ToWString(); 
	return _path.c_str(); 
}
#pragma endregion operator

