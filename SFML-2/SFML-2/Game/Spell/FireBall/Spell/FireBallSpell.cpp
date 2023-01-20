#include "FireBallSpell.h"


#include "../FireBall.h"
#include "../../../Entity/Entity.h"

Game::Spell::FireBallSpell::FireBallSpell(Entity::Entity* _entity) : super("FireBall")
{
	owner = _entity;
}

void Game::Spell::FireBallSpell::OnUse()
{
	FireBall* _fireball = new FireBall(owner);
	_fireball->SetPosition(owner->Position() + sf::Vector2f(_fireball->GlobalBounds().width, 0));
}
