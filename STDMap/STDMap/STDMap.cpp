#include <iostream>
#include "map.h"

int main()
{
	Map<int, std::string> tab = Map<int, std::string> // map < key, value> dico map ?! mais on a interdiction de l'utiliser 
	{
		{0, "Thomas"},
		{1 , "Toto"},
		{2 , "Gogo"}

	};

	for (KeyValuePair<int, std::string> _pair : tab)
	{
		std::cout << _pair.Value() << std::endl; 
	}
	return 0; 

	/*
	std::cout << tab[0] << std::endl; 
	std::cout << tab[1] << std::endl;
	std::cout << tab[2] << std::endl;

	tab[2] = "Jojo"; 

	std::cout << tab[2] << std::endl;

	std::cout << tab.Contains(3) << std::endl;
	std::cout << tab.Contains(0) << std::endl;

	tab.Remove(0); 

	std::cout << tab.IsEmpty() << std::endl;
	tab.Clear(); 
	std::cout << tab.IsEmpty() << std::endl;
	*/



}
