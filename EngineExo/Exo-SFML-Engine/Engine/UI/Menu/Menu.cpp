#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "../../Manager/EventSystem/EventSystem.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../Label/Label.h"
#include "../Button/Button.h"
#include "../../Utils/ObjectMacro.h"
#include "../../Reflection/Utils/ReflectionUtils.h"
#include "../Slider/Slider.h"
#include "../Toggle/Toggle.h"
#include "../TextField/TextField.h"
#include "../../../Test/Z.h"
#include <iostream>



//Deserielize data -> index for button
// get type -> object macro
// Macro name of class -> deserielize -> getName
// 
//

#pragma region const
Engine::UI::Menu::Menu() : super()
{
    std::ifstream _in(_path + "\\b.asset");
    z.DeSerialize(_in);

    SetUiBar();
    SetMenuLabel(); 
    button = new Engine::UI::Button("delete", 100, 50);
    button->SetPosition(sf::Vector2f(500, 900));
    button->AddListener(this, &Menu::Clear);
    loutre = new Engine::UI::Button("loutre", 100, 50);
    loutre->SetPosition(sf::Vector2f(50, 900));
    loutre->AddListener(this, &Menu::DisplayMenu);

    toggle = new UI::Toggle();
    toggle->SetPosition(sf::Vector2f(1750, 100));
    toggle->SetIsActive(false);

    slider = new UI::Slider();
    slider->SetPosition(sf::Vector2f(1750, 300));
    slider->SetIsActive(false);
    
    textField = new TextField();
    textField->SetPosition(sf::Vector2f(1750, 600));
    textField->SetIsActive(false);
    
    rec.setPosition(500, 500);

    slider->SetValue(z.Pint());
    toggle->SetStatus(z.Ball());
    
}
Engine::UI::Menu::Menu(const Menu& _copy) : super(_copy)
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
    if (toggle == nullptr || slider == nullptr || textField == nullptr) return;
    else
    {
        toggle->SetIsActive(true);
        slider->SetIsActive(true);
        textField->SetIsActive(true);
    }

}

void Engine::UI::Menu::Clear()
{

    if (toggle != nullptr || slider != nullptr || textField != nullptr)
    {
        toggle->SetIsActive(false);
        slider->SetIsActive(false);
        textField->SetIsActive(false);
    }
}

void Engine::UI::Menu::SerielizeData(PrimaryType::String _fieldName, PrimaryType::String _value)
{
   const std::string _path = std::filesystem::current_path().string();

   std::ofstream _outFile = std::ofstream(_path + "\\b.asset");

   std::ifstream _inFile = std::ifstream(_path + "\\a.asset");

   std::string _line = "";
   while(std::getline(_inFile, _line))
   {
       if (_line.find(std::string("\"") + _fieldName.ToCstr() + "\"") != std::string::npos)
       {
           _outFile << "\t" + std::string("\"") + _fieldName.ToCstr() + "\" :" + std::string("\"") + _value.ToCstr() + "\"" + "\n";
       }
       else
        _outFile << _line + "\n";
   }
   _inFile.close();
   _outFile.close();

   std::ofstream _out = std::ofstream(_path + "\\a.asset");

   std::ifstream _in = std::ifstream(_path + "\\b.asset");
   _line = "";
   while (std::getline(_in, _line))
   {
       if (_line.find(std::string("\"") + _fieldName.ToCstr() + "\"") != std::string::npos)
       {
           _out << "\t" + std::string("\"") + _fieldName.ToCstr() + "\" :" + std::string("\"") + _value.ToCstr() + "\"" + "," + "\n";
       }
       else
           _out << _line + "\n";
   }

   _in.close();
   _out.close();

}

#pragma endregion
#pragma region override


void Engine::UI::Menu::Draw(sf::RenderWindow* _window)
{

    if (toggle->Status() == true)
        SerielizeData("ball", "true");
    if (toggle->Status() == false)
        SerielizeData("ball", "false");

    std::cout << z.Ball() << std::endl;


    std::ifstream _in(_path + "\\b.asset");
    z.DeSerialize(_in);

   
    assetLabel->SetLabel(z.Strong());
    rec.setRotation(z.Pint());
   _window->draw(*buttonBar);
   _window->draw(*sideBar);
   _window->draw(rec);


    int _value = slider->GetValue();
    SerielizeData("pint", std::to_string(_value).c_str());


    std::string _string = textField->GetText();
    SerielizeData("strong", _string.c_str());
}



#pragma endregion