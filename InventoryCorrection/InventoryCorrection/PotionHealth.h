#pragma once
#include "Potion.h"
class PotionHealth : public Potion
{
#pragma region constructor
public:
	PotionHealth() = default;
	PotionHealth(const float _value);
#pragma endregion constructor
#pragma region methods
public:
	void OnUse(Entity* _entity) override;
#pragma endregion methods
};

