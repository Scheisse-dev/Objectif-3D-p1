#include <iostream>
#include "Player.h"
#include "Inventory.h"


#pragma region constructor/destructor
Player::Player(const std::string& _name,Vector2* _position/*changement de cette donnée*/, const float _maxLife, const float _maxMana)
    :Entity(_name,_position,  _maxLife, _maxMana)
{
    inventory = new Inventory(_name + " Inventory", this);
}

Player::Player(const Player& _copy): Entity(_copy)
{
    inventory = _copy.inventory;
}
Player::~Player()
{
    delete inventory; 
}
#pragma endregion constructor/destructor

Inventory* Player::GetInventory() const
{
    return inventory;
}

//position ->  vector 2 
void Player::Move(Vector2* _position, char _imput)
{
	while (_imput != up || down || left || right)
	{
		std::cin >> _imput;
	}
	if (_imput == up)
	{
		position = _position;  // Y-1 
	}
	else if (_imput == down)
	{
		_position; // Y+1
	}
	else if (_imput == left)
	{
		_position; // X-1
	}
	else if (_imput == right)
	{
		_position; // X +1
	}
		
}
