#include "InspectorWindow.h"
#include "../../Window/Engine/EngineWindow.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../AssetDataBase/AssetDataBase.h"
#include"../../Selection/Selection.h"


#pragma region const
Engine::Editor::InspectorWindow::InspectorWindow() : super("Inspectors")
{
    const int _width = Window::EngineWindow::Instance()->Width();
    const int _height = Window::EngineWindow::Instance()->Height();
    shape = sf::RectangleShape(PrimaryType::Vector2(300, _height));
    shape.setFillColor(sf::Color(50,50,50,255));
    SetPosition(PrimaryType::Vector2(_width - 300, 25));
}

Engine::Editor::InspectorWindow::InspectorWindow(const InspectorWindow& _copy) = default;

Engine::Editor::InspectorWindow::~InspectorWindow()
{
    Selection::OnSelectionChanged.RemoveDynamic(this, &InspectorWindow::OnSelectionChange);
}
#pragma endregion

void Engine::Editor::InspectorWindow::OnSelectionChange(Object* _o)
{
    //TODO if obejct to edit is not nullptr, serielize this
    //todo else set Object to edit
    //TODO draw all properties of object
}