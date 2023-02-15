#pragma once
#include "../ValueType/ValueType.h"
#include "../Float/Float.h"
#include <SFML/Graphics.hpp>

namespace Engine::PrimaryType
{
    class Boolean;
    UCLASS()
    class Vector2 : public ValueType
    {
        DECLARE_CLASS_INFO(Vector2, ValueType)
#pragma region var
    public:
        UPROPERTY() Float x = 0.0f;
REGISTER_FIELD(x, &x, BindingFlags::Public)
        UPROPERTY() Float y = 0.0f;
REGISTER_FIELD(y, &y, BindingFlags::Public)
#pragma endregion
#pragma region const
    public:
        Vector2() {}
        Vector2(const sf::Vector2f& _value);
        Vector2(float _x, float _y);
#pragma endregion
#pragma region methods
    public:
        static Vector2 MoveTowards(const Vector2& _current, const Vector2& _target, float _dt);
#pragma endregion
#pragma region override
    public:
        PrimaryType::String ToString() const override;
        void SerializeField(std::ostream& _os, const PrimaryType::String& _fieldName, int _index) override;
        void DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName) override;
#pragma endregion

#pragma region operator
    public:
        operator sf::Vector2<float>() const;
        Object& operator=(const Object* _obj) override;

        Vector2& operator=(const Vector2& _vector2);
        Vector2& operator+=(const Vector2& _other);
        Vector2& operator-=(const Vector2& _other);
        Vector2& operator/=(const Vector2& _other);
        Vector2& operator*=(const Vector2& _other);

        Vector2 operator+(const Vector2& _vector2) const;
        Vector2 operator-(const Vector2& _vector2) const;
        Vector2 operator/(const Vector2& _vector2) const;
        Vector2 operator*(const Vector2& _vector2) const;

        Boolean operator==(const Vector2& _other) const;
        Boolean operator!=(const Vector2& _other) const;

        Float& operator[](size_t _index);
        Float operator[](size_t _index) const;

#pragma endregion

    };

}


namespace Engine::PrimaryType
{
    class Vector2;
    REGISTER_CLASS(Vector2)
}
