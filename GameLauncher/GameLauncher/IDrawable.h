#pragma once
#include "Object.h"

class IDrawable : public Object
{
public:
	~IDrawable() override = default;

public:
	virtual void Draw() = 0;
	virtual void Erase() = 0;
	virtual void Update() = 0;
};

