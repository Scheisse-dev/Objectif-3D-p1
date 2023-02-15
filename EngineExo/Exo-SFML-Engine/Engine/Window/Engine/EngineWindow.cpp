#include "EngineWindow.h"
#include "../../Manager/GameObject/GameObjectManager.h"
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../Time/Time.h"
#include "../../Utils/CoreDefine.h"
#include "EngineWindow.h"
#include "../../Time/Time.h"
#include "SFML/Graphics.hpp"
#include "../../UI/Button/Button.h"
#include "../../UI/Toggle/Toggle.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../UI/Slider/Slider.h"
#include "../../UI/TextField/TextField.h"

Engine::Window::EngineWindow::EngineWindow() : super("Engine", 1920, 1080) 
{

}

Engine::Window::EngineWindow::EngineWindow(const EngineWindow& _copy)
    :Window<EngineWindow>(_copy.name, _copy.width, _copy.height) {}

void Engine::Window::EngineWindow::Test()
{
    LOG("Button CLick !");
}

void Engine::Window::EngineWindow::Open()
{


    UI::Button* button = new UI::Button("Play", 400, 100);
    button->AddListener(this, &EngineWindow::Test);
    button->SetPosition(PrimaryType::Vector2(100, 50));
    super::Open();
    //toggle = new UI::Toggle();
    //toggle->SetPosition(PrimaryType::Vector2(200, 100));
    //UI::Slider* slider = new UI::Slider(0.f, 100.f, 0.f);
    //slider->SetPosition(sf::Vector2f(300, 300));
    //UI::TextField* textfield = new UI::TextField("Password", PrimaryType::Vector2(200, 40));
    //textfield->SetPosition(sf::Vector2f(300, 500));
}
void Engine::Window::EngineWindow::OnUpdate()
{
    Time::deltaTime = clock.restart().asSeconds();

    Manager::GameObjectManager::Instance()->Update();
    Clear();
    
    Manager::GameObjectManager::Instance()->Draw(this);
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
