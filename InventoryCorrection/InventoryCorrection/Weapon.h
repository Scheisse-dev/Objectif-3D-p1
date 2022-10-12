#pragma once
#include "Item.h"

class Weapon : public Item
{
#pragma region f/p
private:
	float damage = 0.0f;
#pragma endregion f/p
#pragma region constructor
public:
	Weapon() = default;
	Weapon(const std::string& _name, const float _dmg);
	Weapon(const Weapon& _copy);
#pragma endregion constructor
#pragma region methods
public:
	float Damage() const;
	void SetDamage(const float _dmg);
	std::string ToString() const override;
	void OnUse(Entity* _entity) override;
#pragma endregion methods
};

