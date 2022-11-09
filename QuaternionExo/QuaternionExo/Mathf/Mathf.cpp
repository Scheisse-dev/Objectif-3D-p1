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
float Mathf::Abs(const float _value)
{
    return std::abs(_value);
}