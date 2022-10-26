#pragma once

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define BETWEEN 5
#define SPACE ' '

class Pipe
{
private : 
	int _rand = Random(3, SCREEN_HEIGHT - 7);
	int wallPos = WIN_WIDTH - 3;
	

public: 
	void ErasePipe();
	void GeneratePipe(int _index);
	void PositionPipe();
	int Random(int _min, int _max);

};

