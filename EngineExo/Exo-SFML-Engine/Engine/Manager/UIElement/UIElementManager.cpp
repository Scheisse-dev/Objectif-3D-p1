#include "UIElementManager.h"
#include "../../UI/UIElement.h"
#include "../../Window/Engine/EngineWindow.h"

#pragma region const
Engine::Manager::UIElementManager::UIElementManager(const UIElementManager& _copy)
{
    elements = _copy.elements;
}
#pragma endregion

#pragma region methods
void Engine::Manager::UIElementManager::Register(UIElement* _obj)
{
    elements.push_back(_obj);
}

void Engine::Manager::UIElementManager::UnRegister(UIElement* _obj)
{
    for (size_t i = 0; i < elements.size(); i++)
        if (elements[i] == _obj)
        {
            delete elements[i];
            elements.erase(elements.begin() + i);
        }
}

void Engine::Manager::UIElementManager::Update()
{
    for (UIElement* _element : elements)
    {
        if (_element->IsInteractable())
        {
            _element->Update();
        }
    }
}

void Engine::Manager::UIElementManager::Draw(const Window::EngineWindow* _window) const
{
    for (UIElement* _obj : elements)
        _obj->Draw(_window);
}

void Engine::Manager::UIElementManager::OnDestroy()
{
    for (const UIElement* _element : elements)
    {
        delete _element;
        _element = nullptr;
    }
    elements.clear();
}
#pragma endregion

