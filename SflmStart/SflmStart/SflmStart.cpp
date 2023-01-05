#include <SFML/Graphics.hpp>
#include <Windows.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::Texture texture;
    texture.loadFromFile("D:\\harold.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.5f, 0.5f));
    sprite.setPosition(sf::Vector2f(500.f, 500.f));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sprite.rotate(5.f);
        window.clear();
        window.draw(sprite);
        window.display();
        Sleep(10);
    }
 }
