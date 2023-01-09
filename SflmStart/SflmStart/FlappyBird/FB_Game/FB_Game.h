#pragma once
#include "../../Window/Window.h"
#include "../../UI/Image/FB_Image.h"

class FB_Game : public Window
{
#pragma region f/p
private:
	bool isStarted = false;
	FB_Image* background = nullptr;
	class FB_Bird* bird = nullptr; 
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_Game();
	virtual ~FB_Game() override;
#pragma endregion constructor/destructor
#pragma region override
private:
	void Start();
	void InitBackGround();

public:
	void OnDraw() override;
	void OnUpdate() override;
	void InitMenu() override;
#pragma endregion override
};

