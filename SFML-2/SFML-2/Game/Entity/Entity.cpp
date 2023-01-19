#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "../../Core/Manager/TextureManager/TextureManager.h"
#include "../../Core/Utils/Math/Mathf.h"
#include "../../Core/Time/Time.h"
#include "../Physics/Physics.h"

#pragma region constructor/destructor
Game::Entity::Entity::Entity(const char* _texturePath, const EntityStats& _stats)
{
	stats = _stats;
	sprite = new sf::Sprite(); 
	sf::Texture* _texture = Core::Manager::TextureManager::Instance()->Load(_texturePath);
	checkLow((_texture != nullptr), std::format("[Entity] => error on loaded texture {}", _texturePath));
	sprite->setTexture(*_texture);
}
Game::Entity::Entity::Entity(const char* _texturePath) : self(_texturePath, EntityStats::Default) {}
#pragma endregion constructor/destructor
#pragma region methods
void Game::Entity::Entity::AddLife(float _life)
{
	checkLow(_life > 0, "life must be greater than 0")
		stats.life = Core::Utils::Mathf::Clamp(stats.life + _life, 0.0f, stats.maxLife);
}
void Game::Entity::Entity::SetLife(float _value)
{
	checkLow(_value > 0, "life must be greater than 0")
	stats.life = Core::Utils::Mathf::Clamp(_value, 0.0f, stats.maxLife);
}
void Game::Entity::Entity::SetMaxLife(float _value)
{
	checkLow(_value > 0, "life must be greater than 0")
		stats.maxLife = _value;
}
void Game::Entity::Entity::AddMana(float _mana)
{
	checkLow(_mana > 0, "mana must be greater than 0")
		stats.life = Core::Utils::Mathf::Clamp(stats.mana + _mana, 0.0f, stats.maxMana);
}
void Game::Entity::Entity::SetMana(float _value)
{
	checkLow(_value > 0, "life must be greater than 0")
		stats.mana = Core::Utils::Mathf::Clamp(_value, 0.0f, stats.maxMana);
}
void Game::Entity::Entity::SetMaxMana(float _value)
{
	checkLow(_value > 0, "mana must be greater than 0")
		stats.maxMana = _value;
}
void Game::Entity::Entity::TakeDamage(float _value)
{
	checkLow(_value > 0, "damage must be greater than 0")
		stats.life = Core::Utils::Mathf::Clamp(stats.life - _value, 0.0f, stats.maxLife);
	if (stats.life == 0.0f)
		Die();
}
void Game::Entity::Entity::Die()
{
	if (OnDie.IsValid()) OnDie.Invoke();
}
bool Game::Entity::Entity::IsAlive()
{
	return stats.life > 0.0f;
}
bool Game::Entity::Entity::IsGrounded() const
{
	return isGrounded;
}
void Game::Entity::Entity::OnUpdate()
{
	super::OnUpdate();
	if (!isGrounded)
	SetPosition(Position() + sf::Vector2f(0, 1) * GRAVITY * Core::Time::deltaTime);
}
#pragma endregion methods
