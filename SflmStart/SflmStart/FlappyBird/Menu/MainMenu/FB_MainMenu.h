#pragma once
#include "../../../Window/Menu/BaseMenu.h"

class FB_Button;
class FB_Image;

class FB_MainMenu : public BaseMenu
{
#pragma region f/p
private:
	FB_Image* logoTitle = nullptr; 
	
	FB_Button* playButton = nullptr; 
	FB_Button* scoreboardButton = nullptr; 
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_MainMenu(Window* _owner);

	virtual ~FB_MainMenu() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void InitLogoTitle();
	
public:
	FB_Button* PlayButton() const;
	FB_Button* ScoreBoardButton() const;
#pragma endregion methods 
#pragma region override
public:
	virtual void Draw() override;
#pragma endregion override
};

