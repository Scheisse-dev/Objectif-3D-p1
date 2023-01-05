#include "FlappyBird.h"
#include "../Input/Input.h"
#include "../Time/Time.h"
#include <Windows.h>
#include <iostream>

#pragma region  constructor
FlappyBird::FlappyBird()
{
	SetBackground();
	text =  sf::Text();
	sf::Color color = sf::Color(0, 0, 0);
	font =  sf::Font();
	if (!font.loadFromFile("../Fonts/game_over.ttf")) return;
	text.setFont(font);
	text.setFillColor(color);
	text.setString("GameOver");
	text.setCharacterSize(70);
	text.setPosition(300,250);

}

#pragma endregion constructor
#pragma region methods


void FlappyBird::SetBackground()
{

	textureBackground.loadFromFile("../Sprites/background.png");
	background.setTexture(textureBackground);
	background.setScale(1.2f, 1.2f);



}
void FlappyBird::OnDraw()
{
	window->draw(background);
	window->draw(bird.birdSprite);
	window->draw(pipe.pipeSprite);
	window->draw(pipe.pipe2Sprite);
	if (isDeath == true)
	{
		window->draw(text);
	}
}

void FlappyBird::OnUpdate()
{
	if (isDeath == false)
	{
		if (Input::isKeyDown(sf::Keyboard::Space))
		{
			bird.birdSprite.setPosition(bird.birdSprite.getPosition() + sf::Vector2f(0, -50));
		}
		if (Input::isKeyDown(sf::Keyboard::S))
		{
			bird.birdSprite.rotate(10);
			bird.birdSprite.setPosition(bird.birdSprite.getPosition() + sf::Vector2f(0, 50));
		}
		bird.birdSprite.setPosition(bird.birdSprite.getPosition() + sf::Vector2f(0, 1.f));
		bird.birdSprite.rotate(-10);
		pipe.pipeSprite.setPosition(pipe.pipeSprite.getPosition() + sf::Vector2f(-1.f, 0));
		pipe.pipe2Sprite.setPosition(pipe.pipe2Sprite.getPosition() + sf::Vector2f(-1.f, 0));

		if (bird.birdSprite.getGlobalBounds().intersects(pipe.pipeSprite.getGlobalBounds()) || bird.birdSprite.getGlobalBounds().intersects(pipe.pipe2Sprite.getGlobalBounds()))
		{
			isDeath = true;
		}
	}

}
#pragma endregion methods