#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
#pragma region f/p
private:
	float width = 0.1f;
	float height = 0.1f;
	float speed = 0.1f; 
	bool isOffGame = false;
	const char* texture = "../Sprite/HarlodText.png";
#pragma endregion f/p 
#pragma region constructor
public:
	Entity() = default;
	//virtual ~Entity();
#pragma endregion constructor
#pragma region methods
public:
	virtual void SetSprite() = 0;
#pragma endregion methods
};