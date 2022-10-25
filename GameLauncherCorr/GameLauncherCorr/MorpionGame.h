#pragma once
#include "IGame.h"

class MorpionBoard;
class MorpionAI;

class MorpionGame : public IGame
{
#pragma region f/p
private: 
	MorpionBoard* board = nullptr; 
	AI* ai = nullptr;
#pragma endregion f/p
#pragma region constructor
public: 
	MorpionGame();
	~MorpionGame() = default; 
#pragma endregion constructor

#pragma region methods
	virtual void OnStart() override;
	virtual void OnUptdate() override;
	void PlayerTurn(const bool& _isPlayerTwo, int& _moves);
	virtual void OnEnd() override;
	virtual void DisplayMenu() override;
	virtual std::string GameName() const override;
	virtual std::string GameDescription() const override;
#pragma endregion methods
};

