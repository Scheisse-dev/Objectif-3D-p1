#include "WindowTest.h"
#include "../Input/Input.h"
#include "../Time/Time.h"
#include <iostream>

#pragma region constructor/destructor
WindowTest::WindowTest()
{
	shape = new sf::RectangleShape(sf::Vector2f(50, 50));
	text = new sf::Text();
	font = new sf::Font();
	if(!font->loadFromFile("D:/GitHub/Objectif-3D-p1/SflmStart/Fonts/DeutscheZierschrift.ttf")) return;
	text->setFont(*font);
	text->setString("Wolfenstein");
	text->setCharacterSize(120);
}
WindowTest::~WindowTest()
{
	delete shape; 
	shape = nullptr;
	delete text;
	text = nullptr; 
	delete font;
	font = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methods
void WindowTest::OnDraw()
{
	//Draw(shape); 
	Draw(text);
}

void WindowTest::OnUpdate()
{
	if (Input::isKeyDown(sf::Keyboard::D))
	{
		shape->setPosition(shape->getPosition() + sf::Vector2f(1, 0));
	}
	if (Input::isKeyDown(sf::Keyboard::Q))
	{
		shape->setPosition(shape->getPosition() + sf::Vector2f(-1, 0));
	}
}
#pragma endregion methods