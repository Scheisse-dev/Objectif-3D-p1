#pragma once
#include <SFML/Graphics.hpp>

#include "../UIElement.h"

namespace Core
{
	namespace UI
	{
		class Image : public UIElement
		{
			DECLARE_CLASS_INFO(Image, UIElement)
#pragma region f/p
		private:
			sf::Sprite* sprite = nullptr; 
#pragma endregion f/p
#pragma region constructor
		public:
			Image() = delete;
			Image(Window* _owner, const char* _path);
			Image(const Image& _copy);
#pragma endregion constructor
#pragma region override
		public:
			virtual void SetPosition(const sf::Vector2f& _position) override;
			virtual sf::Vector2f Position() const override;
			virtual void SetOrigin(const sf::Vector2f& _origin) override;
			virtual sf::Vector2f Origin() const override;
			virtual void SetScale(const sf::Vector2f& _scale) override;
			virtual sf::Vector2f Scale() const override;
			virtual sf::FloatRect GlobalBounds() const override;
#pragma endregion override
#pragma region methods
		public:

#pragma endregion methods

			// Inherited via UIElement
		};
	}
}