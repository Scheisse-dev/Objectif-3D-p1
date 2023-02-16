#pragma once
#include "../Element/UIElement.h"

#pragma region comment
//deserielize a.asset -> get index
// get name + index name
// 
// 
// Macro createButton check
//
#pragma endregion 

#define CREATE_BUTTON(Name, Index)\
{\
    Engine::UI::Button* Name = new Engine::UI::Button(#Name, 100,50);\
    Name->SetPosition(sf::Vector2f(Index, 900));\
    Name->AddListener(this, &Menu::DisplayMenu);\
}





//datas (ifstream)
// foreach object -> index + 1 
// getName ->pushBack(list of name)
// return index;
//



//TODO, adjust button pos width + 50

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
        Label* assetLabel = nullptr;
        Label* menuLabel = nullptr;
        sf::RectangleShape* buttonBar = nullptr;
        sf::RectangleShape* sideBar = nullptr;
        Slider* slider = nullptr;
        Toggle* toggle = nullptr; 
        TextField* textField = nullptr;
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
        void DeserielizeData();
        void Clear();
#pragma endregion methods
#pragma region override
        void Draw(sf::RenderWindow* _window) override;

#pragma endregion

    };

}
