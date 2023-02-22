#pragma once
#include "../Object/Object.h"
#include "../UI/Element/UIElement.h"
#include "../PrimaryType/Vector2/Vector2.h"

namespace Engine::Editor
{

    enum class EValueType
    {
        Int,
        Bool,
        Float,
        Double,
        String,
        List,
        Vector,
        Object,
    };

    class Editor : public Object
    {
        DECLARE_CLASS_INFO(Editor, Object)
#pragma region f.p
    private:
        std::vector<UI::UIElement*> elements = std::vector<UI::UIElement*>();
        Object* currentObjectEdit = nullptr;
        PrimaryType::Vector2 currentPosition = PrimaryType::Vector2(0, 0);
        PrimaryType::Vector2 initialPosition = PrimaryType::Vector2(0, 0);
#pragma endregion
#pragma region const
    public:
        Editor() = default;
        Editor(Object* _obj);
#pragma endregion
#pragma region meth
    private:
        EValueType GetValueType(Object* _obj);
    public:
        void SetObjectEdit(Object* _obj);
        void SetPosition(const PrimaryType::Vector2& _pos);
        virtual void InspectorGUI();
        Object* ObjectEdit();
        std::vector<UI::UIElement*> Elements() const;
#pragma endregion
    };

}
