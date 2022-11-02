#pragma once
#include "MenuItem.h"
#include "Object.h"
#include "Utils.h"

#pragma region commentZone
/*
* add owner
* SetOldMenu
* test EqualMenu to dont display if same
* Close to... close... stupid
* Open same boy 
* throw the exception, dont crash please
* use fonction name Utils toString to choose 
*/ 
#pragma endregion commentZone
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
	Menu(const std::string _title, std::initializer_list<MenuItem*> _item); 
	Menu(const Menu& _copy); 
	~Menu(); 
#pragma endregion constructor/destructor
#pragma region methods
public:
	void Choose(const std::string _index);
	void DisplayItems();
	std::vector<MenuItem*> Item() const; 
	bool Equals(const Menu* _name);
	void SetOldMenu(Menu* _old);
	Menu* OldMenu();
	void Close();
	void Open(); 
#pragma endregion methods 
};

