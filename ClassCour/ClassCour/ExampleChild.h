#pragma once
#include "Example.h"

class ExampleChild : public Example
{
	Example* example = nullptr; 
	ExampleChild(); 
};

