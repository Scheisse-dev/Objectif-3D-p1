#pragma once
#include "Object.h"

class IGame; 

class LauncherItem : public Object
{
#pragma region f/p
private: 
	IGame* game = nullptr; 
#pragma endregion f/p
#pragma region constructor/destructor
public: 
	LauncherItem() = default; 
	LauncherItem(IGame* _game); 
	LauncherItem(const LauncherItem& _copy);
	~LauncherItem();
#pragma endregion constructor/destructor
public: 
	void Onclick(); 
	void Display(); 
	void Game() const;
};

