#include "Integer.h"
#include "FString.h"
#include "Boolean.h"
#include "Exception.h"
#include <format>
#include <limits>

#pragma region f/p
O3DLIBRARY_API Core::PrimitiveType::Integer Core::PrimitiveType::Integer::MinValue()
{
	return std::numeric_limits<int>::min();
}
O3DLIBRARY_API Core::PrimitiveType::Integer Core::PrimitiveType::Integer::MiaxValue()
{
	return std::numeric_limits<int>::max();
}
#pragma endregion f/p
#pragma region constructor

Core::PrimitiveType::Integer::Integer(const int _value)
{
	value = _value;
}

Core::PrimitiveType::Integer::Integer(const Integer& _copy)
{
	value = _copy.value; 
}
#pragma endregion constructor
#pragma region methods
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::Equals(const Integer& _other) const
{
	return value == _other.value; 
}
O3DLIBRARY_API Core::PrimitiveType::Integer Core::PrimitiveType::Integer::Parse(const FString& _str)
{
	return std::stoi(_str.ToCstr()); 
}
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::TryParse(const FString& _str, Integer& _out)
{
	try
	{
		_out = std::stoi(_str.ToCstr());
		return true;
	}
	catch (const std::exception&)
	{
		_out = -1;
		return false; 
	}
}
#pragma endregion methods
#pragma region override
O3DLIBRARY_API Core::PrimitiveType::FString Core::PrimitiveType::Integer::ToString() const
{
	return std::to_string(value).c_str(); 
}

O3DLIBRARY_API Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::Equals(const Object* _obj) const
{
	const Integer* _other = dynamic_cast<const Integer*>(_obj);
	if (_other == nullptr) return false;
	return Equals(*_other); 
}

#pragma endregion override
#pragma region operator 
Core::PrimitiveType::Integer::operator int() const
{
	return value;
}
O3DLIBRARY_API Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator+(const Integer& _other) const
{
	return  value + _other;
}
O3DLIBRARY_API Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator+=(const Integer& _other)
{
	value += _other; 
	return *this;
}
O3DLIBRARY_API Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator-(const Integer& _other) const
{
	return value - _other; 
}
O3DLIBRARY_API Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator-=(const Integer& _other)
{
	value -= _other;
	return *this;
}
O3DLIBRARY_API Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator*(const Integer& _other) const
{
	return value * _other;
}
O3DLIBRARY_API Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator*=(const Integer& _other)
{
	value *= _other;
	return *this;
}
O3DLIBRARY_API Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator/(const Integer& _other) const
{
	if (_other  == Integer(0))
		throw DivideByZeroException(std::format("Division of {} by zero.", (int)*this).c_str());
	return value / _other;
}
O3DLIBRARY_API Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator/=(const Integer& _other)
{
	if (_other == Integer(0))
		throw DivideByZeroException(std::format("Division of {} by zero.", (int)*this).c_str());
	 value /= _other;
	 return *this;
}
O3DLIBRARY_API Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator%(const Integer& _other) const
{
	return value % _other;
}
O3DLIBRARY_API Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator%=(const Integer& _other)
{
	 value %= _other;
	 return *this;
}
O3DLIBRARY_API Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator++(int)
{
	Integer tmp = * this; 
	operator++();
	return tmp; 
}
O3DLIBRARY_API Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator--(int)
{
	Integer tmp = *this;
	operator--();
	return tmp;
}
O3DLIBRARY_API Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator++()
{
	++value; 
	return *this; 
}
O3DLIBRARY_API Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator--()
{
	--value;
	return *this;
}
O3DLIBRARY_API Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator-(int)
{
	return  -value;
}
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator<(const Integer& _other) const
{
	return value < _other; 
}
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator<=(const Integer& _other) const
{
	return  value <= _other;
}
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator>(const Integer& _other) const
{
	return value > _other;
}
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator>=(const Integer& _other) const
{
	return value >= _other;
}
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator==(const Integer& _other) const
{
	return  value == _other.value; 
}
O3DLIBRARY_API Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator!=(const Integer& _other) const
{
	return !this->operator ==(_other); 
}

#pragma endregion operator 