#pragma once
#include <vector>

class Case;

class Screen
{

#pragma region f/p
private: 
	std::vector<Case*> cases = std::vector<Case*>();
#pragma endregion f/p
#pragma region constructor
public: 
	Screen() = default; 
#pragma endregion constructor
#pragma region methods
public: 
	void Init(); 
	void Display(); 
#pragma endregion methods
};

