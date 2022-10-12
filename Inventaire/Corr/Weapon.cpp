#include "Weapon.h"
#include "Entity.h"
#include <iostream>

#pragma region constructor 
Weapon::Weapon(const std::string& _name, const float _dmg) : Item(_name)
{
	damage = _dmg;
	SetIsStackable(false);
}

Weapon::Weapon(const Weapon& _copy) : Item(_copy)
{
	damage = _copy.damage; 
#pragma endregion constructor 
#pragma region methods


#pragma endregion methods
}

float Weapon::Damage() const
{
	return damage;
}

void Weapon::SetDamage(const float _dmg)
{
	damage = _dmg; 
}

std::string Weapon::ToString() const
{
	return Item::ToString() + ", damage: " + std::to_string(damage);
}

void Weapon::OneUse(Entity* _entity)
{
	_entity->TakeDamage(damage); 
	std::cout << _entity->Name() + " receive: " + std::to_string(damage) + " damage !" << std::endl; 
}

