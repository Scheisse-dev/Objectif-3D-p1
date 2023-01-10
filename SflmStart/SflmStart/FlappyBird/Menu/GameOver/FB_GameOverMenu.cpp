#include "FB_GameOverMenu.h"
#include "../../../Window/Window.h"
#include "../../../UI/Image/FB_Image.h"
#include "../../../UI/Button/FB_Button.h"
#include "../../../UI/Label/FB_Label.h"

#pragma region constructor/destructor
FB_GameOverMenu::FB_GameOverMenu(Window* _owner)
	:BaseMenu(_owner)
{
	const float _centerWidth = _owner->Width() / 2;
	const float _centerHeight = _owner->Height() / 2;

	InitGameOverImage(_centerWidth, _centerHeight);

	InitTitleImage(_centerWidth);

	InitRestartButton(_centerWidth, _centerHeight);

	InitScoreText(_centerWidth, _centerHeight);
	

}
FB_GameOverMenu::~FB_GameOverMenu()
{
	//delete gameOverImage;
	//gameOverImage = nullptr;
	//delete titleImage;
	//titleImage = nullptr;
	//delete restartButton;
	//restartButton = nullptr;
}
#pragma endregion constructor/destructor
#pragma region methods
void FB_GameOverMenu::InitRestartButton(const float& _centerWidth, const float& _centerHeight)
{
	restartButton = new FB_Button(owner, "D:/GitHub/Objectif-3D-p1/SflmStart/FlappyBird/flappybird_play_button.png");
	restartButton->SetScale(sf::Vector2f(0.3f, 0.3f));
	restartButton->SetPosition(sf::Vector2f(_centerWidth - (restartButton->GetGlobalBounds().width + 100), _centerHeight + 50));
	elements.push_back(restartButton);
}

void FB_GameOverMenu::InitTitleImage(const float& _centerWidth)
{
	titleImage = new FB_Image(owner, "D:/GitHub/Objectif-3D-p1/SflmStart/FlappyBird/MarieTitle.png");
	titleImage->SetPosition(sf::Vector2f(_centerWidth - 150, 20));
	titleImage->SetScale(sf::Vector2f(0.19f, 0.19f));
	titleImage->SetOrigin(sf::Vector2f(titleImage->getGlobalBounds().width / 2, titleImage->getGlobalBounds().height / 2));
	elements.push_back(titleImage);
}

void FB_GameOverMenu::InitGameOverImage(const float& _centerWidth, const float& _centerHeight)
{
	gameOverImage = new FB_Image(owner, "D:/GitHub/Objectif-3D-p1/SflmStart/FlappyBird/flappyBirdGameOver.png");
	gameOverImage->SetScale(sf::Vector2f(0.2f, 0.2f));
	sf::Vector2f _position = sf::Vector2f(_centerWidth - (gameOverImage->GetGlobalBounds().width / 2), _centerHeight - (gameOverImage->GetGlobalBounds().height / 2)+30);
	gameOverImage->SetPosition(_position);
	elements.push_back(gameOverImage);
}

void FB_GameOverMenu::InitScoreText(const float _centerWidth, const float _centerHeight)
{
	scoreText = new FB_Label(owner, "0");
	scoreText->SetColor(sf::Color::Black);
	scoreText->SetPosition(sf::Vector2f(_centerWidth - (gameOverImage->getGlobalBounds().width / 2 + -50), gameOverImage->GetGlobalBounds().height * 2 + 100));
	elements.push_back(scoreText);
}




void FB_GameOverMenu::SetScore(const int _score)
{
	scoreText->SetText(("Score:" + std::to_string(_score)).c_str());
}

FB_Button* FB_GameOverMenu::RestartButton() const
{
	return restartButton;
}
#pragma endregion methods
#pragma region override
void FB_GameOverMenu::Draw()
{
	BaseMenu::Draw();
}
#pragma endregion override