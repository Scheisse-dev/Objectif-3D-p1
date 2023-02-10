#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Manager/UIElement/UIElementManager.h"
#include "../../Time/Time.h"
#include "../../UI/UIElement.h"
#include "../../UI/Label/UI_Label.h"
#include "../../UI/Radio/UI_Radio.h"
#include "../../UI/Shape/UI_Shape.h"
#include "../../Utils/CoreDefine.h"

#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Time/Time.h"

Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080)
{
}
Engine::Window::EngineWindow::EngineWindow(const EngineWindow& _copy)
    :Window<EngineWindow>(_copy.name, _copy.width, _copy.height)
{
}
void Engine::Window::EngineWindow::Open()
{
    super::Open();
    SetFrameLimit(60);
}
void Engine::Window::EngineWindow::OnUpdate()
{
    Time::deltaTime = clock.restart().asSeconds();
    Manager::GameObjectManager::Instance()->Update();
    Clear();
    Manager::GameObjectManager::Instance()->Draw(this);

    Display();
}
void Engine::Window::EngineWindow::OnClear() const
{
    super::OnClear();
}
void Engine::Window::EngineWindow::OnReceiveEvent(const sf::Event& _event)
{
    super::OnReceiveEvent(_event);
}
