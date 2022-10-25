#pragma once
#include "IGame.h"

#pragma warning(disable:4996)

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

class Game
{
#pragma region methods
public:
	void DrawBorder();
	void DrawBird();
	void EraseBird();
	void GeneratePipe(int _index);

#pragma endregion methods
};

