#include "Entity.h"
#include "Utils.h"
#include "Vector2.h"
#pragma region constructor
Entity::Entity(const std::string& _name, Vector2* _position, const float _maxLife, const float _maxMana)
{
	name = _name;
	position = _position; 
	life = maxLife = _maxLife; 
	mana = maxMana = _maxMana;
}

Entity::Entity(const Entity& _copy)
{
	name = _copy.name;
	position = _copy.position; 
	life = _copy.life;
	maxLife = _copy.maxLife;
	mana = _copy.mana;
	maxMana = _copy.maxMana;


}
Entity::~Entity()
{
	delete position; 
}
#pragma endregion constructor

#pragma region methods
Vector2* Entity::Position() const
{
	return position;
}
std::string Entity::Name() const
{
	return std::string();
}
std::string Entity::ToString() const
{
	return name + ": Life =>" + std::to_string(life) + ", Mana => " + std::to_string(mana);
}
float Entity::Life() const
{
	return life;
}
float Entity::MaxLife() const
{
	return maxLife;
}
float Entity::Mana() const
{
	return mana;
}
float Entity::MaxMana() const
{
	return maxMana;
}
bool Entity::IsDead() const
{
	return life == 0.0f;
}
bool Entity::HasMana(const float _cost)
{
	return mana >= _cost;
}
bool Entity::Equals(const Entity* _other)
{
	return name == _other->name;
}
void Entity::SetLife(const float _life)
{
	life = Utils::Clamp(_life, 0.0f, maxLife);
}
void Entity::SetMaxLife(const float _maxLife)
{
	maxLife = _maxLife; 
}
void Entity::AddLife(const float _value)
{
	life = Utils::Clamp(life + _value, 0.0f, maxLife); 

}
void Entity::TakeDamage(const float _dmg)
{
	life = Utils::Clamp(life - _dmg, 0.0f, maxLife); 
}
void Entity::AddMana(const float _value)
{
	mana = Utils::Clamp(mana + _value, 0.0f, maxMana);
}
void Entity::SetMana(const float _mana)
{
	mana = Utils::Clamp(mana, 0.0f, maxMana);
}
void Entity::SetMaxMana(const float _maxMana)
{
	mana = _maxMana;
}
void Entity::DecreaseMana(const float _value)
{
	mana = Utils::Clamp(mana - _value, 0.0f, maxMana);
}
Map* Entity::GetMap() const
{
	return currentMap;
}
void Entity::SetMap(Map* _map)
{
	currentMap = _map; 
}
#pragma endregion methods
