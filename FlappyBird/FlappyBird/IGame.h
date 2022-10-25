#pragma once
class IGame
{

	virtual void DrawBorder() = 0;
	virtual void DrawBird() = 0;
	virtual void EraseBird() = 0;
	virtual void GeneratePipe(int _index) = 0;
};

