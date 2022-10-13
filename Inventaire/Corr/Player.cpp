#include "Player.h"
#include "Inventory.h"

#pragma region constructor/destructor
Player::Player(const std::string& _name,Vector2* _position, const float _maxLife, const float _maxMana)
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
