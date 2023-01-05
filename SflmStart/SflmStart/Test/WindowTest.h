#pragma once
#include "../Window/Window.h"
class WindowTest : public Window
{
#pragma region f/p
private:
	sf::RectangleShape* shape = nullptr;
	sf::Text* text = nullptr; 
	sf::Font* font = nullptr;
#pragma endregion f/p

#pragma region constructor
public:
	WindowTest();
	~WindowTest() override; 
#pragma endregion construct
#pragma region methods
protected:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
#pragma endregion methods
};

