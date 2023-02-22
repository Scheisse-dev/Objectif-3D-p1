#include "AssetWindow.h"
#include "../../Window/Engine/EngineWindow.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../AssetDataBase/AssetDataBase.h"
#include "../../UI/AssetButton/AssetButton.h"
#include "../../Selection/Selection.h"

#pragma region const
Engine::Editor::AssetWindow::AssetWindow() : super ("Assets")
{
    shape = sf::RectangleShape(PrimaryType::Vector2(Window::EngineWindow::Instance()->Width(), 150));
    shape.setFillColor(sf::Color(50, 50, 50, 255));
    SetPosition(PrimaryType::Vector2(0, Window::EngineWindow::Instance()->Height() - 150));
}

Engine::Editor::AssetWindow::AssetWindow(const AssetWindow& _copy) = default;
#pragma endregion
#pragma region meth
void Engine::Editor::AssetWindow::RefreshAssetGUI()
{
    std::vector<Engine::Object*> _assets = Engine::AssetDataBase::LoadAllAssets();
    Engine::PrimaryType::Vector2 _position = Engine::PrimaryType::Vector2(50, Engine::Window::EngineWindow::Instance()->Height() - 140);
    for (Engine::Object* _asset : _assets)
    {
        UI::AssetButton* _button = new UI::AssetButton("", 100, 50, _asset, nullptr); //TODO Action
        _button->AddListener(Selection::Instance(), &Selection::SetSelection);
        _button->SetPosition(_position);
        _position.x += 100;
    }
}
#pragma endregion
#pragma region override
void Engine::Editor::AssetWindow::Open()
{
    RefreshAssetGUI();
    super::Open();
}
#pragma endregion