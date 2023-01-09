#pragma once
#include "../FB_UIElement.h"
class FB_Image : public FB_UIElement
{
#pragma region f/p
private:
	sf::Sprite* sprite = nullptr; 
	sf::Texture* texture = nullptr; 
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_Image() = default; 
	FB_Image(Window* _owner, const char* _path);
	FB_Image(const FB_Image& _copy);
	virtual ~FB_Image() override; 
	#pragma endregion constructor/destructor
#pragma region methods
private:
	void Free();
public:
	sf::FloatRect getGlobalBounds();
#pragma endregion methods
#pragma region override
public:
	virtual void SetPosition(const sf::Vector2f& _position) override;

	virtual void SetScale(const sf::Vector2f& _scale) override;

	virtual void Draw(Window* _window) override;

	virtual void SetOrigin(const sf::Vector2f& _origin) override;

	virtual sf::FloatRect GetGlobalBounds() const override;
#pragma endregion override

};

