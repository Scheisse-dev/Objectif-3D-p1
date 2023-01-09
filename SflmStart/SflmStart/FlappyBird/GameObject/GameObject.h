#pragma once
#include "../../Object/Object.h"
#include <SFML/Graphics.hpp>

class Window;
class GameObject : public Object
{
#pragma region f/p
protected: 
	sf::Drawable* drawable = nullptr; 
#pragma endregion f/p
#pragma region constructor/destructor
public:
	GameObject();
	GameObject(GameObject& _copy);
	~GameObject() override; 
#pragma endregion constructor/destructor
#pragma region methods
public:
	virtual void OnUpdate();
	virtual void OnDraw(Window* _window);
	virtual void OnCollisionEnter(GameObject* _other); 
	virtual sf::FloatRect GetGlobalBounds() const = 0;
	virtual sf::Vector2f Position() const = 0;
#pragma endregion methods

};

