#pragma once
#include "../../Object/Object.h"

namespace Engine::PrimaryType
{
	class ValueType : public Object
	{
		DECLARE_CLASS_INFO_FLAGS(ValueType, Object, ClassFlags::Type)
#pragma region const/dest
	public:
		ValueType() = default;
		~ValueType() override = default;
#pragma endregion
#pragma region operator
	public:
        Object& operator=(const Object* _other) override
        {
            return super::operator=(_other);
        }

        ValueType& operator=(const ValueType&) // alors la c'est assez drôle vue que faire ça ou lui = default c'est la même mdr
        {
            return *this;
        }
#pragma endregion
	};
}

