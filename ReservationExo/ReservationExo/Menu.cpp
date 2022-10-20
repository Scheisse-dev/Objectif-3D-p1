#include "Menu.h"
#include <iostream>

#pragma region commentZone
/*
* _space = char* space = " "; for i<spaceLength => space[i] = " "; erreur out of range; def operator+ ? 
* // bée non c'était un resize, je suis tout de même très con 
*  _name change pour chaque menu -> _line doit donc TOUJOURS prendre la longeur de _name //done 
* std::string = char*; logiquement std::string tab; tab[1]
*/

#pragma endregion commentZone 
#pragma region constructor

Menu::Menu(std::string _name, std::initializer_list<std::string*> tab)
{
	std::string _line;
	std::string _space;
	_line.resize(_name.size());
	for (int i = 0; i < _name.size(); i++)
	{
		_line[i] = '-'; 
	}

	_space.resize(spaceLength);
	for (int i = 0; i < spaceLength; i++)
	{
		_space[i] = ' ';
	}	
	std::cout << _space << _name << _space << std::endl;
	std::cout << _space << _line << _space << std::endl;
}

#pragma endregion constructor



#pragma region methods


#pragma endregion methods