#include "Inventory.h"
#include "Item.h"
#include <iostream>

#pragma region constructor
Inventory::Inventory(const std::string& _name, Entity* _owner)
{
	name = _name;
	owner = _owner;
}

Inventory::Inventory(const Inventory& _copy)
{
	name = _copy.name;
	items = _copy.items;
	owner = _copy.owner;
}

Inventory::~Inventory()
{
	items.clear();
}

#pragma endregion constructor

#pragma region methods
size_t Inventory::FindItem(const Item* _item)
{
	const size_t _size = items.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (_item->Equals(items[i]))
			return i;
	}
	return -1;
}

void Inventory::UseItem(const int _index)
{
	const int _currentIndex = _index - 1;
	if (_currentIndex < 0 || _currentIndex > items.size()) throw std::exception("use item invalid index !");
	Item* _item = items[_currentIndex];
	if (_item == nullptr) return;
	_item->OnUse(owner);
	if (_item->Stack() == 0)
		RemoveItem(_item);
}

void Inventory::AddItem(Item* _item)
{
	const size_t _index = FindItem(_item);
	if (_index == -1)
		items.push_back(_item);
	else 
		items[_index]->AddStack(1);
}

void Inventory::RemoveItem(Item* _item)
{
	const size_t _index = FindItem(_item);
	if (_index == -1) return;
	items.erase(items.begin() + _index);
}

void Inventory::Clear()
{
	items.clear();
}
int Inventory::Count() const
{
	return (int)items.size();
}

void Inventory::DisplayInventory()
{
	std::cout << "--------------------" << name << "--------------------" << std::endl;
	const size_t _size = items.size();
	for (size_t i = 0; i < _size; i++)
	{
		std::cout << i + 1 << ": " << items[i]->ToString() << std::endl;
	}
	std::cout << "--------------------" << std::string(name.size(), '-') << "--------------------" << std::endl;
}

std::vector<Item*> Inventory::Items() const
{
	return items;
}
#pragma endregion methods