#pragma once
#include "Object.h"
#include <vector>

class MenuItem;

class Menu : public Object
{
#pragma region f/p
protected:
	std::string title = "";
	Menu* oldMenu = nullptr;
	bool isOpen = false;
	std::vector<MenuItem*> items = std::vector<MenuItem*>();
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Menu() = default;
	Menu(const std::string& _title, std::initializer_list<MenuItem*> _items);
	Menu(const Menu& _copy);
	~Menu() override;
#pragma endregion constructor/destructor

#pragma region methods
public:
	virtual void Open();
	virtual void Close();
	virtual void Update();
	void OpenOldMenu();
	void DisplayItems();
	std::vector<MenuItem*> Items() const;
	void Choose(const int _index);
	Menu* OldMenu() const;
	void SetOldMenu(Menu* _old);
	bool Equals(const Menu* _other);
#pragma endregion methods
};

