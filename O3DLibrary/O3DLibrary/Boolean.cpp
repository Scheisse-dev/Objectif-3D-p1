#include "pch.h"
#include "Boolean.h"
#include "FString.h"

#pragma region constructeur
Core::PrimitiveType::Boolean::Boolean(const bool _value)
{
	value = _value;
}

Core::PrimitiveType::Boolean::Boolean(const Boolean& _copy)
{
	value = _copy.value; 
}

#pragma endregion constructeur
#pragma region override

Core::PrimitiveType::FString Core::PrimitiveType::Boolean::ToString() const
{
	return value ? "true" : "flase";
}

#pragma endregion override
#pragma region operator
Core::PrimitiveType::Boolean Core::PrimitiveType::Boolean::operator==(const Boolean& _other) const
{
	return value == _other.value; 
}
Core::PrimitiveType::Boolean Core::PrimitiveType::Boolean::operator!=(const Boolean& _other) const
{
	return value != _other.value;
}
Core::PrimitiveType::Boolean::operator bool() const
{
	return value;
}
Core::PrimitiveType::Boolean Core::PrimitiveType::Boolean::operator!()
{
	return !value; 
}
#pragma endregion operator