#include "MapChoice.h"
#include <iostream>

#pragma region methods
std::string MapChoice::ChoiceMap()
{


	std::cout << "Choose Your map (1/2/3)" << std::endl;
	while (_choice < 1 || _choice > 3)
		std::cin >> _choice;
	if (_choice == 1) _mapChoice = "mapTest";
	else if (_choice == 2) _mapChoice = "map2";
	else if (_choice == 3) _mapChoice = "map3";

	return _mapChoice; 

#pragma endregion methods


}
