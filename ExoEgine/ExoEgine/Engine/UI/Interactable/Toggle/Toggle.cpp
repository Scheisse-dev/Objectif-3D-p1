#include "Toggle.h"
#include "../../../Window/Engine/EngineWindow.h"


Toggle::Toggle()
{
    sf::RectangleShape* box = new sf::RectangleShape(sf::Vector2f(200, 200));

}

Toggle::~Toggle()
{

}

bool Toggle::Enable()
{
    return isEnable; 
}
