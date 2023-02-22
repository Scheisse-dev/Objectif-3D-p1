#pragma once
#include "../../Object/Object.h"
#include "../../Utils/DebugMacro.h"
#include "../../PrimaryType/Boolean/Boolean.h"

namespace Engine::Event
{
    template <typename Res, typename... Params>
    class Delegate : public Object
    {
        DECLARE_CLASS_INFO(Delegate, Object)
#pragma region var
        typedef Res(Object::* Function)(Params...);
        Function function = nullptr;
        Object* instance = nullptr;
#pragma endregion
#pragma region const/dest
    public:
        Delegate(nullptr_t)
        {
            function = nullptr;
            instance = nullptr;
        }
        template <typename Class>
        Delegate(Class* _instance, Res(Class::* _ptr)(Params...))
        {
            checkBaseOf(Object, Class)
                instance = _instance;
            function = reinterpret_cast<Function>(_ptr);
        }
#pragma endregion
#pragma region methods
    public:
        void SetDynamic(nullptr_t)
        {
            function = nullptr;
            instance = nullptr;
        }

        template <typename Class>
        void SetDynamic(Class* _instance, Res(Class::* _ptr)(Params...))
        {
            checkBaseOf(Object, Class)
                instance = _instance;
            function = reinterpret_cast<Function>(_ptr);
        }

        Object* Instance()
        {
            return instance;
        }

        Res Invoke(Params... _params)
        {
            return (instance->*function)(_params...);
        }

        PrimaryType::Boolean IsValid()
        {
            return instance != nullptr && function != nullptr;
        }

        Object* Intance() const
        {
            return instance;
        }

        void* GetAddress() const
        {
            return (void*&)function;
        }
#pragma endregion
#pragma region operator
    public:
        PrimaryType::Boolean operator==(const Delegate& _other)
        {
            return GetAddress() == _other.GetAddress();
        }

        template <typename Class>
        PrimaryType::Boolean operator==(Res(Class::* _ptr)(Params...))
        {
            return GetAddress() == (void*&)_ptr;
        }

        

        Delegate& operator=(nullptr_t)
        {
            function = nullptr;
            instance = nullptr;
            return *this;
        }

        Res operator()(Params... _params)
        {
            return  (instance->*function)(_params...);
        }
#pragma endregion

    };

}

template <typename Res, typename... Params>
Engine::Event::Delegate<Res, Params...>::Delegate(const Delegate& _copy)
{
    function = _copy.function;
    instance = _copy.instance;
}
