#include "FlappyBird.h"
#include "../Input/Input.h"
#include "../Time/Time.h"
#include "../Event/Event.h"
#include <Windows.h>
#include <iostream>

#pragma region  constructor
FlappyBird::FlappyBird()
{
	SetBackground();



}

#pragma endregion constructor
#pragma region methods


void FlappyBird::SetBackground()
{
	font = sf::Font();
	if (!font.loadFromFile("../Fonts/game_over.ttf")) return;            
	score.setFont(font);                      
	score.setFillColor(color);
	score.setCharacterSize(70);
	score.setPosition(800, 0);                        

	textureBackground.loadFromFile("../Sprites/background.png");
	background.setTexture(textureBackground);
	background.setScale(1.2f, 1.2f);
	leftlimit.setPosition(-150,0);
	upperlimit.setPosition(0, 0);
	lowerlimit.setPosition(0, 600);


}
void FlappyBird::OnDraw()
{
	window->draw(background);
	window->draw(bird.birdSprite);
	window->draw(pipe.pipeSprite);
	window->draw(pipe.pipe2Sprite);
	window->draw(pipe.pipe3Sprite);
	window->draw(pipe.pipe4Sprite);
	
	window->draw(score);

	if (onStart == false)
	{
		window->draw(flappyMenu.titleSprite);
		window->draw(flappyMenu.startSprite);
	}
	
	if (isDeath == true)
	{
		window->draw(flappyMenu.text);
		window->draw(flappyMenu.exitSprite);
		window->draw(flappyMenu.retrySprite);
	}
}

void FlappyBird::OnUpdate()
{
	if (onStart == false)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//std::cout << "pressed" << std::endl;
			//sf::Vector2f(sf::Mouse::getPosition()) == flappyMenu.startSprite.getPosition()
			if (flappyMenu.startSprite.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
			{
				onStart = true;
				std::cout << "pressed & on button" << std::endl;

			}
		}
	}
	if (isDeath == true)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (flappyMenu.retrySprite.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
			{

				std::cout << "pressed & on button" << std::endl;
				pipe.pipeSprite.setPosition(300, 400);
				pipe.pipe2Sprite.setPosition(412, 100);
				pipe.pipe3Sprite.setPosition(900, 550);
				pipe.pipe4Sprite.setPosition(1012, 250);

				bird.birdSprite.setPosition(0, 300);
				count = 0;
				isDeath = false;
				onStart = true;
			}
			if (flappyMenu.exitSprite.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
			{
				window->close();
			}
		}
	}
	if (pipe.pipeSprite.getGlobalBounds().intersects(leftlimit.getGlobalBounds()))
	{
		space = rand() % 300 + 50;
		space2 = space + 300;
		pipe.pipeSprite.setPosition(900, space2);
		pipe.pipe2Sprite.setPosition(1012, space);
		count++;
	}
	if (pipe.pipe3Sprite.getGlobalBounds().intersects(leftlimit.getGlobalBounds()))
	{
		space = rand() % 300 + 50;
		space2 = space + 300;
		pipe.pipe3Sprite.setPosition(900, space2);
		pipe.pipe4Sprite.setPosition(1012, space);
		count ++;
	}
	if (isDeath == false && onStart == true)
	{
		if (Input::isKeyDown(sf::Keyboard::Space))
		{
			bird.birdSprite.setPosition(bird.birdSprite.getPosition() + sf::Vector2f(0, -50));
		}

		bird.birdSprite.setPosition(bird.birdSprite.getPosition() + sf::Vector2f(0, 1.f));
		pipe.pipeSprite.setPosition(pipe.pipeSprite.getPosition() + sf::Vector2f(-1.f, 0));
		pipe.pipe2Sprite.setPosition(pipe.pipe2Sprite.getPosition() + sf::Vector2f(-1.f, 0));
		pipe.pipe3Sprite.setPosition(pipe.pipe3Sprite.getPosition() + sf::Vector2f(-1.f, 0));
		pipe.pipe4Sprite.setPosition(pipe.pipe4Sprite.getPosition() + sf::Vector2f(-1.f, 0));

		if (bird.birdSprite.getGlobalBounds().intersects(pipe.pipeSprite.getGlobalBounds()) || bird.birdSprite.getGlobalBounds().intersects(pipe.pipe2Sprite.getGlobalBounds())
			|| bird.birdSprite.getGlobalBounds().intersects(pipe.pipe3Sprite.getGlobalBounds()) || bird.birdSprite.getGlobalBounds().intersects(pipe.pipe4Sprite.getGlobalBounds()) ||
			bird.birdSprite.getGlobalBounds().intersects(upperlimit.getGlobalBounds()) || bird.birdSprite.getGlobalBounds().intersects(lowerlimit.getGlobalBounds()))
		{
			isDeath = true;
		}
		score.setString("Score :" + std::to_string(count));
	}

}
#pragma endregion methods