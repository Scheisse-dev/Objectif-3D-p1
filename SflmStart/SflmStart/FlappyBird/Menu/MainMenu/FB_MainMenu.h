#pragma once
#include "../../../Window/Menu/BaseMenu.h"
#include "../../../Utils/GIF/GIF.h"

class FB_Button;
class FB_Image;

class FB_MainMenu : public BaseMenu
{
#pragma region f/p
private:
	FB_Image* logoTitle = nullptr; 
	FB_Button* playButton = nullptr; 
	FB_Button* scoreboardButton = nullptr; 
	//sf::Sprite* gifSprite = nullptr;
	//GIF gif = GIF("D:/GitHub/Objectif-3D-p1/SflmStart/Sprites/gandalf-sax-guy.gif");
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FB_MainMenu(Window* _owner);


	virtual ~FB_MainMenu() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void InitLogoTitle();
	void InitButton();
	
public:
	FB_Button* PlayButton() const;
	FB_Button* ScoreBoardButton() const;
#pragma endregion methods 
#pragma region override
public:
	virtual void Draw() override;
#pragma endregion override
};

