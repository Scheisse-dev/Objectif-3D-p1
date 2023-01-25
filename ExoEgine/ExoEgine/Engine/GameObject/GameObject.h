#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics/Shape.hpp>
#include "../PrimaryType/String/String.h"

ENUM(PrimitiveType, Circle, Square)


namespace Engine
{
	class GameObject : public Object
	{
		DECLARE_CLASS_INFO(GameObject, Object)
#pragma region f/p
	protected:
		sf::Shape* shape = nullptr;
		PrimaryType::String name = "";
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		GameObject() = default;
		GameObject(const PrimaryType::String& _name);
		GameObject(const GameObject& _copy);
		~GameObject() override;
#pragma endregion constructor/destructor
#pragma region methods
	public:
		sf::Shape* Shape() const; 
		void SetColor(const sf::Color& _color);
		static GameObject* CreatePrimitive(const PrimitiveType& _type, const PrimaryType::String& _name);
#pragma endregion methods
#pragma region operator
	public:
		GameObject& operator=(const GameObject& _other);
		PrimaryType::Boolean operator==(const GameObject& _other) const;
		PrimaryType::Boolean operator!=(const GameObject& _other) const; 
#pragma endregion operator
	};

}