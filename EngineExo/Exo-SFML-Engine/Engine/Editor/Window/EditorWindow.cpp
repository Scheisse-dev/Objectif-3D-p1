#include "EditorWindow.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../Manager/FontManager.h"
#include "../../Window/Engine/EngineWindow.h"

#pragma region const
Engine::Editor::EditorWindow::EditorWindow(const char* _name)
{
    titleShape = sf::RectangleShape(PrimaryType::Vector2(60, 20));
    titleShape.setFillColor(sf::Color(50, 50, 50, 255));
    titleText = sf::Text(_name, *Manager::FontManager::Instance()->GetFont("Arial"));
    titleText.setCharacterSize(12);

    const int _height = Engine::Window::EngineWindow::Instance()->Height();
    shape = sf::RectangleShape(PrimaryType::Vector2(100, _height));

}
Engine::Editor::EditorWindow::EditorWindow(const EditorWindow& _copy)
{
    titleText = _copy.titleText;
    titleShape = _copy.titleShape;
    shape = _copy.shape;
}
#pragma endregion
#pragma region meth
void Engine::Editor::EditorWindow::Draw(sf::RenderWindow* _window)
{
    _window->draw(shape);
    _window->draw(titleShape);
    _window->draw(titleText);
    _window->draw(sideShape);
}

void Engine::Editor::EditorWindow::SetPosition(const PrimaryType::Vector2& _position) 
{ 
    shape.setPosition(_position);
    titleShape.setPosition(PrimaryType::Vector2(_position.x, _position.y - titleShape.getGlobalBounds().height));
    const sf::FloatRect _shapeBounds = titleShape.getGlobalBounds();
    const sf::FloatRect _textBounds = titleText.getGlobalBounds();
    const float _x = _shapeBounds.left + (_shapeBounds.width / 2) - (_textBounds.width / 2);
    const float _y = _shapeBounds.top + (_shapeBounds.height / 2) - _textBounds.height;
    titleText.setPosition(_x, _y);
}
void Engine::Editor::EditorWindow::OnGUI() { }

void Engine::Editor::EditorWindow::Open()
{
    Window::EngineWindow::Instance()->RegisterEditorWindow(this);
}
#pragma endregion