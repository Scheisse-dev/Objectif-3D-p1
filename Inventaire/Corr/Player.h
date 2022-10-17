#pragma once
#include "Entity.h"
#include "Vector2.h"
#include "Case.h"

class Inventory;

class Player : public Entity 
{
#pragma region f/p
private: 
	Inventory* inventory = nullptr; 
	//int x; // position de l'entré -> case 
	//int y; // position de l'entré -> case 
	//char up = 'a';
	//char down = 's';
	//char left = 'q';
	//char right = 'd';
	//Vector2* position = new Vector2(); 
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Player() = default; 
	Player(const std::string& _name, Vector2* _position = new Vector2(0,0), const float _maxLife = 100.0f, const float _maxMana = 100.0f);
	Player(const Player& _copy);
	~Player();
#pragma endregion constructor/destructor
#pragma region methods
public: 
	Inventory* GetInventory() const;
	void Move() override;
#pragma endregion methods
};

