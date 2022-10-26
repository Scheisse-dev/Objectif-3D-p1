#pragma once
#include "IGame.h"
#include "Pipe.h"
#include <string>

#pragma warning(disable:4996)

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define BETWEEN 5
#define SPACE ' '

class Game
{
#pragma region f/p

	bool isDeath = false; 
	char bird[2][6] = { '/','-','-','o','\\',' ',
					'|','_','_','_',' ','>' };

	std::string clear = "        ";
	int h = SCREEN_HEIGHT / 2;
	Pipe pipe = Pipe();
#pragma endregion f/p
#pragma region methods
public:
	
	
	void DrawBorder();
	void DrawBird();
	void OneUpdate();
	void EraseBird(int _h);


#pragma endregion methods
};

