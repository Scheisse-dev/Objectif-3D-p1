#include "pch.h"
#include "Exception.h"
#include <format>


#pragma region constructor
Core::Exception::Exception::Exception(const Core::PrimitiveType::FString& _error, const std::source_location& _location)
{
	error = std::format("{} in class {} in {} at {} line", _error.ToCstr(), _location.file_name(), _location.function_name(), _location.line()).c_str();
}
#pragma endregion constructor
#pragma region override
O3DLIBRARY_API Core::PrimitiveType::FString Core::Exception::Exception::ToString() const
{
	return error; 
}
#pragma endregion override