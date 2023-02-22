#pragma once
#include "../Window/EditorWindow.h"



namespace Engine::Editor
{
    class InspectorWindow : public EditorWindow
    {
        DECLARE_CLASS_INFO(InspectorWindow, EditorWindow)

#pragma region const
    public:
        InspectorWindow();
        ~InspectorWindow();
#pragma endregion
        void OnSelectionChange(Object* _o);
    };

}
