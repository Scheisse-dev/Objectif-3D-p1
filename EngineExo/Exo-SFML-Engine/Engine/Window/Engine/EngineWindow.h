#pragma once
#include "../Window.h"
#include "../../UI/Element/UIElement.h"
#include "../../UI/Menu/Menu.h"


namespace Engine::Editor
{
    class EditorWindow;
    class InspectorWindow;
}

namespace Engine::UI
{
    class UIELement;
    class Button;
    class Slider;
    class Toggle;
}

#define CREATE_BUTTON(Name, Index, Event)\
{\
    Engine::UI::Button* Name = new Engine::UI::Button(#Name, 100,50);\
    Name->SetPosition(sf::Vector2f(Index, 900));\
    Name->AddListener(this, Event);\
}


namespace Engine::Window
{
    class EngineWindow : public Window<EngineWindow>
    {
        DECLARE_CLASS_INFO(EngineWindow, Window<EngineWindow>)
#pragma region f/p
    private:
        std::vector<Editor::EditorWindow*> editorWindows = std::vector<Editor::EditorWindow*>();
        sf::Clock clock = sf::Clock();
#pragma endregion f/p
#pragma region const
    public:
        EngineWindow();
#pragma endregion const
#pragma region meth
        void RegisterEditorWindow(Editor::EditorWindow* _window);
        void UnRegisterEditorWindow(Editor::EditorWindow* _window);
#pragma endregion
#pragma region override
    public:
        void Open() override;
        void OnUpdate() override;
        void OnClear() const override;
        void OnReceiveEvent(const sf::Event& _event) override;
#pragma endregion override
    };
}
