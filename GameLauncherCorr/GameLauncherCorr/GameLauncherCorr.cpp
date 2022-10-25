#include <iostream>
#include "Launcher.h"
#include "LauncherItem.h"
#include <Windows.h>
#include "MorpionGame.h"


int main()
{

    SetConsoleTitle(L"Launcher");
    Launcher _launcher = Launcher({
        new LauncherItem(new MorpionGame())
        });
    _launcher.Open(); 
}
