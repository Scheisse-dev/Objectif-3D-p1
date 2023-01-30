#pragma once
#include "../Window.h"

namespace Engine::Window
{
	class EngineWindow : public Window<EngineWindow>
	{
#pragma region f/p
	private:
		sf::Clock clock = sf::Clock();
#pragma endregion f/p
#pragma region override
	public:
		void Open() override;
		void OnUpdate() override;
		void OnClear() override;
		void OnReceiveEvent(const sf::Event& _event) override;
#pragma endregion override
	};

}