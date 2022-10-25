#include "Game.h"
#include "Utils.h"
#include <iostream>

void Game::DrawBorder()
{

	for (int i = 0; i < SCREEN_WIDTH; i++)
	{
		Utils::SetCursorPosition(i, 0); 
		std::cout << "±";
		Utils::SetCursorPosition(i, SCREEN_HEIGHT); 
		std::cout << "±";
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		Utils::SetCursorPosition(0, i);
		std::cout << "±";
		Utils::SetCursorPosition( SCREEN_WIDTH, i);
		std::cout << "±";
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		Utils::SetCursorPosition(WIN_WIDTH, i);
		std::cout << "±";
	}
	for (int i = 0; i < SCREEN_WIDTH; i++)
	{
		Utils::SetCursorPosition(i, 0);
		std::cout << "±";
		Utils::SetCursorPosition(i, SCREEN_HEIGHT);
		std::cout << "±";
	}
}

void Game::DrawBird()
{
	char bird[2][6] = { '/','-','-','o','\\',' ',
					'|','_','_','_',' ','>' };

	//Utils::CinNoBlock
	//SetCursorAtPosition

}
