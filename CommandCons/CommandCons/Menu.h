#pragma once
#include "MenuItem.h"
#include "Object.h"
#include "Utils.h"

#pragma region commentZone
/*
* throw the exception, dont crash please
* use fonction name Utils toString to choose 
*/ 
#pragma endregion commentZone
class Menu : public Object
{
#pragma region f/p
protected:
	std::string title = "";
	bool isInLoop = true;
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
	void FonctionMix();
	void Choose(const std::string _index);
	void DisplayItems();
	std::vector<MenuItem*> Item() const;

#pragma endregion methods 
};

