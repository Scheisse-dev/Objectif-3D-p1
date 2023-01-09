#include "FB_Button.h"
#include "../Image/FB_Image.h"

#pragma region constructor/destructor

FB_Button::FB_Button(Window* _owner, const char* _path) : FB_UIElement(_owner)
{
	image = new FB_Image(_owner, _path);
}

FB_Button::FB_Button(const FB_Button& _copy)
{
	image = _copy.image;
}

FB_Button::~FB_Button()
{
	delete image;
	image = nullptr;
	OnClick = nullptr; 
}
#pragma endregion constructor/destructor

#pragma region methods

#pragma endregion methods
#pragma region override

void FB_Button::SetPosition(const sf::Vector2f& _position)
{
	image->SetPosition(_position); 
}

void FB_Button::SetScale(const sf::Vector2f& _scale)
{
	image->SetScale(_scale);
}

void FB_Button::Draw(Window* _window)
{
	image->Draw(_window); 
}

void FB_Button::SetOrigin(const sf::Vector2f& _origin)
{
	image->SetOrigin(_origin);
}

void FB_Button::OnUpdate()
{
	if (!isActive) return;
	const sf::Vector2i _moussePosition = sf::Mouse::getPosition(*owner->Renderer());
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && image->getGlobalBounds().contains(sf::Vector2f(_moussePosition.x, _moussePosition.y)))
	{
		OnClick.Invoke();
	}
}

sf::FloatRect FB_Button::GetGlobalBounds() const
{
	return image->GetGlobalBounds();
}


#pragma endregion override
