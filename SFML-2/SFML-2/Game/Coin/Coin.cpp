#include "Coin.h"
#include "../../Core/Environment/Environment.h"
#include "../../Core/Utils/Path/Path.h"
#include "../../Core/Gif/Gif.h"
#include "../Entity/Player/Player.h"

#pragma region constructor/destructor
Game::Coin::Coin()
{
	sprite = new sf::Sprite();
	gif = new Core::Gif(Core::Utils::Path::Combine({ Core::Environment::AssetPath, "Coin", "coin.gif" }).c_str());
	SetOrigin(sf::Vector2f(GlobalBounds().width / 2, GlobalBounds().height / 2));
	SetScale(sf::Vector2f(0.3f, 0.3f));
}
Game::Coin::~Coin()
{
	delete gif;
	gif = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methods
void Game::Coin::OnUpdate()
{
	gif->Update(*sprite);
}
void Game::Coin::OnCollisionEnter(GameObject* _object)
{
	Player* _player = dynamic_cast<Player*>(_object);
	if (_player == nullptr) return;
	//TODO add coin to player inventory
	Destroy(this);
}
#pragma endregion methods