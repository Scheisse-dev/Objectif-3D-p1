#include "EventSystem.h"
#include "../../UI/Element/UIElement.h"
#include "../../UI/Interface/IPointerClickHandler.h"
#include "../../UI/Interface/IPointerEnterHandler.h"
#include "../../UI/Interface/IPointerExitHandler.h"
#include "../../UI/Interface/IPointerMoveHandler.h"
#include "../../UI/Interface/ITextEntered.h"

#pragma region const
Engine::Manager::EventSystem::EventSystem(const EventSystem& _copy) = default;
#pragma endregion
#pragma region meth
void Engine::Manager::EventSystem::RemoverHoveredElements(const UI::UIElement* _element)
{
    std::vector<UI::UIElement*>::iterator _index = std::find(hoveredElements.begin(), hoveredElements.end(), _element);
    if (_index == hoveredElements.end()) return;
    hoveredElements.erase(_index);
}
void Engine::Manager::EventSystem::Register(UI::UIElement* _element)
{
    elements.push_back(_element);
}

void Engine::Manager::EventSystem::UnRegister(UI::UIElement* _element)
{
    std::vector<UI::UIElement*>::iterator _index = std::find(elements.begin(), elements.end(), _element);
    if (_index == elements.end()) return;
    elements.erase(_index);
}

void Engine::Manager::EventSystem::Update(const sf::Event& _event,sf::RenderWindow* _window)
{
    const sf::Vector2i _position = sf::Mouse::getPosition(*_window);
    const sf::Vector2f _mousePosition = sf::Vector2f(_position.x, _position.y);
    for (UI::UIElement* _element : elements)
    {
        if (_element->Shape() == nullptr || !_element->IsActive() || !_element->CanInteract()) continue;
        if (_element->Shape()->getGlobalBounds().contains(_mousePosition))
        {
            CheckPointerMoveHandler(_event, _element);
            CheckPointerClickHandler(_element, _event);
            CheckEnterHandler(_element);
            CheckTextEntered(_event, _element);
        }
        else CheckExitHandler(_element);   
    }
}

void Engine::Manager::EventSystem::CheckTextEntered(const sf::Event& _event, Engine::UI::UIElement* _element)
{
    if (_event.type == sf::Event::TextEntered)
    {
        ITextEntered* _textEntered = dynamic_cast<ITextEntered*>(_element);
        if (_textEntered != nullptr) _textEntered->OnTextEntered(_event.text.unicode);

    }
}

void Engine::Manager::EventSystem::CheckPointerMoveHandler(const sf::Event& _event, Engine::UI::UIElement* _element)
{
    if (_event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        IPointerMoveHandler* _moveHandler = dynamic_cast<IPointerMoveHandler*>(_element);
        IPointerClickHandler* _clickHandler = dynamic_cast<IPointerClickHandler*>(_element);
        if (_moveHandler != nullptr)
        {
            if (pointer != _clickHandler)
            {
                if (pointer != nullptr) pointer->OnPointerUnClick();
                pointer = _clickHandler;
            }
            _moveHandler->OnPointerMove((float)_event.mouseMove.x, (float)_event.mouseMove.y);
        }
    }
}

void Engine::Manager::EventSystem::CheckEnterHandler(Engine::UI::UIElement*& _element)
{
    if (std::find(hoveredElements.begin(), hoveredElements.end(), _element) == hoveredElements.end())
    {
        IPointerEnterHandler* _pointerEnter = dynamic_cast<IPointerEnterHandler*>(_element);
        if (_pointerEnter != nullptr)
        {
            _pointerEnter->OnPointerEnter();
            hoveredElements.push_back(_element);
        }

    }
}

void Engine::Manager::EventSystem::CheckPointerClickHandler(Engine::UI::UIElement* _element, const sf::Event& _event)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        
        IPointerClickHandler* _mouseClick = dynamic_cast<IPointerClickHandler*>(_element);
        if (_mouseClick != nullptr)
        {
            if (pointer != _mouseClick)
            {
                if (pointer != nullptr) pointer->OnPointerUnClick();
                pointer = _mouseClick;
            }
        _mouseClick->OnPointerClick(_event);
        }
    }
}

void Engine::Manager::EventSystem::CheckExitHandler(Engine::UI::UIElement* _element)
{
    IPointerExitHandler* _pointerExit = dynamic_cast<IPointerExitHandler*>(_element);
    if (_pointerExit != nullptr)
    {
        _pointerExit->OnPointerExit();
        RemoverHoveredElements(_element);
    }
}

void Engine::Manager::EventSystem::Draw(sf::RenderWindow* _window)
{
    for (UI::UIElement* _element : elements)
    {
        if (!_element->IsActive()) continue;
        _element->Draw(_window);
    }
}
#pragma endregion 
void Engine::Manager::EventSystem::OnDestroy()
{
    for (UI::UIElement*& _element : elements)
    {
        delete _element;
        _element = nullptr; 
    }
    elements.clear();
    hoveredElements.clear();
}
