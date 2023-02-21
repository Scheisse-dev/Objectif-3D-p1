#pragma once
#include "../Element/UIElement.h"
#include "../../Utils/Singleton/Singleton.h"
#include "../../../Test/Z.h"
#include <string>
#include <filesystem>

#pragma region comment
//Serielize -> get line -> Name -> change value -> value return by event 
// error -> value can be change by something else
//
#pragma endregion 



#define DESERIELIZE_DATA(ClassName, DataName)\
{\
\
}
//-> deserielize -> get line dataname -> get value (type missing...)
// -> get type dont work -> new gate type ? or template macro ? 
//AHHHHHHHHHHHHHHHHHHHHHHHH


namespace Engine::UI
{
    class Label;
    class Button;
    class Slider;
    class Toggle;
    class TextField;


    class Menu : public UIElement
    {
        DECLARE_CLASS_INFO(Menu, UIElement)
#pragma region f.p
    private:
        sf::RectangleShape rec = sf::RectangleShape(sf::Vector2f(200, 100));
        UI::Toggle* toggle = nullptr;
        UI::Slider* slider = nullptr;
        UI::TextField* textField = nullptr;
        UI::Button* button = nullptr;
        UI::Button* loutre = nullptr;
        Label* assetLabel = nullptr;
        Label* menuLabel = nullptr;
        sf::RectangleShape* buttonBar = nullptr;
        sf::RectangleShape* sideBar = nullptr;
        Test::Z z = Test::Z();
        const std::string _path = std::filesystem::current_path().string();
#pragma endregion
#pragma region const
    public:
        Menu();
        ~Menu();
#pragma endregion
#pragma region methods
    public:
        void SetUiBar();
        void SetMenuLabel();
        void DisplayMenu();
        void SerielizeData(PrimaryType::String _fieldName, PrimaryType::String Value);
        void Clear();
#pragma endregion methods
#pragma region override
        void Draw(sf::RenderWindow* _window) override;

#pragma endregion

    };

}
