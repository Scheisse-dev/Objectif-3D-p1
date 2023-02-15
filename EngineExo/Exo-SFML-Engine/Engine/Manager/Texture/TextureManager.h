#pragma once
#include <SFML/Graphics.hpp>
#include "../../Utils/Singleton/Singleton.h"

namespace Engine::Manager
{
    class TextureManager : public Utils::Singleton<TextureManager>
    {
#pragma region f/p
    private:
        std::map < std::string, sf::Texture*> textures = std::map < std::string, sf::Texture*>();
#pragma endregion
#pragma region constructor
    public:
        TextureManager();
#pragma endregion
#pragma region methods
    public:
        void Init();
        void LoadTexture(const char* _path);
        sf::Texture* GetTexture(const std::string& _fontName);
#pragma endregion
#pragma region override
    public:
        void OnDestroy() override;
#pragma endregion
    };

}
