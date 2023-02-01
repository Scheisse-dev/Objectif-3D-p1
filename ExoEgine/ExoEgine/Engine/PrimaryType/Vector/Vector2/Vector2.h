#pragma once

#include "../../Float/Float.h"
#include <SFML/System/Vector2.hpp>

namespace Engine::PrimaryType
{
	UCLASS()
	class Vector2 : public PrimaryType::ValueType
	{
	DECLARE_CLASS_INFO(Vector2, ValueType)
#pragma region f/p
	private:
		UPROPERTY() Float y = 0.0f;
REGISTER_FIELD(y, &y, BindingFlags::NoPublic)
		UPROPERTY() Float x = 0.0f;
REGISTER_FIELD(x, &x, BindingFlags::NoPublic)
#pragma endregion f/p
#pragma region constructor
	public:
		Vector2() = default;
		Vector2(const Vector2&) = default;
		Vector2(float _x, float _y);
#pragma endregion constructor
#pragma region methods
	public:
		static Vector2 MoveTowards(const Vector2& _current, const Vector2& _target, float _dt);
#pragma endregion methods
#pragma region override
	public:
		String ToString() const override;
		void SerializeField(std::ostream& _os, const PrimaryType::String& _fieldName) override;
		void DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName) override;
#pragma endregion override
#pragma region operator
	public:
		operator sf::Vector2f() const; 
		Object& operator=(const Object* _obj);
		Vector2& operator=(const Vector2& _other);
		Vector2& operator+=(const Vector2& _other);
		Vector2& operator-=(const Vector2& _other);
		Vector2& operator*=(const Vector2& _other);
		Vector2& operator/=(const Vector2& _other);
		Vector2 operator+(const Vector2& _other) const;
		Vector2 operator-(const Vector2& _other) const;
		Vector2 operator*(const Vector2& _other) const;
		Vector2 operator/(const Vector2& _other) const;
		Boolean operator==(const Vector2& _other) const;
		Boolean operator!=(const Vector2& _other) const;
		Float& operator[](size_t _index);
		Float operator[](size_t _index) const;

#pragma endregion operator

	};

}
