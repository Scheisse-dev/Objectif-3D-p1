#include "GameObject.h"
#include "../Utils/DebugMacro.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include <SFML/Graphics.hpp>

#pragma region constructor/destructor
Engine::GameObject::GameObject(const PrimaryType::String& _name)
{
	name = _name; 
}

Engine::GameObject::GameObject(const GameObject& _copy)
{
	shape = _copy.shape;
	name = _copy.name;
}

Engine::GameObject::~GameObject()
{
	delete shape;
	shape = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methods

sf::Shape* Engine::GameObject::Shape() const
{
	return shape;
}
void Engine::GameObject::SetColor(const sf::Color& _color)
{
	checkLow((shape != nullptr), "[GameObject] => shape is nullptr")
	shape->setFillColor(_color);
}

Engine::GameObject* Engine::GameObject::CreatePrimitive(const PrimitiveType& _type, const PrimaryType::String& _name)
{
	GameObject* _result = new GameObject(_name);
		switch (_type)
		{
		case PrimitiveType::Circle:
			_result->shape = new sf::CircleShape(sf::CircleShape(25.0f));
			break;
		case PrimitiveType::Square:
			_result->shape = new sf::RectangleShape(sf::Vector2f(25.0f, 25.0f));
			break;
		}
	return _result;
}


#pragma endregion methods

#pragma region operator

Engine::GameObject& Engine::GameObject::operator=(const GameObject& _other)
{
	name = _other.name;
	shape = _other.shape;
	return *this;
}

Engine::PrimaryType::Boolean Engine::GameObject::operator==(const GameObject& _other) const
{
	return name == _other.name && shape == _other.shape;
}

Engine::PrimaryType::Boolean Engine::GameObject::operator!=(const GameObject& _other) const
{
	return !this->operator==(_other);
}

#pragma endregion operator