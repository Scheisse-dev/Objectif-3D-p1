#pragma once
#include <SFML/Graphics.hpp>

#include "../Base/BaseManager.h"

namespace Core
{
	namespace Manager
	{
		class FontManager : public BaseManager<FontManager, sf::Font>
		{
#pragma region f/p
		public:
			void Init() override;
#pragma endregion f/p
		};
	}
}