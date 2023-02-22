#include "Integer.h"
#include "../String/String.h"
#include "../Boolean/Boolean.h"
#include "../../Utils/Template/Template.h"
#include "../../Utils/DebugMacro.h"
#include "../../Reflection/Utils/ReflectionUtils.h"
#include <iostream>

#pragma region var
const Engine::PrimaryType::Integer Engine::PrimaryType::Integer::MinValue = INT_MIN;
const Engine::PrimaryType::Integer Engine::PrimaryType::Integer::MaxValue = INT_MAX;
#pragma endregion

#pragma region const
Engine::PrimaryType::Integer::Integer(int _value) : super()
{
    value = _value;
}

Engine::PrimaryType::Integer::Integer(const Integer& _copy) : super(_copy)
{
    value = _copy.value;
}
#pragma endregion


#pragma region methods
Engine::PrimaryType::Integer Engine::PrimaryType::Integer::Parse(const String& _str)
{
    return std::stoi(_str.ToCstr());
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::TryParse(const String& _str, Integer& _output)
{
    try
    {
        _output = std::stoi(_str.ToCstr());
        return true;
    }
    catch (const std::exception&)
    {
        _output = -1;
        return false;
    }
}
#pragma endregion


#pragma region override
Engine::PrimaryType::String Engine::PrimaryType::Integer::ToString() const
{
    return std::to_string(value).c_str();
}

void Engine::PrimaryType::Integer::SerializeField(std::ostream& _os, const PrimaryType::String& _fieldName, int _index)
{
    Reflection::ReflectionUtils::SerializePrimaryType(_os, this, _fieldName);
}

void Engine::PrimaryType::Integer::DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName)
{
    String _str = Reflection::ReflectionUtils::GetLine(_is, _fieldName);
    _str = _str.Replace("\"", "").Replace("\t", "").Replace(",", "").Replace(":", "").Replace(_fieldName, "");
    *this = std::stoi(_str.ToCstr());
}
#pragma endregion

#pragma region operator
Engine::Object& Engine::PrimaryType::Integer::operator=(const Object* _other)
{
    if (!IsSame<Integer>(_other))
        return *this;
    super::operator=(_other);
    const Integer* _int = dynamic_cast<const Integer*>(_other);
    value = _int->value;
    return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator=(const Integer& _other)
{
    value = _other.value;
    return *this;
}

Engine::PrimaryType::Integer::operator int()
{
    return value;
}

Engine::PrimaryType::Integer::operator int() const
{
    return value;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator>(const int _other) const
{
    return value > _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator>=(const int _other) const
{
    return value >= _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator<(const int _other) const
{
    return value < _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator<=(const int _other) const
{
    return value <= _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator==(const int _other) const
{
    return value == _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator!=(const int _other) const
{
    return value != _other;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator+(const int _other) const
{
    return value + _other;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator-(const int _other) const
{
    return value - _other;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator*(const int _other) const
{
    return value * _other;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator/(const int _other) const
{
    return value / _other;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator%(const int _other) const
{
    return value % _other;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator+=(int _value)
{
    value += _value;
    return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator-=(int _value)
{
    value -= _value;
    return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator*=(int _value)
{
    value *= _value;
    return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator/=(int _value)
{
    value /= _value;
    return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator%=(int _value)
{
    value %= _value;
    return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator++()
{
    ++value;
    return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator--()
{
    --value;
    return *this;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator++(int)
{
    const int _res = value;
    operator++();
    return _res;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator--(int)
{
    const int _res = value;
    operator--();
    return _res;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator-()
{
    return -value;
}
#pragma endregion