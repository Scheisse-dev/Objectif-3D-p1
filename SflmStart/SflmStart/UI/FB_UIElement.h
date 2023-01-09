#pragma once
#include "../../Object/Object.h"
#include "../../Window/Window.h"
#include <SFML/Graphics.hpp>
class FB_UIElement : public Object
{
#pragma region f/p
protected:
	bool isActive = false;
	Window* owner = nullptr; 
#pragma endregion f/p
#pragma region constructor
public:
	FB_UIElement() = default; 
	FB_UIElement(Window* _owner);
	FB_UIElement(const FB_UIElement& _copy);
	~FB_UIElement() override;
#pragma endregion constructor
#pragma region methods
public:
	virtual void SetPosition(const sf::Vector2f& _position) = 0; 
	virtual void SetScale(const sf::Vector2f& _scale) = 0;
	virtual void Draw(class Window* _window) = 0;
	virtual void SetOrigin(const sf::Vector2f& _origin) = 0; 
	virtual void OnUpdate();
	void SetActive(const bool _status);
	virtual sf::FloatRect GetGlobalBounds() const = 0;
#pragma endregion methods
};

