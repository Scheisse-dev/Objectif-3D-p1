#include "FlappyBird.h"
#include "Utils.h"
#include "FlappyMap.h"
#include "FlappyPlayer.h"
#include "FlappyPipe.h"

FlappyBird::FlappyBird()
{
    map = new FlappyMap(); 
    player = new FlappyPlayer(); 
    pipeOne = new FlappyPipe();
    pipeTwo = new FlappyPipe(); 
}

FlappyBird::~FlappyBird()
{
    delete map;
    map = nullptr;
    delete player;
    player = nullptr; 
    delete pipeOne;
    pipeOne = nullptr;
    delete pipeTwo; 
    pipeTwo = nullptr;
}

bool FlappyBird::IsOutOfScreen() const
{
    const int _position = player->Position();
    return _position > SCREEN_HEIGHT - 2 || _position <= 3;
}

void FlappyBird::Draw()
{
    player->Draw();
    pipeOne-> Draw(); 
    pipeTwo->Draw();
}

void FlappyBird::Clear()
{
    player->Erase();
    pipeOne->Erase();
    pipeTwo->Erase();
}

void FlappyBird::DisplayConstrols()
{
    Utils::SetCursorPosition(WIN_WIDTH + 5, 2); 
    Utils::LogWithEffect(GameName()); 
    Utils::SetCursorPosition(WIN_WIDTH + 6, 4);
    Utils::LogWithEffect("----------");
    Utils::SetCursorPosition(WIN_WIDTH + 6, 6);
    Utils::LogWithEffect("----------");
    Utils::SetCursorPosition(WIN_WIDTH + 7, 12);
    Utils::LogWithEffect("Control "); 
    Utils::SetCursorPosition(WIN_WIDTH + 7, 13);
    Utils::LogWithEffect("-------- ");
    Utils::SetCursorPosition(WIN_WIDTH + 2, 14);
    Utils::LogWithEffect("Spacebar for jump");
}

void FlappyBird::UpdatePipe()
{
    pipeOne->Update();
    pipeTwo->Update();

    const int _pipePosition = pipeOne->Position(); 
    if (_pipePosition >= 40 && _pipePosition < 42)
    {
        pipeTwo->SetCanDraw(true);
        pipeTwo->SetPosition(4);
        pipeTwo->SetGapPosition(2 + rand() % 14); //TODO change rand
    }
}
void FlappyBird::Init()
{
    isQuitting = false; 
    player->SetDead(false); 
    player->SetPosition(6); 
    pipeOne->SetCanDraw(true); 
    pipeTwo->SetCanDraw(false); 
    pipeOne->SetPosition(4);
    pipeTwo->SetPosition(4);
    pipeOne->SetGapPosition(3 + rand() % 14); 
}
void FlappyBird::UpdateScore()
{
    if (pipeOne->Position() > 68)
    {
        score.Update();
        score.Draw();
        pipeTwo->SetCanDraw(false);
        pipeOne->SetPosition(pipeTwo->Position());
        pipeOne->SetGapPosition(pipeTwo->GapPosition());
    }
}
#pragma region override
void FlappyBird::OnStart()
{
    Utils::ClearConsole();
    Utils::SetCursor(false, 0);
    sleepTime = SLEEP_DEFAULT; 
    Init(); 
    map->Draw();
    
}

void FlappyBird::OnUpdate()
{
    while (!player->IsDead() && !isQuitting) //TODO change true
    {
        const char _input = Utils::CinNoBlock();
        if (_input == SPACE) player->Jump();
        else if (_input == ESCAPE)
        {
            isQuitting = true;
            continue;
        }
        Draw(); 
        if (player->IsCollide(pipeOne))
        {
            player->SetDead(true);
            continue;
        }

        Utils::Sleep(sleepTime); 
        Clear();
        player->Update();

        if (IsOutOfScreen())
        {
            player->SetDead(true);
            continue;
        }

        UpdatePipe(); 
        UpdateScore();
    }
}

void FlappyBird::OnEnd()
{
    Utils::SetCursor(true, 20);
}

void FlappyBird::DisplayMenu()
{
    DisplayConstrols();
}

std::string FlappyBird::GameName() const
{
    return "Flappy Bird";
}

std::string FlappyBird::GameDescription() const
{
    return "Gna";
}
#pragma endregion override