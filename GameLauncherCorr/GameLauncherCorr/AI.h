#pragma once
#include <vector>

class MorpionBoard; 


class AI
{
#pragma region constructor/depstructor
public: 
	AI() = default; 
	~AI() = default;

private: 
	int MinMax(std::vector<int> _board, int _player); 
public: 
	int BestMove(MorpionBoard _board);
};

