#pragma once
#include <initializer_list>
#include <string>
#pragma region CommentZone
/*
* 
*/
#pragma endregion CommentZone
class Abstract
{
#pragma region constructor
public: 
	/*
	Abstract() = default; 
	Abstract(std::initializer_list<std::string> game); 
	~Abstract(); 
	*/
#pragma endregion constructor
#pragma region Methods
public : 
	virtual void Menu(std::string _name) = 0;
#pragma endregion Methods
};

