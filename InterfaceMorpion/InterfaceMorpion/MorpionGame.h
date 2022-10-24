#pragma once
#include <map>
#include <vector>
#include <string>

#pragma region CommentZone 
/*
* def map ==> key = position + O/Y
* map => key 1/2/3/4/5/6/7/8/9 = tab[2][3] / tab [2][6]/... // utiliser les pointeur  map{1, &tab[2][3]}
*/
#pragma endregion CommentZone
class MorpionGame
{
#pragma region f/p
private:
	//std::map<int, std::string> gameKey{ {1, "[2,3]"}, {2, "[2,6]" }, {3, "[2,6]" }, {4, "[4,3]" }, {5, "[4,6]" }, {6, "[4,9]" }, {7, "[6,3]" }, {8, "[6,6]" }, {9, "[6,9]" } };
	//std::map<int, std::string> map = std::map<int,std::string>();
	bool win = false;
	bool player = true; 
	std::string tab[9] = { "   ", "   " , "   ", "   ", "   ", "   ","   ", "   ", "   " };
	std::vector<int> command = std::vector<int>(); 
#pragma endregion f/p
#pragma region methods
public: 
	void Display();
	void Game(); 
#pragma endregion methods
};

