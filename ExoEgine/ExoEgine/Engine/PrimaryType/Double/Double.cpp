#include "Double.h"
#include "../Boolean/Boolean.h"
#include "../String/String.h"
#include "../Integer/Integer.h"


#pragma region f/p
const Engine::PrimaryType::Double Engine::PrimaryType::Double::Epsilon = 4.94065645841247E-324;
const Engine::PrimaryType::Double Engine::PrimaryType::Double::MinValue = -1.7976931348623157E+308;
const Engine::PrimaryType::Double Engine::PrimaryType::Double::MaxValue = 1.7976931348623157E+308;
const Engine::PrimaryType::Double Engine::PrimaryType::Double::PositiveInfinity = 1e+300 * 1e+300;
const Engine::PrimaryType::Double Engine::PrimaryType::Double::NegativeInfinity = -PositiveInfinity;
const Engine::PrimaryType::Double Engine::PrimaryType::Double::NaN = PositiveInfinity * 0.0;
#pragma endregion f/p
#pragma region constructor

Engine::PrimaryType::Double::Double(double _value) : super()
{
	value = _value;
}

Engine::PrimaryType::Double::Double(const Double& _copy) : super(_copy)
{
	value = _copy.value;
}

#pragma endregion constructor
#pragma region methods


Engine::PrimaryType::Double Engine::PrimaryType::Double::Parse(const String& _str) 
{
	return std::stoi(_str.ToCstr());
}



Engine::PrimaryType::Boolean Engine::PrimaryType::Double::TryParse(const String& _str,Double& _output)
{
	try
	{
		_output = std::stod(_str.ToCstr());
		return true;
	}
	catch (...)
	{
		_output = -1;
		return false;
	}
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::IsEpsilon(const Double& _value)
{
	return _value == Epsilon;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::IsPositiveInfinity(const Double& _value)
{
	return _value == PositiveInfinity;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::IsNegativeInfinity(const Double& _value)
{
	return _value == NegativeInfinity;
}
Engine::PrimaryType::Boolean Engine::PrimaryType::Double::IsNaN(const Double& _value)
{
	return std::isnan(_value);
}
#pragma endregion methods
#pragma region operator
Engine::PrimaryType::Double& Engine::PrimaryType::Double::operator=(const Double& _other)
{
	value = _other.value;
	return *this;
}

Engine::PrimaryType::Double::operator double()
{
	return value;
}

Engine::PrimaryType::Double::operator double() const
{
	return value;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::operator+(double _other) const
{
	return value + _other;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::operator-(double _other) const
{
	return value - _other;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::operator/(double _other) const
{
	return value / _other;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::operator*(double _other) const
{
	return value * _other;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::operator-() const
{
	return -value;
}

Engine::PrimaryType::Double& Engine::PrimaryType::Double::operator+=(double _other)
{
	value += _other;
	return *this;
}

Engine::PrimaryType::Double& Engine::PrimaryType::Double::operator-=(double _other)
{
	value -= _other;
	return *this;
}

Engine::PrimaryType::Double& Engine::PrimaryType::Double::operator/=(double _other)
{
	value /= _other;
	return *this;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::operator*=(double _other)
{
	value *= _other;
	return *this;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator<(double _other) const
{
	return value< _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator<=(double _other) const
{
	return value <= _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator>(double _other) const
{
	return value > _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator>=(double _other) const
{
	return value >= _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator==(double _other) const
{
	return value == _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator!=(double _other) const
{
	return value != _other;
}
#pragma endregion operator

