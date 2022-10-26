#pragma once
#include "IGame.h"
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
	int wallPos = WIN_WIDTH - 3;
	int h = SCREEN_HEIGHT / 2;
	char bird[2][6] = { '/','-','-','o','\\',' ',
					'|','_','_','_',' ','>' };
	std::string clear = "        ";
#pragma endregion f/p
#pragma region methods
public:
	int Random(int _min, int _max);
	void DrawBorder();
	void DrawBird();
	void OneUpdate();
	void EraseBird(int _h);
	void GeneratePipe(int _index);

#pragma endregion methods
};

