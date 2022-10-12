#include <iostream>
#include "Player.h"
#include "Weapon.h"
#include "Inventory.h"
#include "PotionHealth.h"

int main()
{
	std::cout << "Choose your username: ";
	std::string _name = "";
	std::cin >> _name;
	Player player = Player(_name);
	player.GetInventory()->AddItem(new PotionHealth(50.0f));
	player.GetInventory()->AddItem(new PotionHealth(50.0f));
	player.GetInventory()->AddItem(new PotionHealth(25.0f));
	player.GetInventory()->AddItem(new Weapon("Bada-boom", 90.0f));

	int _choice = 0;

	while (!player.IsDead())
	{
		system("cls");
		player.GetInventory()->DisplayInventory();
		std::cout << "Choose your item: ";
		std::cin >> _choice;
		player.GetInventory()->UseItem(_choice);
		system("pause");
	}
	system("cls");
	std::cout << player.Name() << " is dead !";
	return 0;
} 