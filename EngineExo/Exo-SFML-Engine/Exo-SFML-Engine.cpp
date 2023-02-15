// Exo-SFML-Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine/Manager/FontManager.h"
#include "Engine/Window/Engine/EngineWindow.h"
#include "Engine/Manager/GameObject/GameObjectManager.h"
#include "Engine/Manager/Texture/TextureManager.h"
#include "Test/Reflexion/Json/JsonTest.h"

int main()
{
    Test::JsonTest::Test();
    Engine::Manager::FontManager::Instance()->Init();
    Engine::Manager::TextureManager::Instance()->Init();
    //Test::JsonTest::Test();
    /*Engine::GameObject* _go = Engine::GameObject::CreatePrimitive(PrimitiveType::Circle, "Test");
    _go->AddComponent<Test::PlayerComponent>();*/

    Engine::Window::EngineWindow::Instance()->Open();

    Engine::Manager::GameObjectManager::Instance()->Destroy();
    Engine::Manager::FontManager::Instance()->Destroy();
    Engine::Manager::TextureManager::Instance()->Destroy();
    //Engine::Manager::GameObjectManager::Instance()->Destroy();
    //std::cout << "coucou" << std::endl;
}
