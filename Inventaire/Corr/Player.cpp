#include <iostream>
#include "Player.h"
#include "Inventory.h"
#include "Utils.h"
#include "Vector2.h"
#include "Map.h"


#pragma region constructor/destructor
Player::Player(const std::string& _name, Vector2* _position, const float _maxLife, const float _maxMana)
    :Entity( _name, _position,  _maxLife, _maxMana)
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

void Player::Move()
{
	char _imput = Utils::UserChoice<char>("(z,q,s,d) for movement: ");
	Vector2 _position = *Position(); 
	switch (std::tolower(_imput))
	{
	case 'z': 
		//_position.Set(Vector2(_position.X(), _position.Y() - 1)); 
		_position -= Vector2(0, 1); 
		break;
	case 'q': 
		//_position.Set(Vector2(_position.X()- 1, _position.Y()));
		_position -= Vector2(1, 0);
		break;
	case 's': 
		//_position.Set(Vector2(_position.X(), _position.Y() + 1));
		_position += Vector2(0, 1);
		break;
	case 'd': 
		//_position.Set(Vector2(_position.X() + 1 , _position.Y()));
		_position += Vector2(1, 0);
		break;
	default: 
		break; 
	}
	Case* _case = GetMap()->GetCaseAtPosition(_position); 
	if (_case == nullptr || _case->IsWall()) return;
	Position()->Set(_position); 
}
#pragma endregion Methods
/*
//position ->  vector 2 
void Player::Move(Vector2* _position, char _imput)
{
	while (_imput != up || down || left || right)
	{
		std::cin >> _imput;
	}
	if (_imput == up)
	{
		position = Vector2* _position(x, y);  // Y-1 
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
	position = _position; 
}*/
