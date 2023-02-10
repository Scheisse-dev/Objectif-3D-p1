#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
    class Boolean : public ValueType
    {
        DECLARE_CLASS_INFO(Boolean, ValueType)
#pragma region var
    private:
        bool value = false;
#pragma endregion
#pragma region const
    public:
        Boolean() {}
        Boolean(bool _value);
#pragma endregion

#pragma region override
    public:
        PrimaryType::String ToString() const override;
        void SerializeField(std::ostream& _os, const PrimaryType::String& _fieldName, int _index) override;
        void DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName) override;
#pragma endregion
#pragma region operator
    public:
        Boolean& operator=(const Boolean& _other);
        Boolean operator-() const;
        operator bool();
        operator bool() const;
#pragma endregion

    };

}


namespace Engine::PrimaryType
{
    class Boolean;
    REGISTER_CLASS(Boolean)
}
