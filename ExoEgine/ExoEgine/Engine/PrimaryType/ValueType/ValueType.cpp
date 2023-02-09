#include "ValueType.h"


Engine::PrimaryType::ValueType::ValueType(const ValueType& _copy) = default;

Engine::Object& Engine::PrimaryType::ValueType::operator=(const Object* _other)
{
    return super::operator=(_other);
}
