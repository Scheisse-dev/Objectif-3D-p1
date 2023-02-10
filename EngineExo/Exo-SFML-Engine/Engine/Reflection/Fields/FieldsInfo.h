#pragma once
#include "../../Object/Object.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../Flags/BindingFlags.h"

namespace Engine::Reflection
{
    UCLASS()
    class FieldsInfo : public Object
    {
        DECLARE_CLASS_INFO(FieldsInfo, Object)
#pragma region var
    private:
        PrimaryType::String name = "";
        Object* reflectedObject = nullptr;
        BindingFlags flags = BindingFlags::NoPublic;
#pragma endregion
#pragma region const
    public:
        FieldsInfo() = default;
        FieldsInfo(const PrimaryType::String& _name, Object* _reflected, BindingFlags flags);
#pragma endregion
#pragma region methods
    public:
        const char* Name() const;
        Object* ReflectedObject() const;
        BindingFlags Flags() const;

        PrimaryType::Boolean IsReflectedClass();
        PrimaryType::Boolean IsPublic();
        PrimaryType::Boolean IsPrivate();
        PrimaryType::Boolean IsStatic();
        PrimaryType::Boolean IsArray();
#pragma endregion
#pragma region override
    public:
        PrimaryType::String ToString() const override;
#pragma endregion
#pragma region operator
    public:
        Object& operator=(const Object* _obj);
#pragma endregion

    };

}
