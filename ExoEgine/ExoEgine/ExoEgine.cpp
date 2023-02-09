#include <iostream>
#include <filesystem>
#include "Assembly.h"
#include "Engine/Window/Engine/EngineWindow.h"
#include "Engine/UI/Interactable/Toggle/Toggle.h"

int main()
{

	//Toggle* to = new Toggle();

	
	Engine::Window::EngineWindow::Instance()->Open();
	

	//Engine::GameObject* o = new Engine::GameObject();
	//std::string _assetPath = std::filesystem::current_path().string();
	//_assetPath = Engine::PrimaryType::String((_assetPath + "\\Asset\\GameObject.asset").c_str());
	//std::ifstream _if = std::ifstream(_assetPath);
	//o->DeSerialize(_if);
	//_if.close();
	//o->OnDeserializeFinish();

}