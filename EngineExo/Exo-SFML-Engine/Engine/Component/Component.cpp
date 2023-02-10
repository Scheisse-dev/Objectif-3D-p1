#include "Component.h"
#include "../Utils/DebugMacro.h"

#pragma region const
Engine::Component::Component(const Component& _copy)
{
    gameObject = _copy.gameObject;
    enabled = _copy.enabled;
}
#pragma endregion

#pragma region operator
Engine::Object& Engine::Component::operator=(const Object* _obj)
{
    const Component* _other = dynamic_cast<const Component*>(_obj);
    check((_other != nullptr), "[Component] operator= _obj is not Component", *this)
        super::operator=(_obj);
    enabled = _other->enabled;
    gameObject = _other->gameObject;
    return *this;
}
#pragma endregion

