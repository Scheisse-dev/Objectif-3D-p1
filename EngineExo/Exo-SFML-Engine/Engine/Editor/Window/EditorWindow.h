#pragma once

#include <SFML/Graphics.hpp>
#include "../../Object/Object.h"


namespace Engine::PrimaryType
{
    class Vector2;
}
namespace Engine::Editor
{
    class EditorWindow : public Object
    {
        DECLARE_CLASS_INFO(EditorWindow, Object);
#pragma region f.p
    private:
        sf::RectangleShape titleShape = sf::RectangleShape();
        sf::Text titleText = sf::Text();
    protected:
        sf::RectangleShape sideShape = sf::RectangleShape();
        sf::RectangleShape shape = sf::RectangleShape();
#pragma endregion
#pragma region const
    public:
        EditorWindow() = delete;
        EditorWindow(const char* _name);
#pragma endregion
#pragma region meth
    public:
        void Draw(sf::RenderWindow* _window);
        virtual void SetPosition(const PrimaryType::Vector2& _position);
        virtual void OnGUI();
        virtual void Open();

#pragma endregion
    };

}
