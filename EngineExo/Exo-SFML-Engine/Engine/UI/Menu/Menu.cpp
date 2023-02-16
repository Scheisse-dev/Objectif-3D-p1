#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../Label/Label.h"
#include "../Button/Button.h"
#include "../../Utils/ObjectMacro.h"
#include "../../../Test/Z.h"
#include "../Slider/Slider.h"
#include "../Toggle/Toggle.h"
#include "../TextField/TextField.h"
#include <iostream>
#include <filesystem>
#include <fstream>

#pragma region const
Engine::UI::Menu::Menu()
{
    SetUiBar();
    SetMenuLabel(); 
    CREATE_BUTTON(Loutre, 50);
    
}
Engine::UI::Menu::Menu(const Menu& _copy) : super()
{

}
Engine::UI::Menu::~Menu()
{
    delete assetLabel;
    assetLabel = nullptr;
    delete sideBar;
    sideBar = nullptr;
    delete buttonBar;
    buttonBar = nullptr;
    delete menuLabel;
    menuLabel = nullptr;
}
#pragma endregion 
#pragma region meth
void Engine::UI::Menu::SetUiBar()
{
    sideBar = new sf::RectangleShape(sf::Vector2f(600, 1080));
    sideBar->setFillColor(sf::Color(178, 190, 181));
    sideBar->setPosition(sf::Vector2f(1700, 0));
    buttonBar = new sf::RectangleShape(sf::Vector2f(1920, 250));
    buttonBar->setFillColor(sf::Color(178, 190, 181));
    buttonBar->setPosition(sf::Vector2f(0, 900));
}

void Engine::UI::Menu::SetMenuLabel()
{
    assetLabel = new Label();
    assetLabel->SetPosition(sf::Vector2f(0, 900));
    assetLabel->SetColor(sf::Color::Black);
    assetLabel->SetLabel("asset");
    menuLabel = new Label();
    menuLabel->SetLabel("Menu");
    menuLabel->SetPosition(sf::Vector2f(1700, 0));
    menuLabel->SetColor(sf::Color::Black);
}
void Engine::UI::Menu::DisplayMenu() //add var name
{
    Clear(); 
    slider = new Slider();
    slider->SetPosition(sf::Vector2f(1750, 50));
    toggle = new Toggle();
    toggle->SetPosition(sf::Vector2f(1750, 100));
    textField = new TextField();
    textField->SetPosition(sf::Vector2f(1750, 150));
}
void Engine::UI::Menu::DeserielizeData()
{
    const std::string _path = std::filesystem::current_path().string();
    Test::Z z = Test::Z();
    std::ifstream _inFile = std::ifstream(_path + "\\a.asset");
    z.DeSerializeField(_inFile, "ball");
    z.Ball();
    
    
    
    _inFile.close(); \

    //GetType of object
    // Macro -> DeserielizeData(ClassName)
    //

}
void Engine::UI::Menu::Clear()
{
    delete slider;
    delete toggle;
    delete textField;
    slider = nullptr;
    toggle = nullptr;
    textField = nullptr;


}
#pragma endregion
#pragma region override


void Engine::UI::Menu::Draw(sf::RenderWindow* _window)
{
   _window->draw(*buttonBar);
   _window->draw(*sideBar);
}



#pragma endregion