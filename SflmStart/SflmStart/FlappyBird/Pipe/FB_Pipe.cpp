#include "FB_Pipe.h"
#include "../../Time/Time.h"
#include "../Manager/Texture/FB_TextureManager.h"
#include "../Manager/FB_GameObjectManager/FB_GameObjectManager.h"
#pragma region constructor/destructor
FB_Pipe::FB_Pipe()
{
	sprite = new sf::Sprite();
	texture = FB_TextureManager::Instance()->Get("D:/GitHub/Objectif-3D-p1/SflmStart/FlappyBird/cheminée.png");
	sprite->setTexture(*texture);
	sprite->scale(0.3f, 0.7f);
	drawable = sprite; 

}

FB_Pipe::~FB_Pipe()
{
	delete sprite; 
	sprite = nullptr; 

}
#pragma endregion constructor/destructor
#pragma region methods
void FB_Pipe::Rotate()
{
	sprite->rotate(180);
}

void FB_Pipe::Move()
{
	SetPosition(sprite->getPosition() - sf::Vector2f(1, 0) * PIPE_SPEED * Time::deltaTime);
	if (!passedBird && sprite->getPosition().x <= -0.5f && OnBirdPosition.IsValid())
	{
		OnBirdPosition.Invoke();
		passedBird = true; 
	}
	if (sprite->getPosition().x < (0 - GetGlobalBounds().width))
		FB_GameObjectManager::Instance()->Destroy(this);
	
}
void FB_Pipe::SetPosition(sf::Vector2f _position)
{
	sprite->setPosition(_position);
}
#pragma endregion methods
#pragma region override
void FB_Pipe::OnUpdate()
{
	Move();
}

sf::FloatRect FB_Pipe::GetGlobalBounds() const
{
	return sprite->getGlobalBounds();
}
sf::Vector2f FB_Pipe::Position() const
{
	return sprite->getPosition();
}

#pragma endregion override