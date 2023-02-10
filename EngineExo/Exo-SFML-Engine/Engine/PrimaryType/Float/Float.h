#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Float : public ValueType
	{
		DECLARE_CLASS_INFO(Float, ValueType)
#pragma region var
	private:
		float value = 0.0f;
	public:
		static const Float MinValue;
		static const Float MaxValue;
		static const Float Epsilon;
		static const Float NaN;
		static const Float PositiveInfinity;
		static const Float NegativeInfinity;
#pragma endregion
#pragma region const
	public:
		Float() {}
		Float(float _value);
#pragma endregion
#pragma region methods
	public:
		static Float Parse(const String& _str);
		static class Boolean TryParse(const String& _str, Float& _output);
		static Boolean IsNaN(const Float& _value);
		static Boolean IsEpsilon(const Float& _value);
		static Boolean IsPositifInfinite(const Float& _value);
		static Boolean IsNegatifInFinite(const Float& _value);
#pragma endregion
#pragma region override
	public:
		PrimaryType::String ToString() const override;
        void SerializeField(std::ostream& _os, const PrimaryType::String& _fieldName, int _index) override;
        void DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName) override;
#pragma endregion
#pragma region operator
	public:
		Float& operator=(const Float& _other);
		operator float();
		operator float() const;
		Boolean operator>(float _other) const;
		Boolean operator>=(float _other) const;
		Boolean operator<(float _other) const;
		Boolean operator<=(float _other) const;
		Boolean operator==(float _other) const;
		Boolean operator!=(float _other) const;

		Float operator+(float _other) const;
		Float operator-(float _other) const;
		Float operator*(float _other) const;
		Float operator/(float _other) const;
		Float operator-() const;

		Float& operator+=(float _other);
		Float& operator-=(float _other);
		Float& operator*=(float _other);
		Float& operator/=(float _other);
#pragma endregion

	};

}


namespace Engine::PrimaryType
{
    class Float;
    REGISTER_CLASS(Float)
}
