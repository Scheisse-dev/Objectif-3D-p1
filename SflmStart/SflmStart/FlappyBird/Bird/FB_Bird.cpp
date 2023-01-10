#include "FB_Bird.h"
#include "../../Math/Mathf.h"
#include "../../Time/Time.h"
#include "../../Input/Input.h"
#include <iostream>

#pragma region constructor/destructor
FB_Bird::FB_Bird() : GameObject()
{
	sprite = new sf::Sprite(); 
	texture = new sf::Texture();
	if (texture->loadFromFile("D:/GitHub/Objectif-3D-p1/SflmStart/FlappyBird/marie.png"))
	{
		sprite->setTexture(*texture); 
	}
	sprite->setOrigin(sf::Vector2f(0, 0));
	sprite->setScale(sf::Vector2f(BIRD_SCALE, BIRD_SCALE));
	drawable = sprite; 
}
FB_Bird::~FB_Bird()
{
	delete sprite;
	sprite = nullptr;
	delete texture;
	texture = nullptr; 
}
#pragma endregion constructor/destructor
#pragma region override
void FB_Bird::Die()
{
	if (isDead) return;
	isDead = true;
	std::cout << "bird collide" << std::endl;
	OnDie.Invoke();
}
void FB_Bird::SetWindowSize(const sf::Vector2f& _vector)
{
	windowSize = _vector;
}
void FB_Bird::OnUpdate()
{
	if (isDead) return;
	sprite->setPosition(Mathf::Lerp(sprite->getPosition(), sprite->getPosition() + sf::Vector2f(0, GRAVITY), BIRD_SPEED_GRAVITY * Time::deltaTime));
	const float _elapsed = lastJumpTimer.getElapsedTime().asSeconds();
	if (sprite->getPosition().y <= 0 || sprite->getPosition().y >= windowSize.y - sprite->getGlobalBounds().height)
	{
		Die();
		return;
	}
	if (Input::isKeyDown(sf::Keyboard::Space))
	{
		sprite->setRotation(-15.0f);
		sprite->setPosition(sprite->getPosition() - sf::Vector2f(0, BIRD_JUMP_FORCE));
		lastJumpTimer.restart();
	}
	else if (_elapsed > 0.2f && _elapsed < 0.5f)
		sprite->setRotation(0);
	else if (_elapsed > 0.6f)
		sprite->setRotation(15.0f);
}

void FB_Bird::OnCollisionEnter(GameObject* _other)
{
	Die();
}

sf::FloatRect FB_Bird::GetGlobalBounds() const
{
	return sprite->getGlobalBounds();
}

sf::Vector2f FB_Bird::Position() const
{
	return sprite->getPosition(); 
}

#pragma endregion override