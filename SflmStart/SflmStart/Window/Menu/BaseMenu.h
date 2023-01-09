#pragma once
#include "../../Object/Object.h"
#include <vector>

class BaseMenu : public Object
{
#pragma region f/p
protected:
	std::vector<class FB_UIElement*> elements = std::vector<FB_UIElement*>();
	bool isOpen = false;
	class Window* owner = nullptr; 
#pragma region f/p
#pragma region constructor/destructor
public:
	BaseMenu() = default;
	BaseMenu(Window* _owner);
	virtual ~BaseMenu(); 
#pragma endregion constructor/destructor
#pragma region methods
public:
	void Open();
	void Close();
	void SetActive(const bool _status);
	virtual void Draw();
#pragma endregion methods
};

