#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../Time/Time.h"
#include "../../Utils/CoreDefine.h"
#include "EngineWindow.h"
#include "../../Time/Time.h"
#include "SFML/Graphics.hpp"
#include "../../UI/Button/Button.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../Editor/Window/EditorWindow.h"



Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080) 
{


}


void Engine::Window::EngineWindow::RegisterEditorWindow(Editor::EditorWindow* _window)
{
    editorWindows.push_back(_window);
}

void Engine::Window::EngineWindow::UnRegisterEditorWindow(Editor::EditorWindow* _window)
{
    std::erase(editorWindows, _window);
}

Engine::Window::EngineWindow::EngineWindow(const EngineWindow& _copy)
    :Window<EngineWindow>(_copy.name, _copy.width, _copy.height) {}



void Engine::Window::EngineWindow::Open()
{
    super::Open();

}
void Engine::Window::EngineWindow::OnUpdate()
{

    Time::deltaTime = clock.restart().asSeconds();

    Manager::GameObjectManager::Instance()->Update();
    Clear();
    Manager::GameObjectManager::Instance()->Draw(this);


    for (Editor::EditorWindow* _editorWindow : editorWindows)
        _editorWindow->Draw(renderer);

    Manager::EventSystem::Instance()->Draw(renderer);
    Display();
}
void Engine::Window::EngineWindow::OnClear() const
{
    super::OnClear();
}
void Engine::Window::EngineWindow::OnReceiveEvent(const sf::Event& _event)
{
    super::OnReceiveEvent(_event);
    Manager::EventSystem::Instance()->Update(currentEvent, renderer);
}
