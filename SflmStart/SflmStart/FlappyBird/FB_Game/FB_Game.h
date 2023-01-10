#pragma once
#include "../../Window/Window.h"
#include "../../UI/Image/FB_Image.h"

#define TIME_FOR_SPAWN 1.5f


class FB_Game : public Window
{
#pragma region f/p
private:
	bool isStarted = false;
	FB_Image* background = nullptr;
	class FB_Bird* bird = nullptr; 
	sf::Clock spawnerClock = sf::Clock();
	class FB_Score* score = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_Game();
	virtual ~FB_Game() override;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void Start();
	void OnBirdDie();
	void OnReceiveEvent(const sf::Event& _event);
#pragma endregion methods
#pragma region override
private:
	void InitBackGround();
	void InitMenu();
	void SpawnPipe();
public:
	void OnDraw() override;
	void OnUpdate() override;
#pragma endregion override
};

