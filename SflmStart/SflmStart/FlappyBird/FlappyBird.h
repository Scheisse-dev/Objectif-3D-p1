#pragma once
#include <SFML/Graphics.hpp>
#include "../Window/Window.h"
#include "Entity/Bird/Bird.h"
#include "Entity/Pipe/Pipe.h"

class FlappyBird: public Window
{
#pragma region f/p
private:
	Bird bird = Bird();
	Pipe pipe = Pipe();
	sf::Text text;
	sf::Font font;
	bool isDeath = false; 
	
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FlappyBird();
	~FlappyBird() = default; 
#pragma endregion constructor/destructor
#pragma region methods
public:
	void SetBackground();
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
#pragma endregion methods



};

