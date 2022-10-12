#include <iostream>
#include"Inventory.h"
#include "Item.h"

int main()
{
	Inventory inv = Inventory("Toto");
	inv.AddItem(new Item("awap"));
	inv.AddItem(new Item("awap"));
	inv.DisplayInventory();
	
}
