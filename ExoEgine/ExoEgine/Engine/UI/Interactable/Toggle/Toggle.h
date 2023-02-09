#pragma once
#include <SFML/Graphics.hpp>


//create rect -> set collission in
// bool is enable = false;
// if(onclick) enable = true
// if(enable)create cross
// if(!enable) destroy cross
//

class Toggle
{
#pragma region f/p
private:
	sf::RectangleShape* box = nullptr;
	sf::Color color = sf::Color::White;
	sf::RectangleShape line = sf::RectangleShape(sf::Vector2f(150, 1));
	bool isEnable = false; 
#pragma endregion f/p
#pragma region constructor
public:
	Toggle();
	~Toggle();
#pragma endregion constructor
#pragma region methods
public:
	bool Enable();
	
#pragma endregion methods
};

