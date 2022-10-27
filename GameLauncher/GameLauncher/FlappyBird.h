#pragma once
#include "IGame.h"
#include "FlappyScore.h"

#define SLEEP_TIME_MAP 20
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define SLEEP_DEFAULT 100
#define GAP_SIZE 7
#define PRESS_ANY_KEY "Press any key..."

class FlappyMap;
class FlappyPlayer; 
class FlappyPipe;

class FlappyBird : public IGame
{
private: 
	FlappyMap* map = nullptr; 
	FlappyPlayer* player = nullptr; 
	FlappyPipe* pipeOne = nullptr;
	FlappyPipe* pipeTwo = nullptr;
	FlappyScore score = FlappyScore(); 
	bool isQuitting = false;
	int sleepTime = 0;
public: 

	FlappyBird();
	~FlappyBird() override;
public:
	bool IsOutOfScreen() const;
	void Draw(); 
	void Clear(); 
	void DisplayConstrols(); 
	void UpdatePipe(); 
	void Init(); 
	void UpdateScore(); 
#pragma region override
public: 
	virtual void OnStart() override;
	virtual void OnUpdate() override;
	virtual void OnEnd() override;
	virtual void DisplayMenu() override; 
	std::string GameName() const override;
	std::string GameDescription() const override;
#pragma endregion override
};

