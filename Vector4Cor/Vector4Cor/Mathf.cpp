#include "Mathf.h"
#include <complex>



float Mathf::Sqrt(const float _value)
{
    return std::sqrt(_value);
}

float Mathf::Min(const float _a, const float _b)
{
    return _a < _b ? _a : _b;
}

float Mathf::Max(const float _a, const float _b)
{
    return _a > _b ? _a : _b;
}

float Mathf::Abs(const float _value)
{
    return std::abs(_value);
}

float Mathf::Acos(const float _value)
{
    return std::acos(_value);
}

float Mathf::Clamp01(const float _value)
{
    if (_value < 0) return 0;
    if (_value > 1) return 1;
    return _value;
}