#include "PotionHealth.h"
#include "Entity.h"
#include <iostream>

PotionHealth::PotionHealth(const float _value) : Potion("Potion Health", _value) { }

void PotionHealth::OnUse(Entity* _entity)
{
	Potion::OnUse(_entity);
	_entity->AddLife(Value());
	std::cout << "new life for " + _entity->Name() + ": " + std::to_string(_entity->Life()) << std::endl;
}
