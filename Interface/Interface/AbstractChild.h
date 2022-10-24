#pragma once
#include "AbstractClass.h"

class AbstractChild : public AbstractClass
{
	// Inherited via AbstractClass
	virtual void Test() override;
};

