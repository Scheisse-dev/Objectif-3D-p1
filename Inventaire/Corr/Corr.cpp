#include <iostream>
#include"Inventory.h"
#include "Item.h"
#include"Player.h"
#include"PotionHealth.h"
#include "Weapon.h"

int main()
{
	std::cout << "Choose yout username: ";
	std::string _name = "";
	std::cin >> _name;
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

}
