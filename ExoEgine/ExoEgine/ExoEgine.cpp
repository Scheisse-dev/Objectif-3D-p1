#include <iostream>

#include "Engine/Window/Engine/EngineWindow.h"
#include "Engine/Manager/GameObject/GameObjectManager.h"
#include "Engine/GameObject/GameObject.h"
#include "Test/Reflection/Json/JsonTest.h"


int main()
{
	Test::JsonTest test = Test::JsonTest();
	test.JTest();
}