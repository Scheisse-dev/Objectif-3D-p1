#pragma once
#include "../../Object/Object.h"

namespace Engine::Utils
{
    template <typename T>
    class Singleton : public Object
    {
        DECLARE_CLASS_INFO(Singleton<T>, Object)
#pragma region var
    private:
        static inline T* instance = nullptr;
#pragma endregion
#pragma region const/dest
    public:
        Singleton() = default;
        ~Singleton() override
        {
            OnDestroy();
        }
#pragma endregion
#pragma region methods
    public:
        static T* Instance()
        {
            if (instance == nullptr)
                instance = new T();
            return instance;
        }

        void Destroy()
        {
            delete instance;
            instance = nullptr;
        }

        virtual void OnDestroy() {}
#pragma endregion

    };
}

template <typename T>
Engine::Utils::Singleton<T>::Singleton(const Singleton& _copy)
{
    instance = _copy.instance;
}
