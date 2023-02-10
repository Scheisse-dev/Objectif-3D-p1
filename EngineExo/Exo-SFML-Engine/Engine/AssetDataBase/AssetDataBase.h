#pragma once
#include "../Object/Object.h"

namespace Engine
{
    namespace PrimaryType
    {
        class String;
    }

    class AssetDataBase : public Object
    {
        DECLARE_CLASS_INFO(AssetDataBase, Object)
#pragma region methods
    public:
        static void CreateAsset(Object* _asset, PrimaryType::String _path);
#pragma endregion
    };
}

