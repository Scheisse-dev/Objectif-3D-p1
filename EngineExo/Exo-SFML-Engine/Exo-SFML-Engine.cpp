// Exo-SFML-Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine/Utils/DebugMacro.h"
#include "Engine/Object/Object.h"
#include "Engine/GameObject/GameObject.h"
#include "Engine/AssetDataBase/AssetDataBase.h"
#include "Engine/Manager/GameObject/GameObjectManager.h"
#include "Engine/Window/Engine/EngineWindow.h"
#include "Engine/AssetDataBase/AssetDataBase.h"
#include "Engine/Utils/ObjectMacro.h"
#include "Test/Reflexion/Json/JsonTest.h"
#include "Test/Component/PlayerComponent.h"
#include "Assemblie.h"
#include <iostream>

int main()
{
    //Test::JsonTest::Test();
    /*Engine::GameObject* _go = Engine::GameObject::CreatePrimitive(PrimitiveType::Circle, "Test");
    _go->AddComponent<Test::PlayerComponent>();*/

    //Engine::Window::EngineWindow::Instance()->Open();
    //Engine::Manager::GameObjectManager::Instance()->Destroy();
    std::cout << "coucou" << std::endl;
}
