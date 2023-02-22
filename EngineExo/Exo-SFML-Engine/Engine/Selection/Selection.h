#pragma once
#include "../Object/Object.h"
#include "../Event/Action/ActionInternal.h"
#include "../Utils/Singleton/Singleton.h"
namespace Engine
{
    class Selection : public Utils::Singleton<Selection>
    {
        DECLARE_CLASS_INFO(Selection, Utils::Singleton<Selection>)
#pragma region var
    private:
        Object* selected = nullptr;
    public:
        static inline Action<Object*> OnSelectionChanged = nullptr;
#pragma endregion
        Selection() = default;
#pragma region const
        
#pragma endregion
#pragma region methods
    public:
        void SetSelection(Object* _obj);
        Object* GetSelected();
#pragma endregion
    };
}
