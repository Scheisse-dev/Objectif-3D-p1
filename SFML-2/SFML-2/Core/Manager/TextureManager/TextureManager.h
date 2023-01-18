#pragma once
#include <SFML/Graphics.hpp>

#include "../Base/BaseManager.h"

namespace Core
{
	namespace Manager
	{
		class TextureManager : public BaseManager<TextureManager, sf::Texture>
		{
		public:
			void Init() override;
		};
	}
}