#include "UIElement.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../PrimaryType/String/String.h"
#include "../../Utils/DebugMacro.h"
#include "../../Utils/Template/Template.h"
#include "../../Manager/FontManager.h"
#include "../../Manager/EventSystem/EventSystem.h"

#pragma region const


Engine::UI::UIElement::UIElement()
{
    Manager::EventSystem::Instance()->Register(this);
}

Engine::UI::UIElement::UIElement(const char* _label)
{
    labelText.setString(_label);
    labelText.setCharacterSize(50);
    labelText.setFont(*Manager::FontManager::Instance()->GetFont("Duck"));
}

Engine::UI::UIElement::UIElement(const UIElement& _copy)
{
    shape = _copy.shape;
    labelText = _copy.labelText;
    canInteract = _copy.canInteract;
    isActive = _copy.isActive;
}

Engine::UI::UIElement::~UIElement()
{
    delete shape;
    shape = nullptr;
    Manager::EventSystem::Instance()->UnRegister(this);
}
#pragma endregion
#pragma region methods
void Engine::UI::UIElement::SetPosition(const PrimaryType::Vector2& _position)
{
    checkLow((shape != nullptr), "shape is nullptr");
    shape->setPosition(_position);
}

void Engine::UI::UIElement::SetRotation(const float _rotation)
{
    checkLow((shape != nullptr), "shape is nullptr");
    shape->setRotation(_rotation); //TODO change to float 
}

void Engine::UI::UIElement::SetScale(const PrimaryType::Vector2& _scale)
{
    checkLow((shape != nullptr), "shape is nullptr");
    shape->setScale(_scale); 
}

void Engine::UI::UIElement::SetOrigin(const PrimaryType::Vector2& _position)
{
    checkLow((shape != nullptr), "shape is nullptr");
    shape->setOrigin(_position);
}

void Engine::UI::UIElement::SetIsActive(bool _status)
{
    isActive = _status;
}

void Engine::UI::UIElement::SetCanBeInteract(bool _status)
{
    canInteract = _status;
}

void Engine::UI::UIElement::SetLabel(const char* _label)
{
    labelText.setString(_label);
}

bool Engine::UI::UIElement::CanInteract() const
{
    return canInteract;
}

bool Engine::UI::UIElement::IsActive() const
{
    return isActive;
}
Engine::PrimaryType::Vector2 Engine::UI::UIElement::Position() const
{
    check((shape != nullptr), "shape is nullptr", Engine::PrimaryType::Vector2(0, 0));
    return shape->getPosition(); // TODO change to float;
}

sf::Shape* Engine::UI::UIElement::Shape() const
{
    return shape;
}

float Engine::UI::UIElement::Rotation() const
{
    check((shape != nullptr), "shape is nullptr", PrimaryType::Float::NaN);
    return shape->getRotation();
}

Engine::PrimaryType::Vector2 Engine::UI::UIElement::Scale() const
{
    check((shape != nullptr), "shape is nullptr", Engine::PrimaryType::Vector2(0, 0));
    return shape->getScale();
}

Engine::PrimaryType::Vector2 Engine::UI::UIElement::Origin() const
{
    check((shape != nullptr), "shape is nullptr", Engine::PrimaryType::Vector2(0,0));
    return shape->getOrigin();
}

Engine::PrimaryType::String Engine::UI::UIElement::LabelText() const
{
    return labelText.getString().toAnsiString().c_str();
}

void Engine::UI::UIElement::Draw(sf::RenderWindow* _window)
{
    checkLow((shape != nullptr), "shape is nullptr");
    _window->draw(labelText);
    _window->draw(*shape);
}
#pragma endregion methods
#pragma region operator

Engine::Object& Engine::UI::UIElement::operator=(const Object* _obj)
{
    if (!IsSame<UIElement>(_obj)) return *this;
    const UIElement* _other = dynamic_cast<const UIElement*>(_obj);
    shape = _other->shape;
    labelText = _other->labelText;
    canInteract = _other->canInteract;
    isActive = _other->isActive;
    return *this;
}
#pragma endregion operator