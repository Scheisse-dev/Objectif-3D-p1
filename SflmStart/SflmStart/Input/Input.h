#pragma once
#include <SFML/Graphics.hpp>

class Input
{
public:
	static bool isKeyDown(const sf::Keyboard::Key& _key);
	static bool isKeyUp(const sf::Keyboard::Key& _key);
};

