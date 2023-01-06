#pragma once
#include <SFML/Graphics.hpp>
#include "../Window/Window.h"
#include "Entity/Bird/Bird.h"
#include "Entity/Pipe/Pipe.h"
#include "FlappyMenu/FlappyMenu.h"
#include <SFML/Audio.hpp>


class FlappyBird: public Window
{
#pragma region f/p
private:
	Bird bird = Bird();
	Pipe pipe = Pipe();
	FlappyMenu flappyMenu = FlappyMenu(); 
	sf::Font font;
	sf::Color color = sf::Color(0, 0, 0);
	sf::Text score; 
	sf::Music music = sf::Music();
	sf::Sound sound = sf::Sound();
	sf::SoundBuffer buffer;
	sf::RectangleShape leftlimit = sf::RectangleShape(sf::Vector2f(10, 600));
	sf::RectangleShape upperlimit = sf::RectangleShape(sf::Vector2f(100, 10));
	sf::RectangleShape lowerlimit = sf::RectangleShape(sf::Vector2f(100, 10));
	sf::Mouse mouse = sf::Mouse();
	sf::Clock clock;


	sf::Texture sprite1;
	sf::Texture sprite2;
	sf::Texture sprite3;

	int index = 0;
	int count = 0;

	int space = 0;
	int space2 = 0;
	//TODO on start 

	bool onStart = false;
	bool isDeath = false; 
	
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FlappyBird();
	~FlappyBird() = default; 
#pragma endregion constructor/destructor
#pragma region methods
public:
	void SetBackground();
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
	void EntityMove();
	void EntityCollision();
	void UpdateEntity();
#pragma endregion methods



};

