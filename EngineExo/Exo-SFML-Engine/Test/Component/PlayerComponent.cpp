#include "PlayerComponent.h"
#include "../../Engine/GameObject/GameObject.h"
#include "../../Engine/Time/Time.h"

Test::PlayerComponent::PlayerComponent(const PlayerComponent&) = default;

void Test::PlayerComponent::Update()
{
    Engine::PrimaryType::Vector2& _posi = gameObject->transform->position;
    _posi = gameObject->transform->position.MoveTowards(gameObject->transform->position, Engine::PrimaryType::Vector2(100, 100), Engine::Time::deltaTime);
}
