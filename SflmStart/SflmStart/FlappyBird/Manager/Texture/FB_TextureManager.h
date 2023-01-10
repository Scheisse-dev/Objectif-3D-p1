#pragma once
#include "../../../Singleton/Singleton.h"
#include <SFML/Graphics.hpp>
#include <map>

class FB_TextureManager : public Singleton<FB_TextureManager>
{
#pragma region f/p
private:
	std::map<const char*, sf::Texture*> textures = std::map<const char*, sf::Texture*>();

#pragma endregion f/p
#pragma region constructor
public:
	FB_TextureManager() = default;
#pragma endregion constructor
#pragma region methods
public:
	sf::Texture* Get(const char* _path);
#pragma endregion methods
#pragma region override
protected:
	void OnDestroy() override;
#pragma endregion override
};

