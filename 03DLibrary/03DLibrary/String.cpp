#include "pch.h"
#include "String.h"


#pragma warning(disable : 4996)


#pragma region constructor
Core::PrimitiveType::String::String(const char* _value)
{
	if (_value == nullptr) _value = ""; 
	const int _otherLength = strlen(_value); 
	const int _newLength = length + _otherLength; 
	char* _array = new char(_newLength + 1); 
	strcpy(_array, _value);
	strcat(_array, _value);
	value = _array; 
	length = _newLength; 

}

Core::PrimitiveType::String::String(const String& _copy)
{
	if (_copy.value == nullptr) return; 
	const int _length = _copy.length; 
	char* _array = new char(_length + 1);
	memcpy(_array, _copy.value, _length + 1); 
	value = _array; 
	length = _length; 
}

Core::PrimitiveType::String::String(std::string::iterator _begin, std::string::iterator _end)
{
	for (; _begin != _end; ++_begin)
		Append(*_begin); 
}
#pragma endregion constructor

#pragma region methods 
void Core::PrimitiveType::String::Append(const String& _str)
{
	const int _newLength = length + _str.length;
	char* _array = new char[_newLength + 1]; 
	strcpy(_array, _str.value);
	strcat(_array, _str.value); 
	value = _array;
	length = _newLength; 
}
void Core::PrimitiveType::String::Append(const char _value)
{
	const int _newLength = length + 2; 
	char* _array = new char[_newLength];
	strcpy(_array, value);
	_array[length] = _value; 
	_array[length+1] = '\0';
	value = _array; 
	length += 1; 
}

int Core::PrimitiveType::String::Length() const
{
	return length;
}

const char* Core::PrimitiveType::String::ToCstr() const
{
	return value;
}

#pragma endregion methods 
#pragma region override
Core::PrimitiveType:: String Core::PrimitiveType::String::ToString() const
{
	return value;
}

#pragma endregion override
#pragma region operator
Core::PrimitiveType::String::operator const char* () const
{
	return value;
}
#pragma endregion operator 

std::ostream& Core::PrimitiveType::operator<<(std::ostream& _os, const String& _str)
{
	_os << _str.value;
	return _os; 
}
