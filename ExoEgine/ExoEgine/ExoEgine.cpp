#include <iostream>
#include "Engine/Utils/DebugMacro.h"
#include "Test/PrimaryType/List/ListTest.h"


int main()
{
	Test::ListTest test = Test::ListTest();
	test.Test(); 
	Engine::Reflection::ParameterInfo* p = new Engine::Reflection::ParameterInfo("age", 0);
	LOG(p)
	delete p;
	return 0;
}