#include <iostream>
#include "Game.h"
#include "Utils.h"
#include <Windows.h>


//Sleep(1000); => window.h (timer) 
int main()
{
    bool t = true;
    
    
        Game game;
        game.DrawBorder();
        while (t)
        {
            game.DrawBird();
            Sleep(200);
            
        }
}

