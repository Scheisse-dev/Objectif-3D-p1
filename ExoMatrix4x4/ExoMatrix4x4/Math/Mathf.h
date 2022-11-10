#pragma once
class Mathf
{
#pragma region f/p
public:
	static inline const float Pi = 3.1415926535897932384;
	static inline const float Deg2Rad = Pi * 2.0f / 360.0f;
	static inline const float Rad2Deg = 1.0f / Deg2Rad;
#pragma endregion f/p
#pragma region methods
public: 
	template <typename T>
	static T Clamp(const T& _current, const T& _min, const T& _max);
	static float Clamp01(const float _value); 
	static float Sqrt(const float _value);
	static float Min(const float _a, const float _b);
	static float Max(const float _a, const float _b);
	static float Abs(const float _value);
	static float Acos(const float _value);
	static float Cos(const float _value);
	static float Sin(const float _value);
#pragma endregion methods
};

template<typename T>
inline T Mathf::Clamp(const T& _current, const T& _min, const T& _max)
{
	if (_current < _min) return _min;
	if (_current > _max) return _max;
	return _current; 
}