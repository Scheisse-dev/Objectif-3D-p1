#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Time/Time.h"

Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080)
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
