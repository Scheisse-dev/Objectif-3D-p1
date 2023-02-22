#pragma once
#include "../Window/EditorWindow.h"

namespace Engine::Editor
{
    class AssetWindow : public EditorWindow
    {
        DECLARE_CLASS_INFO(AssetWindow, EditorWindow)
#pragma region const
    public:
        AssetWindow();
#pragma endregion
#pragma region meth
        void RefreshAssetGUI();
#pragma endregion
#pragma region override
    public:
        void Open() override;
#pragma endregion
    };

}
