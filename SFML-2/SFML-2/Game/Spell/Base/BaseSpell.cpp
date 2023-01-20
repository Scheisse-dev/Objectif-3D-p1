#include "BaseSpell.h"

#pragma region constructor/destructor
Game::Spell::BaseSpell::BaseSpell(const char* _name)
{
	name = _name;
}
#pragma endregion constructor/destructor
#pragma region methods
bool Game::Spell::BaseSpell::IsInCooldown() const
{
	return currentCooldown;
}
float Game::Spell::BaseSpell::Cooldown() const
{
	return cooldown;
}
float Game::Spell::BaseSpell::ManaCost() const
{
	return manaCost;
}
std::string Game::Spell::BaseSpell::Name() const
{
	return name;
}
Game::Entity::Entity* Game::Spell::BaseSpell::Owner() const
{
	return owner;
}
#pragma endregion methods