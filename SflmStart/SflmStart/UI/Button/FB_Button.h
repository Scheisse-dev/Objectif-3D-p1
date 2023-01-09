#pragma once
#include "../FB_UIElement.h"
#include "../../Event/Delegate/Delegate.h"
class FB_Image;

class FB_Button : public FB_UIElement
{
#pragma region f/p
private:
	FB_Image* image = nullptr; 
public:
	Delegate<void> OnClick = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_Button(Window* _owner, const char* _path);
	FB_Button(const FB_Button& _copy);
	virtual ~FB_Button() override; 
#pragma endregion constructor/destructor
#pragma region methods
public:
#pragma endregion methods
#pragma region override
public:
	virtual void SetPosition(const sf::Vector2f& _position) override;
	virtual void SetScale(const sf::Vector2f& _scale) override;
	virtual void Draw(Window* _window) override;
	virtual void SetOrigin(const sf::Vector2f& _origin) override;
	virtual void OnUpdate() override;
	virtual sf::FloatRect GetGlobalBounds() const override;
#pragma endregion override




};

