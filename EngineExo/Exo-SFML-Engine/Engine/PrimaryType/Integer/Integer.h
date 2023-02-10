#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Integer : public ValueType
	{
		DECLARE_CLASS_INFO(Integer, ValueType)
#pragma region var
	private:
		int value = -1;
	public:
		static const Integer MinValue;
		static const Integer MaxValue;
#pragma endregion
#pragma region const
	public:
		Integer() {}
		Integer(int _value);
#pragma endregion
#pragma region methods
	public:
		static Integer Parse(const String& _str);
		static class Boolean TryParse(const String& _str, Integer& _output);
#pragma endregion
#pragma region override
	public:
		PrimaryType::String ToString() const override;
        void SerializeField(std::ostream& _os, const PrimaryType::String& _fieldName, int _index) override;
        void DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName) override;
#pragma endregion
#pragma region operator
	public:
        Object& operator=(const Object* _other) override;
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
		Integer& operator+=(int _other);
		Integer& operator-=(int _other);
		Integer& operator*=(int _other);
		Integer& operator/=(int _other);
		Integer& operator%=(int _other);
		Integer& operator++();
		Integer& operator--();
		Integer operator++(int);
		Integer operator--(int);
		Integer operator-();
#pragma endregion

	};

}


namespace Engine::PrimaryType
{
    class Integer;
    REGISTER_CLASS(Integer)
}
