#include "Input.h"
#include "../Event/Event.h"

bool Input::isKeyDown(const sf::Keyboard::Key& _key)
{
	const sf::Event* _current = Event::currentEvent;
	if (_current == nullptr) return false;
	return _current->type == sf::Event::KeyPressed && _current->key.code == _key;
}

bool Input::isKeyUp(const sf::Keyboard::Key& _key)
{
	const sf::Event* _current = Event::currentEvent;
	if (_current == nullptr) return false;
	return _current->type == sf::Event::KeyReleased && _current->key.code == _key;
}
