#pragma once
#include "../../../Window/Menu/BaseMenu.h"

class FB_GameOverMenu : public BaseMenu
{
#pragma region f/p
	class FB_Image* gameOverImage = nullptr; 
	FB_Image* titleImage = nullptr;
	class FB_Button* restartButton = nullptr; 
	class FB_Label* scoreText = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_GameOverMenu(Window* _owner);

	virtual ~FB_GameOverMenu() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void InitRestartButton(const float& _centerWidth, const float& _centerHeight);
	void InitTitleImage(const float& _centerWidth);
	void InitGameOverImage(const float& _centerWidth, const float& _centerHeight);
	void InitScoreText(const float _centerWidth, const float _centerHeight);
public:
	void SetScore(const int _score);
	FB_Button* RestartButton() const;
#pragma endregion methods
#pragma region override
public: 
	virtual void Draw() override;
#pragma endregion override
};

