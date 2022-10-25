#include "MorpionGame.h"
#include "MorpionBoard.h"
#include "Utils.h"
#include "AI.h"
#include <format>

#pragma region constructor
MorpionGame::MorpionGame()
{
    board = new MorpionGame(); 
}
#pragma endregion constructor
#pragma region methods
void MorpionGame::OnStart()
{
    winner = 0;
}

void MorpionGame::OnUptdate()
{
    int _moves = 0;
    while (winner == 0 && _moves < 9)
    {
        Utils::ClearConsole();
        board->ShowBoard();
        const bool _isPlayerTwo = currentPlayer % 2 == 0; 
        if (_isPlayerTwo && ai != nullptr)
        {
            int _currentMove = ai->BestMove(*board);
            board->At(_currentMove) = 1; 
        }
        else
        {
            PlayerTurn(_isPlayerTwo, _moves);

        }
        currentPlayer++; 
        winner = board->Win(); 

    }
}

void MorpionGame::PlayerTurn(const bool& _isPlayerTwo, int& _moves)
{
    Utils::Log(std::format("Player {}: turn : ", _isPlayerTwo ? 2 : 1));
    int _currentMove = Utils::UserChoice<int>();
    if (_currentMove <= 0 || _currentMove > 9)
        throw std::exception("[Morpion Game] => move out of range !");
    if (board->At(_currentMove - 1) == 0)
    {
        board->At(_currentMove - 1) = _isPlayerTwo ? 1 : -1;
        _moves++;
    }
}

void MorpionGame::OnEnd()
{
    Utils::ClearConsole(); 
    board->ShowBoard(); 
    board->Reset(); 
    if (winner == 0)
        Utils::Log("Equality"); 
    else
    {
        const std::string& _winnerName = winner == 1 ? ai != nullptr ? "AI" : "Player 2" : "Player 1"; 
        Utils::Log(std::format("WInner is {}", _winnerName)); 
    }
    Utils::Pause(); 
}

void MorpionGame::DisplayMenu()
{
    Utils::ClearConsole(); 
    Utils::LogTitle(GameName()); 
    const std::string _msg = "1- Player vs Player\n2- Player vs AI\n"; 
    char _choice = Utils::UserChoice<char>("");
    if (_choice == '2')
        ai = new AI();
    else
    {
        delete ai;
        ai = nullptr; 
    }
    _choice = Utils::UserChoice<char>("Do you want to start first ? (y/n): ", '-1', 'y', 'n'); 
    currentPlayer = _choice == 'y' ? 1 : 2;
}

std::string MorpionGame::GameName() const
{
    return "Morpion";
}

std::string MorpionGame::GameDescription() const
{
    return "Morpion Game, you can play with another player or with AI";
}
#pragma endregion methods