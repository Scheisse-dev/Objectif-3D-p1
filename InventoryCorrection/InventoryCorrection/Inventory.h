#pragma once
#include <vector>
#include <string>

class Item;
class Entity;

class Inventory
{
#pragma region f/p
private:
	std::string name = "Base Inventory";
	std::vector<Item*> items = std::vector<Item*>();
	Entity* owner = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Inventory() = default;
	Inventory(const std::string& _name, Entity* _owner);
	Inventory(const Inventory& _copy);
	virtual ~Inventory();
#pragma endregion constructor/destructor

#pragma region methods
private:
	size_t FindItem(const Item* _item);
public:
	void UseItem(const int _index);
	void AddItem(Item* _item);
	void RemoveItem(Item* _item);
	void Clear();
	int Count() const;
	void DisplayInventory();
	std::vector<Item*> Items() const;
#pragma endregion methods
};

