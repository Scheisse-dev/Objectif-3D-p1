#pragma once
#include "../GameObject/GameObject.h"
#include "../../Event/Delegate/Delegate.h"

#define PIPE_SPEED 250.0f
#define GAP 200.0f

class FB_Pipe : public GameObject
{
#pragma region f/p
private:
	sf::Sprite* sprite = nullptr; 
	sf::Texture* texture = nullptr; 
	bool passedBird = false;
public:
	Delegate<void> OnBirdPosition = nullptr; 
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_Pipe(); 
	~FB_Pipe();
#pragma endregion constructor/destructor
#pragma region methods
public:
	void Rotate();
	void Move();
	void SetPosition(sf::Vector2f _position);
#pragma endregion methods
#pragma region override
	virtual void OnUpdate() override;
	virtual sf::FloatRect GetGlobalBounds() const override;
	virtual sf::Vector2f Position() const override;
#pragma endregion override
};

