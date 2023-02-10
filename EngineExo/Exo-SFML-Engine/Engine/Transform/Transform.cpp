#include "Transform.h"

#pragma region const
Engine::Transform::Transform(const Transform& _copy)
    : super(_copy)
{
    position = _copy.position;
}
#pragma endregion

#pragma region operator
Engine::Object& Engine::Transform::operator=(const Engine::Object* _obj)
{
    const Transform* _other = dynamic_cast<const Transform*>(_obj);
    check((_other != nullptr), "[Transform] operator= _obj is not Transform", *this)
        super::operator=(_obj);
    position = _other->position;
    return *this;
}
#pragma endregion
