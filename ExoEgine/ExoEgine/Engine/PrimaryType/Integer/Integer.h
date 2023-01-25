#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	UCLASS()
	class Integer : public ValueType
	{
		DECLARE_CLASS_INFO(Integer,ValueType)
#pragma region f/p
	private:
		int value = -1;
	public:
		static const Integer MinValue;
		static const Integer MaxValue;
#pragma endregion f/p
#pragma region constructor
	public:
		Integer(int _value);
		Integer(const Integer& _copy);
#pragma endregion constructor
#pragma region methods
	public:
		static Integer Parse(const String& _str);
		static class Boolean TryParse(const String& _str, Integer& _output);
#pragma endregion methods
#pragma region override
		PrimaryType::String ToString() const override;
#pragma endregion override
#pragma region operator
		Integer& operator=(const Integer& _other);
		operator int();
		operator int() const;
		Boolean operator>(int _other) const;
		Boolean operator>=(int _other) const;
		Boolean operator<(int _other) const;
		Boolean operator<=(int _other) const;
		Boolean operator==(int _other) const;
		Boolean operator!=(int _other) const;
		Integer operator+(int _other) const;
		Integer operator-(int _other) const;
		Integer operator*(int _other) const;
		Integer operator/(int _other) const;
		Integer operator%(int _other) const;
		Integer operator+=(int _other);
		Integer operator-=(int _other);
		Integer operator*=(int _other);
		Integer operator/=(int _other);
		Integer operator%=(int _other);
		Integer operator++();
		Integer operator--();
		Integer operator++(int);
		Integer operator--(int);
		Integer operator-();
#pragma endregion operator
		Object& operator=(const Object* _other) override;
	};

}