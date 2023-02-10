#pragma once
#include "../Component/Component.h"
#include "../PrimaryType/Vector2/Vector2.h"
#include "../Utils/DebugMacro.h"

namespace Engine
{
    UCLASS()
        class Transform : public Component
    {
        DECLARE_CLASS_INFO(Transform, Component)
#pragma region var
    public:
        UPROPERTY() PrimaryType::Vector2 position = PrimaryType::Vector2(0, 0);
REGISTER_FIELD(position, &position, BindingFlags::Public)
#pragma endregion
#pragma region const
    public:
        Transform() = default;
#pragma endregion
#pragma region operator
    public:
        Transform& operator=(const Transform& _other) = default;
        Object& operator=(const Object* _obj) override;
#pragma endregion
    };
}


