#pragma once
#include <string>
#include <initializer_list>
#pragma region commentZone
/*
*Doit �tre �volutif ( 
* tab pour l'ent�te ? 
* std::string tab pour l'interieur du menu (tab dynamique) 
* spaceLength = +qqc du length menu... � voir � la fin
* surchage du constructeur menu pour les dif menu // utiliser initializer list 
*/
#pragma endregion commentZone

class Menu
{
#pragma region f/p
private:
	int spaceLength = 15;
#pragma endregion f/p
#pragma region constructor
public: 
	Menu(std::string _name, std::initializer_list<std::string*> tab);
#pragma endregion constructor
#pragma region methods
public:
	void AddBooking(); 
	void CancelBooking(); 

#pragma endregion methods
};

