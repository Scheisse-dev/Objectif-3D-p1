#include <iostream>
#include <string>
#include "App.h"
#include "Button.h"
#include "Rect.h"
#include "EventSystem.h"

int main()
{
    Button* butt = new Button("My Big Butt", new Rect(11,1,10,15));
    EventSystem::Instance()->Register(butt);
    App app;
    app.Open();

    
}
