#pragma once
#include "Object.h"


class IGame : public Object
{
	CLASS_INFO(Interface)
	DECLARE_CLASS_INFO(Object)

public: 
	virtual void Test()
	{

	}
};

