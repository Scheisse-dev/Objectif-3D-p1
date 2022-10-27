#pragma once
#include "IDrawable.h"



class FlappyMap : public IDrawable
{
public: 
	FlappyMap() = default;
	~FlappyMap() override = default; 
public:

	virtual void Draw() override;
	virtual void Erase() override; 
	virtual void Update() override;
};

