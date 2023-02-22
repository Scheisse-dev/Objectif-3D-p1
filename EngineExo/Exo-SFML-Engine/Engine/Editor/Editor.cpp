#include "Editor.h"
#include "../Manager/EventSystem/EventSystem.h"
#include "../PrimaryType/Integer/Integer.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../PrimaryType/Float/Float.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Vector2/Vector2.h"
#include "../PrimaryType/Double/Double.h"
#include "../PrimaryType/List/IList.h"
#include "../UI/Toggle/Toggle.h"
#include "../Reflection/Fields/FieldsInfo.h"

#pragma region const
Engine::Editor::Editor::Editor(Object* _obj)
{
    currentObjectEdit = _obj;
}

Engine::Editor::Editor::Editor(const Editor& _copy)
{
    currentObjectEdit = _copy.currentObjectEdit;
}
#pragma endregion
Engine::Editor::EValueType Engine::Editor::Editor::GetValueType(Object* _obj)
{
    if (dynamic_cast<PrimaryType::Integer*>(_obj)) return EValueType::Int;
    if (dynamic_cast<PrimaryType::String*>(_obj)) return EValueType::String;
    if (dynamic_cast<PrimaryType::Float*>(_obj)) return EValueType::Float;
    if (dynamic_cast<PrimaryType::Double*>(_obj)) return EValueType::Double;
    if (dynamic_cast<PrimaryType::Boolean*>(_obj)) return EValueType::Bool;
    if (dynamic_cast<PrimaryType::Vector2*>(_obj)) return EValueType::Vector;
    if (dynamic_cast<PrimaryType::IList*>(_obj)) return EValueType::List;
    return EValueType::Object;
}
void Engine::Editor::Editor::SetObjectEdit(Object* _obj)
{
    for (Engine::UI::UIElement* _element : elements)
    {
        Manager::EventSystem::Instance()->UnRegister(_element);
        delete _element;
    }
    elements.clear();
    currentPosition = initialPosition;
    currentObjectEdit = _obj;
}

void Engine::Editor::Editor::SetPosition(const PrimaryType::Vector2& _pos)
{
    currentPosition = _pos;
    initialPosition = _pos;
}

void Engine::Editor::Editor::InspectorGUI()
{
    if (currentObjectEdit == nullptr) return;
    currentPosition.y += 30;
    std::vector<Reflection::FieldsInfo*> _allFields = currentObjectEdit->Fields();
    for (Reflection::FieldsInfo* _field : _allFields)
    {
        switch (GetValueType(_field->ReflectedObject()))
        {
        case EValueType::Int: break;
        case EValueType::Bool:
        {
            PrimaryType::Boolean* _value = dynamic_cast<PrimaryType::Boolean*>(_field->ReflectedObject());
            UI::Toggle* _toggle = new UI::Toggle(*_value);
            _toggle->SetPosition(currentPosition);
            elements.push_back(_toggle);
            currentPosition.y += _toggle->Shape()->getGlobalBounds().height;
            break;
        }
        case EValueType::Float: break;
        case EValueType::Double: break;
        case EValueType::String: break;
        case EValueType::List: break;
        case EValueType::Vector: break;
        case EValueType::Object: break;
        }
    }
}

Engine::Object* Engine::Editor::Editor::ObjectEdit()
{
    return nullptr;
}

std::vector<Engine::UI::UIElement*> Engine::Editor::Editor::Elements() const
{
    return std::vector<UI::UIElement*>();
}
