#pragma once
#include "Entity.h"
#include "Vector2.h"
#include "Case.h"

class Inventory; 

class Mob: public Entity
{
#pragma region f/p
private:
	Inventory* inventory = nullptr; 
#pragma endregion f/p
#pragma region constructor/destructor
public: 
	Mob() = default;
	Mob(const std::string& _name, Vector2* _position = new Vector2(0, 0),const float _maxLife = 100.0f, const float _maxMana = 100.0f);
	Mob(const Mob& _copy); 
	~Mob(); 
#pragma endregion constructor/destructor
#pragma region methods
public:
	Inventory* GetInventory() const; 
	void Move() override; 
#pragma endregion methods 
};

