#pragma once
#define STB_IMAGE_IMPLEMENTATION
#define STB_ONLY_GIF

#include "stb_image.h"
#include <SFML/Graphics.hpp>
#include <vector>
class GIF
{
private:
	sf::Vector2i size;
	sf::Clock clock; 
	sf::Time startTime;
	sf::Time totalDelay;
	std::vector<std::tuple<int, sf::Texture>> frames;
	std::vector<std::tuple<int, sf::Texture>>::iterator frameIter; 

public:
	GIF(const char* _path);

public:
	void Update(sf::Sprite& _sprite);

	sf::Vector2i GetSize() const;
};

