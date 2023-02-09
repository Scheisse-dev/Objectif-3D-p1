#include "PlayerComponent.h"
#include "../../Engine/Time/Time.h"
#include "../../Engine/GameObject/GameObject.h"

Test::PlayerComponent::PlayerComponent() = default;

Test::PlayerComponent::PlayerComponent(const PlayerComponent& _copy) : super(_copy) {};

void Test::PlayerComponent::Update()
{
	Engine::PrimaryType::Vector2& _position = gameobject->transform->position;
	gameobject->transform->position = Engine::PrimaryType::Vector2::MoveTowards(_position, Engine::PrimaryType::Vector2(100, 0), Engine::Time::deltaTime * 10.0f);
}
