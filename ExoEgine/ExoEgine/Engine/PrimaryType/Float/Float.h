#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Float : public ValueType
	{
		DECLARE_CLASS_INFO(Float, ValueType)
#pragma region f/p
	private:
		float value = -1.0f;
	public:
		static const Float MinValue;
		static const Float MaxValue;
		static const Float Epsilon; 
		static const Float NaN;
		static const Float PositiveInfinity;
		static const Float NegativeInfinity;
#pragma endregion f/p
#pragma region constructor
	public:
		Float() = default;
		Float(float _value);
		Float(const Float& _copy);
#pragma endregion constructor
#pragma region methods
	public:
		static Float Parse(const String& _str);
		static class Boolean TryPase(const String& _str, Float& _output);
		static Boolean IsNaN(const Float& _value);
		static Boolean IsEpsilon(const Float& _value);
		static Boolean IsPositiveInfinity(const Float& _value);
		static Boolean IsNegativeInfinity(const Float& _value);
#pragma endregion methods
#pragma region override
	public:
		String ToString() const override;
#pragma endregion override
#pragma region operator
		Float& operator=(const Float& _other);
		operator float();
		operator float() const;
		Float operator+(float _other) const;
		Float operator-(float _other) const;
		Float operator/(float _other) const;
		Float operator*(float _other) const;
		Float operator-() const;

		Float& operator+=(float _other);
		Float& operator-=(float _other);
		Float& operator/=(float _other);
		Float operator*=(float _other);

		Boolean operator<(float _other) const;
		Boolean operator<=(float _other) const;
		Boolean operator>(float _other) const;
		Boolean operator>=(float _other) const;
		Boolean operator==(float _other) const;
		Boolean operator!=(float _other) const;
#pragma endregion operator
	};

}