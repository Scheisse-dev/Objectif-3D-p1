#include <iostream>
#include <Windows.h>
#include <string>
#include "Window\Window.h"
#include "Window\WindowItem\WindowItem.h"

int main()
{
	Window window = Window(std::string("Test"), 900, 800); 
	window.Open(); 


}

