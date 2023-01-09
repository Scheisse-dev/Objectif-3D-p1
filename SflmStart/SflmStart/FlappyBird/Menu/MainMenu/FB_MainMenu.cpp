#include "FB_MainMenu.h"
#include "../../../UI/Image/FB_Image.h"
#include "../../../UI/Button/FB_Button.h"

#pragma region constructor/destructor
FB_MainMenu::FB_MainMenu(Window* _owner) : BaseMenu(_owner)
{

	InitLogoTitle();
	playButton = new FB_Button(owner, "D:\\GitHub\\Objectif-3D-p1\\SflmStart\\FlappyBird\\flappybird_play_button.png");
	playButton->SetScale(sf::Vector2f(0.3f, 0.3f));
	const sf::Vector2f _position = sf::Vector2f((_owner->Width() / 2) - (playButton->GetGlobalBounds().width + 100), owner->Height() / 2);
	playButton->SetPosition(_position);
	elements.push_back(playButton);
}



FB_MainMenu::~FB_MainMenu()
{
	//delete logoTitle;
	//logoTitle = nullptr;
	//
	//
	//delete playButton;
	//playButton = nullptr;
	//delete scoreboardButton;
	//scoreboardButton = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methods 
void FB_MainMenu::InitLogoTitle()
{
	logoTitle = new FB_Image(owner, "D:/GitHub/Objectif-3D-p1/SflmStart/FlappyBird/Flappy_Logo.png");
	logoTitle->SetPosition(sf::Vector2f((owner->Width() / 2) - 150, 50));
	logoTitle->SetScale(sf::Vector2f(0.1f, 0.1f));
	logoTitle->SetOrigin(sf::Vector2f(logoTitle->getGlobalBounds().width / 2, logoTitle->getGlobalBounds().height / 2));
	elements.push_back(logoTitle);
}


FB_Button* FB_MainMenu::PlayButton() const
{
	return playButton;
}

FB_Button* FB_MainMenu::ScoreBoardButton() const
{
	return scoreboardButton;
}

#pragma endregion methods 
#pragma region override
void FB_MainMenu::Draw()
{
	BaseMenu::Draw();
}
#pragma endregion override