#pragma once
#include "IDrawable.h"

class FlappyScore : public IDrawable 
{
private :
	int score = 0; 

public: 
	FlappyScore() = default; 
	~FlappyScore() override = default; 

public: 
	virtual void Draw() override;
	virtual void Erase() override; 
	virtual void Update() override; 

#pragma region operator
	operator int() const; 
	FlappyScore& operator=(const int _value);
	FlappyScore& operator+=(const int _value); 

#pragma endregion operator
};

