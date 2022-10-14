#include <iostream>
#include "Environment.h"
#include "Map.h"
#include "Player.h"
#include "Case.h"
#include "Vector2.h"
#include "Utils.h"; 
/*
#include <string>
#include "Utils.h"
#include"Inventory.h"
#include "Item.h"
#include"Player.h"
#include"PotionHealth.h"
#include "Weapon.h"
#include "Map.h"
*/
int main()
{
	Map map = Map("mapTest");
	if (!map.IsValid()) return -4;

	while (!map.GetPlayer()->Position()->Equals(map.Exit()->Position()))
	{
		system("cls");
		map.Display();
		map.GetPlayer()->Move();
	}
	system("cls");
	Utils::Log(map.GetPlayer()->Name() + " find the exit !"); 
	return 0; 

	/*
	Map map = Map();
	map.FileReader();
	std::cout << "Choose your username: ";
	std::string _name = Utils::UserChoice <std::string>("Choose your username: ");
	Player player = Player(_name);
	player.GetInventory()->AddItem(new PotionHealth(50.0f)); 
	player.GetInventory()->AddItem(new PotionHealth(50.0f));
	player.GetInventory()->AddItem(new PotionHealth(25.0f));
	player.GetInventory()->AddItem(new Weapon("Bada-Boom", 90.0f));

	int _choise = 0;
	
	while (!player.IsDead())
	{
		system("cls");
		player.GetInventory()->DisplayInventory();
		std::cout << "Chopose your item: ";
		std::cin >> _choise;
		player.GetInventory()->UseItem(_choise);
		system("pause");
	}
	system("cls");
	std::cout << player.Name() << " is dead !";
	return 0;
	*/
}
