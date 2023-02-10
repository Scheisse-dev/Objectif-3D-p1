#pragma once
#include "../Function.h"
#include "../../Flags/BindingFlags.h"

namespace Engine
{
    class Object;
}

namespace Engine::Reflection
{
    template <typename Res, typename... Params>
    class MethodsInfo : public Function
    {
#pragma region var
    private:
        typedef Res(Object::* FunctionType)(Params...);
        typedef Res(*StaticFunctionType)(Params...);
        FunctionType function = nullptr;
        StaticFunctionType staticFunction = nullptr;
        BindingFlags flags = BindingFlags::NoPublic;
#pragma endregion
#pragma region const/dest
    public:
        MethodsInfo() = default;
        template <typename Class>
        MethodsInfo(const std::string& _name, Res(Class::* _ptr)(Params...), const std::vector<ParameterInfo*>& _params, const BindingFlags _flags)
            : Function(_name, _params)
        {
            if constexpr (!std::is_base_of_v<Object, Class>)
                throw std::exception("Class must be inherited of Object");
            function = reinterpret_cast<FunctionType>(_ptr);
            flags = _flags;
        }
        MethodsInfo(const std::string& _name, Res(* _ptr)(Params...), const std::vector<ParameterInfo*>& _params, const BindingFlags _flags)
            : Function(_name, _params)
        {
            staticFunction = _ptr;
            flags = _flags;
        }
#pragma endregion
#pragma region methods
    public:
        BindingFlags Flags() const
        {
            return flags;
        }
        Res Invoke(Object* _instance, Params... _params)
        {
            if (function != nullptr)
                return (_instance->*function)(_params...);
            return staticFunction(_params...);
        }
        void* GetAddress() const
        {
            if (function != nullptr)
                return (void*&)&function;
            return (void*&)&staticFunction;
        }
#pragma endregion
#pragma region operator
    public:
        bool operator==(nullptr_t)
        {
            return function == nullptr || staticFunction == nullptr;
        }
        bool operator!=(nullptr_t)
        {
            return function != nullptr || staticFunction != nullptr;
        }

        bool operator==(const MethodsInfo& _other)
        {
            return GetAddress() == _other.GetAddress();
        }
        bool operator!=(const MethodsInfo& _other)
        {
            return GetAddress() != _other.GetAddress();
        }

        template<typename Class>
        bool operator==(Res(Class::* _ptr)(Params...))
        {
            return GetAddress() == (void*&)_ptr;
        }
        template<typename Class>
        bool operator!=(Res(Class::* _ptr)(Params...))
        {
            return GetAddress() != (void*&)_ptr;
        }
#pragma endregion

    };
}
