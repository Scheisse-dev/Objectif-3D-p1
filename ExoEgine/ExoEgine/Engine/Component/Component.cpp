#include "Component.h"
#include "../Utils/DebugMacro.h"

#pragma region operator
Engine::Object& Engine::Component::operator=(const Object* _obj)
{
	const Component* _other = dynamic_cast<const Component*>(_obj);
	check((_other != nullptr), "[Component] operator= _obj is no Component", *this)
	super::operator=(_obj);
	enable = _other->enable;
	gameobject = _other->gameobject;
	return *this;
}
#pragma endregion operator