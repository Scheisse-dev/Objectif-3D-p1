#pragma once
#include <string>
class MapChoice
{
#pragma region f/p
private:
	int _choice = 0;
	std::string _mapChoice;
#pragma endregion f/p
#pragma region constructor
public : 
	MapChoice() = default; 
#pragma endregion constructor
#pragma region methods
	std::string ChoiceMap(); 
#pragma endregion methods
};

