#include "Player.h"
#include "Inventory.h"

#pragma region constructor/destructor
Player::Player(const std::string& _name, const float _maxLife, const float _maxMana)
    : Entity(_name, _maxLife, _maxMana)
{
    inventory = new Inventory(_name + " Inventory", this);
}

Player::Player(const Player& _copy) : Entity(_copy)
{
    inventory = _copy.inventory;
}

Player::~Player()
{
    delete inventory;
}
#pragma endregion constructor/destructor

#pragma region methods
Inventory* Player::GetInventory() const
{
    return inventory;
}
#pragma endregion methods